#ifndef __QUEUE_H__
#define __QUEUE_H__
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int QDataType;

typedef struct Node 
{
  QDataType val;
  struct Node* next;
}Node;

typedef struct Queue 
{
  Node* head;
  Node* back;
}Queue;

//申请节点
Node* New()
{
 Node* node = (Node*)malloc(sizeof(Node));
 assert(node);
 node->val = 0;
 node->next = NULL;

 return node;
}
//fifo
//初始化
void Init(Queue* node)
{
  node->head = New();
  node->back = node->head;
}
//插入
void _push(Queue* node, QDataType val)
{
  assert(node);

  Node* newNode = New();
  newNode->val = val;

  node->back->next = newNode;
  node->back = newNode;
}

//出
void _pop(Queue* node)
{
  assert(node);
  assert(node->head);

  Node* tmp = node->head->next; 
  if(!tmp){
    perror("is empty");
    return;
  }
  node->head->next = tmp->next;
  free(tmp);
}
//获取头元素
QDataType _front(Queue* node)
{
  assert(node);
  assert(node->head);
  assert(node->head->next);

  return node->head->next->val;
}
//判断是否为空

int Empty(Queue* q)
{
  assert(q);

  return q->head->next == NULL ;
}


















#endif //
