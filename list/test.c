#include<stdio.h>
#include"list.h"

int main()
{
  List l;
  initL(&l);
  
  Push_Back(&l,6);
  Push_Back(&l,4);
  Push_Back(&l,4);
  Push_Back(&l,4);
  Push_Back(&l,4);
  Push_Back(&l,4);
  Push_Back(&l,4);
  Push_Front(&l,3);
  Push_Front(&l,1);
  Pop_back(&l);
  Pop_back(&l);
  Pop_Front(&l);
  
  printf("%d\n",Find(&l,4));
  
  Update(&l,4,0); 
  print(&l);
  return 0;
}
