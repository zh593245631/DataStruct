#include<stdio.h>
#include"queue.h"

int main()
{
  Queue q;
  Init(&q);


  printf("%d\n",Empty(&q));
  _push(&q,1);
  _push(&q,2);
  _push(&q,3);
  _push(&q,4);
  _push(&q,5);
  printf("%d\n",_front(&q));

  _pop(&q);
  printf("%d\n",_front(&q));
  _pop(&q);
  printf("%d\n",_front(&q));
  _pop(&q);
  printf("%d\n",_front(&q));
  _pop(&q);
  printf("%d\n",_front(&q));
  printf("%d\n",Empty(&q));
  _pop(&q);
  
  printf("%d\n",Empty(&q));
  return 0;
}
