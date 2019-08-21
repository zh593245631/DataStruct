#include<iostream>
#include<vector>

using namespace std;

void bubblesort(vector<int>& v)
{
   size_t n = v.size();
   for(size_t i = 0; i < n - 1; ++i)
   {
     bool flat = true;
     for(size_t j = 1; j < n - i; ++j)
     {
       if(v[j - 1] > v[j]){
         swap(v[j - 1], v[j]);
         flat = false;
       }
     }
     if(flat)break;
   }
}
int main()
{
  vector<int> v = {2,5,1,3,8,9,7,6};
  bubblesort(v);
  for(const auto& e:v)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
