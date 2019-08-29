#include<cstdio>
#include<ctime>
#include<iostream>
#include<vector>
#include<functional>

using namespace std;
typedef function<void (vector<int>& v)> Handler;

//1.冒泡排序
void BubbleSort(vector<int>& v)
{
  int n = v.size();
  for(int i = 0; i < n - 1; ++i)
  {
    bool ret = true;
    for(int j = 1; j < n - i; ++j)
    {
      if(v[j - 1] > v[j]){
        swap(v[j - 1], v[j]);
        ret = false;
      }
    }
    if(ret)break;
  }
}
//2. 插入排序
void insertionsort(vector<int>& v)
{
  size_t n = v.size();
  size_t j = 0;
  for(size_t i = 1; i < n; ++i)
  {
    int tmp = v[i];
    for(j = i; j > 0 && tmp < v[j - 1]; --j)
    {
      v[j] = v[j - 1];
    }
    v[j] = tmp;
  }
}
//3. 选择排序
void selectionsort(vector<int>& v)
{
   size_t n = v.size();
   for(size_t i = 0; i < n; ++i)
   {
     size_t min = i;
     for(size_t j = i + 1; j < n; ++j)
     {
       if(v[j] < v[min]){
         min = j;
       }
     }
     swap(v[min], v[i]);
   }
}
//4. 希尔排序
void shellsort(vector<int>& v)
{
  size_t n = v.size();
  size_t h = 1;
  while(h < n/3)
    h = h*3 + 1;
  while(h >= 1)
  {
    for(size_t i = h; i < n; ++i)
    {
      for(size_t j = i; j >= h&& v[j] < v[j - h]; j -= h)
      {
        swap(v[j], v[j - h]);
      }
    }
    h /= 3;
  }
}
//5. 堆排序
void sink(vector<int>& v, int k, int n);
void heapsort(vector<int>& v)
{
  int n = v.size();
  for(int k = n/2; k >= 1; --k)
  {
    sink(v,k,n);
  }

  while(n > 0)
  {
    swap(v[0],v[n - 1]);
    sink(v,1,--n);
  }
}
void sink(vector<int>& v, int k, int n)
{
  while( 2*k <= n )
  {
     int j = 2*k;
     if(j < n && v[j] > v[j - 1]){
       ++j;
     }
     if(v[k - 1] >= v[j - 1]){
       break;
     }
     swap(v[k - 1], v[j - 1]);
     k = j;
  }
}
//6. 快速排序
void _quicksort(vector<int>& v,int left, int right);
void quicksort(vector<int>& v)
{
  _quicksort(v,0,v.size() - 1);
}
void _quicksort(vector<int>& v,int left, int right)
{
  if(left < right)
  {
    int i = left,j = right,x = v[left];
    while( i < j )
    {
      while(i < j && v[j] >= x)
        --j;
      if(i < j)
        v[i++] = v[j];
      while(i < j && v[i] <= x)
        ++i;
      if(i < j)
        v[j--] = v[i];
    }
    v[i] = x;
    _quicksort(v,left,i - 1);
    _quicksort(v,i + 1,right);
  }

}
void test(Handler handler, vector<int>& v)
{
  clock_t beg = clock();
  handler(v);
  clock_t end = clock();
  printf("use time:%0.16fs\n", (double)(end - beg)/CLOCKS_PER_SEC);

}
void print(const vector<int>& v)
{
  for(const auto& e: v)
    cout<<e<<" ";
  cout<<endl;
}
int main()
{
  srand((unsigned)time(NULL));

  vector<int> v(10,0);
  for(size_t i = 0; i < v.size(); ++i)
  {
    v[i] = rand()%100 + 1;
  }
  //print(v);
  vector<int> v1(v);
  printf("BubbleSort : \n");
  test(BubbleSort,v1);
  //print(v1);

  v1 = v;
  printf("insertionsort : \n");
  test(insertionsort,v1);
  //print(v1);

  v1 = v;
  printf("selectionsort : \n");
  test(selectionsort,v1);
  //print(v1);
  
  v1 = v;
  printf("shellsort : \n");
  test(shellsort,v1);
  //print(v1);
  
  v1 = v;
  printf("heapsort : \n");
  test(heapsort,v1);
  //print(v1);

  v1 = v;
  printf("quicksort : \n");
  test(quicksort,v1);
  print(v1);

  return 0;
}
