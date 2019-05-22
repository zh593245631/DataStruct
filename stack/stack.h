#ifndef __STACK_H__
#define __STACK_H__
#include<stdio.h>
#include<malloc.h>
#include"vector/vector.h"

typedef int SKDataType;

typedef struct Stack
{
  Vector* v;
}Stack;
//申请空间
//初始化
void StackInit(Stack* ps)
{
  assert(ps);
  init(ps->v,10);
}
//销毁
void StackDestory(Stack* ps)
{    
  assert(ps);
  Clean(ps->v);
}
//插入
void Stackpush(Stack* ps, SKDataType a)
{
  assert(ps);
  Push_back(ps->v,a);
}
//查看栈顶
SKDataType Top(Stack* ps)
{
  assert(ps);
  assert(ps->v);
  return ps->v->arr[ps->v->size-1];
}
//出栈
void Pop(Stack* ps)
{
  assert(ps);
  Pop_back(ps->v);
}
//判断是否为空
int _Empty(Stack* ps)
{
  assert(ps);
  if(ps->v||ps->v->size)
      return 0; 
  else
      return -1;
}
//size
int StackSize(Stack* ps)
{
  assert(ps);
  assert(ps->v);
  return ps->v->size;
}





#endif //__STACK_H__
