#ifndef __VECTOR_H__
#define __VECTOR_H__
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
typedef int VDataType;

//顺序表的动态存储
typedef struct Vector
{
  VDataType* arr;
  size_t size;  //有效元素个数
  size_t capicity;  //容量
}Vector;
//打印
void Print(Vector* v)
{
  assert(v);
  printf("size: %zu\n", v->size);
  printf("capicity: %zu\n", v->capicity);

  size_t i = 0;
  for(; i<(v->size); ++i)
  {
    printf("%d \n",v->arr[i]);
  }
}

//初始化
void init(Vector* v, size_t _capicity)
{
  assert(v);
  v->arr = (VDataType*)malloc(sizeof(VDataType)*_capicity);
  v->size = 0;
  v->capicity = _capicity;
}
//扩容
void Capicity(Vector* v)
{
  v->capicity = v->capicity*2;
  VDataType* tmp = (VDataType*)malloc(sizeof(VDataType)*v->capicity);
  size_t i = 0;
  for(;i<(v->size); ++i)
  {
    tmp[i] = v->arr[i];
  }
  free(v->arr);
  v->arr = tmp;
}
//清空
void Clean(Vector* v)
{
  assert(v);
  printf("~Clean\n");
  if(v->arr){
    free(v->arr);
    v->size = 0;
    v->capicity = 0;
  }
}
//增
//尾插
void Push_back(Vector* v, VDataType val)
{
  assert(v);
  if(v->size == v->capicity){
    Capicity(v);
  }
  v->arr[v->size] = val;
  v->size++; 
}
//插入
void Insert(Vector* v, size_t pos, VDataType val)
{
  assert(v);
  if(v->size == v->capicity){
    Capicity(v);
  }
  size_t i = v->size;
  for(;i>pos; --i)
  {
    v->arr[i] = v->arr[i-1]; 
  }
  v->arr[pos] = val;
  v->size++;
}
//删
//尾删
void Pop_back(Vector* v)
{
  assert(v);
  v->size--;
}
//删除
void Delete(Vector* v, size_t pos)
{
  assert(v);
  size_t i = pos;
  v->size--;
  for(; i<(v->size); ++i)
  {
    v->arr[i] = v->arr[i+1];
  }
}
//查
int Find(Vector* v, VDataType val)
{
  assert(v);
  int ret = -1;
  size_t i = 0;
  for(;i<(v->size);++i)
  {
    if(v->arr[i] == val){
        ret = i;
    }
  }
  return ret;
}
//改
void Update(Vector* v, size_t pos, VDataType val)
{
  assert(v);
  v->arr[pos] = val;
}

#endif//__VECTOR_H__
