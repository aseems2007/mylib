#include "myheader.h"

int euclid(int a, int b)
{
  if(b==0)
    return a;
  return euclid(b, a%b);
}
int main()
{
  int i, j;
  cin >> i >> j;
  cout << euclid(i, j) << endl;
  return 0;
}
