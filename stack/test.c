#include"stack.h"

int main()
{
  Stack s;
  StackInit(&s);
  Stackpush(&s,1);
  printf("%d ",Top(&s));
  Stackpush(&s,2);
  printf("%d ",Top(&s));
  Stackpush(&s,3);
  printf("%d ",Top(&s));
  Stackpush(&s,4);
  printf("%d ",Top(&s));
  Stackpush(&s,5);
  printf("%d ",Top(&s));
  Stackpush(&s,6);
  printf("%d ",Top(&s));
  Stackpush(&s,7);
  printf("%d ",Top(&s));
  Stackpush(&s,8);
  printf("%d ",Top(&s));
  printf("\n");
  
  Pop(&s);
  printf("%d ",Top(&s));
  Pop(&s);
  printf("%d ",Top(&s));
  Pop(&s);
  printf("%d ",Top(&s));
  Pop(&s);
  printf("%d ",Top(&s));
  Pop(&s);
  printf("%d ",Top(&s));
  printf("\n");
  
  printf("%d\n",_Empty(&s));
  printf("%d\n",StackSize(&s));
  
  StackDestory(&s);
  printf("%d\n",_Empty(&s));
  return 0;
}
