#include"vector.h"

int main()
{
  Vector v;
  init(&v,3);
  Push_back(&v,1);
  Push_back(&v,2);
  Push_back(&v,3);
  Push_back(&v,4);
  Push_back(&v,5);
  Push_back(&v,6);
  Push_back(&v,7);
  Pop_back(&v);
  Pop_back(&v);
  Pop_back(&v);
  Pop_back(&v);

  printf("find: %d\n",Find(&v,2));
  printf("find: %d\n",Find(&v,6));
  Update(&v,Find(&v,2),5);
  Insert(&v,Find(&v,5),6);
  Delete(&v,Find(&v,1));
  Print(&v);
  Clean(&v);
  Print(&v);
  return 0;
}
