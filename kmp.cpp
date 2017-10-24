#include "myheader.h"
vector<int> kmp_table;
void make_kmp_table(string &p)
{
  int k, i, j, t = 0;
  k = p.length();
  kmp_table.resize(k);
  kmp_table[0] = 0;
  i = 1;
  while(i<k)
  {
    if(p[i]==p[t])
    {
      t++;
      kmp_table[i] = t;
      i++;
    }
    else
    {
      if(t!=0)
      {
        t = kmp_table[t-1];
      }
      else
      {
        kmp_table[i] = 0;
        i++;
      }
    }
  }
}
int main()
{
  string str, patt;
  int t, i, j, k, n;
  cin >> t;
  while(t--)
  {
    cin >> str >> patt;
    n = str.length();
    k = patt.length();
    make_kmp_table(patt);
    j=0;
    i=0;
    while(i<n)
    {
      if(j==k)
      {
        cout << i-k << " ";
        j=0;
      }
      if(str[i]==patt[j])
      {
        j++;
        i++;
      }
      else
      {
        if(j!=0)
          j = kmp_table[j-1];
        else
          i++;
      }
    }
      if(j==k)
      {
        cout << i-k << " ";
        j=0;
      }
    cout << endl;
    kmp_table.clear();
  }
  return 0;
}
