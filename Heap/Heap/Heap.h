#pragma once
#include<string.h>
#include<stdio.h>
typedef int HDataType;

typedef struct Heap
{
	HDataType _a[100];
	int _size;
}Heap;
void HeapDestory(Heap* hp)
{
	hp->_size = 0;
}
//向下调整
void AdjustDown(Heap* hp, int root)
{
	while (1)
	{
		//叶子节点不需要调整
		int left = 2 * root + 1;
		if (left >= hp->_size) {
			return;
		}

		//判断是否有右孩子
		int right = 2 * root + 2;
		int max = left;
		if (right<hp->_size && (hp->_a[right])>(hp->_a[left])) {
			max = right;
		}

		if (hp->_a[max] <= hp->_a[root]) {
			return;
		}
		//交换
		int tmp = hp->_a[max];
		hp->_a[max] = hp->_a[root];
		hp->_a[root] = tmp;

		//继续向下调整
		root = max;
	}
}
//向上调整
void AdjustUp(Heap* hp, int root)
{
	while (root != 0)
	{
		int parent = (root - 1) / 2;
		if (hp->_a[parent] >= hp->_a[root])
			return;
		int tmp = hp->_a[parent];
		hp->_a[parent] = hp->_a[root];
		hp->_a[root] = tmp;
		
		root = parent;
	}
}
//建堆
void CreateHeap(Heap* hp)
{
	for (int i = (hp->_size - 2) / 2; i >= 0; --i) {
		AdjustDown(hp, i);
	}
}
//堆的初始化
void HeapInit(Heap* hp, int a[], int n)
{
	memcpy(hp->_a, a, n*sizeof(int));
	hp->_size = n;
	CreateHeap(hp);
}
//删头
void HeapPop(Heap* hp)
{
	int tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	--(hp->_size);
	AdjustDown(hp, 0);
}
//插入
void HeapPush(Heap* hp, int val)
{
	hp->_a[hp->_size] = val;
	++(hp->_size);
	AdjustUp(hp, hp->_size - 1);
}
//取
int HeapTop(Heap* hp)
{
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
void HeapSort(Heap* hp)
{
	CreateHeap(hp);
	int ret = hp->_size;
	for (int i = 0; i < ret - 1; ++i)
	{
		HeapPop(hp);
	}
	hp->_size = ret;
}

