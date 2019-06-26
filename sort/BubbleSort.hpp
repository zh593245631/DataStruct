#pragma once
#include<iostream>
#include<vector>

using namespace std;
void BubbleSort(vector<int>& v)
{
  size_t n = v.size();
  for(size_t i = 0; i < n - 1; ++i)
  {
    bool flag = true;
    for(size_t j = 1; j < n - i; ++j)
    {
      if(v[j - 1] > v[j]){
        swap(v[j - 1],v[j]);
        flag = false;
      }
    }
    if(flag)break;
  }
}

