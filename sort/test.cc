#include<iostream>
#include"BubbleSort.hpp"
#include"SelectionSort.hpp"
using namespace std;

void print(vector<int>& v)
{
  for(const auto& e: v)
    cout<<e<<" ";
  cout<<endl;
}
int main()
{
  vector<int> v{1,5,2,5,6,2,6,88,12,3,56,2,1};
  print(v);
  //BubbleSort(v);
  SelectionSort(v);
  print(v);
  return 0;
}
