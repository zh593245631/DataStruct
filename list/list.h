#ifndef __LIST_H__
#define __LIST_H__
#include<assert.h>
#include<malloc.h>

typedef int LDataType;

//节点
typedef struct ListNode
{
  LDataType val;
  struct ListNode* prev;
  struct ListNode* next;
}ListNode;

//链表
typedef struct List
{
  ListNode* head;
}List;

//申请新节点
ListNode* New()
{
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  assert(node);
  return node;
}
//链表初始化
void initL(List* l)
{
  l->head = New();
  l->head->val = 0;
  l->head->prev = l->head;
  l->head->next = l->head;
}
//打印
void print(List* l)
{
  assert(l);
  ListNode* cur = l->head->next;
  for(;cur!=l->head; cur=cur->next)
  {
    printf("%d ",cur->val);
  }
  printf("\n");
}
//增
//头插
void Push_Front(List* l,LDataType val)
{
  assert(l);
  ListNode* node = New();
  //先把节点插上去
  node->val = val;
  node->prev = l->head;
  node->next = l->head->next;
  
  //
  l->head->next->prev = node;
  l->head->next = node;

}
void Push_Back(List* l, LDataType val)
{
  assert(l);
  ListNode* node = New();
  node->val = val;
  node->prev = l->head->prev;
  node->next = l->head;
  
  //
  l->head->prev->next = node;
  l->head->prev = node;
}
//删
//尾删
void Pop_Front(List* l)
{
  assert(l);
  ListNode* tmp = l->head->prev;
  l->head->prev = tmp->prev;
  tmp->prev->next = l->head;
  free(tmp);
  tmp = NULL;
}

//头删
void Pop_back(List* l)
{
  assert(l);
  ListNode* tmp = l->head->next;
  l->head->next = tmp->next;
  tmp->next->prev = l->head;
  free(tmp);
  tmp = NULL;
}
//查
size_t Find(List* l, LDataType val)
{
  assert(l);
  ListNode* cur = l->head->next;
  size_t count = 0;
  for(;cur!=l->head; cur=cur->next)
  {
    if(cur->val == val)count++;
  }
  return count;
  
}
//改
void Update(List* l, LDataType src,LDataType dst)
{
  assert(l);
  ListNode* cur = l->head->next;
  for(;cur!=l->head; cur=cur->next)
  {
    if(cur->val == src)cur->val = dst;
  }
}















#endif//__LIST_H__
