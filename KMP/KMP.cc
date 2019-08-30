#include<iostream>
#include<string>
#include<vector>

using namespace std;

void getNext(string& p,vector<int>& next)
{
  int i = 0;
  int j = -1;
  int n = p.size();
  next[0] = -1;
  while(i < n)
  {
    if(j == -1 || p[i] == p[j])
    {
      ++i;
      ++j;
      next[i] = j;
    }
    else
    {
      j = next[j];
    }
  }
}
int KMP(string& p, string q,vector<int>& next)
{
  size_t i = 0;
  size_t j = 0;
  while(i < p.size()&&j < q.size())
  {
    if(j == -1 || p[i] == q[j])
    {
      ++i;
      ++j;
    }
    else
    {
      j = next[j];
    }
  }

  if(j == q.size())
    return i - j;
  return -1;
}
int main()
{
  string str1,str2;
  while(getline(cin,str1))
  {
    getline(cin,str2);
    vector<int> next;
    next.resize(str1.size());
    getNext(str1,next);
    cout<<KMP(str1,str2,next)<<endl;
  }
  return 0;
}
