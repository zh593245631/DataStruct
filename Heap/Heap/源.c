#include"Heap.h"

void print(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void test()
{
	Heap h;
	int a[] = { 4,5,8,7,9,2,4,2,6,7,5 };
	//int b[10];
	//memcpy(&b, &a, 7);
	HeapInit(&h, a, sizeof(a)/sizeof(a[0]));
	print(h._a, h._size);
	HeapPush(&h, 11);
	print(h._a, h._size);
	HeapPop(&h);
	print(h._a, h._size);
	printf("%d\n", HeapTop(&h));
	printf("%d\n", HeapSize(&h));
	printf("%d\n", HeapEmpty(&h));
	//HeapDestory(&h);
	print(h._a, h._size);
	HeapSort(&h);
	print(h._a, h._size);

}
int main()
{
	test();
	return 0;
}