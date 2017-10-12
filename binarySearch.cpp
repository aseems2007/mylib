#include "myheader.h"

void ge(int *arr, int l, int u, int t, int &ans)
{
  int mid;
  mid = l+(u-l)/2;
  while(l<u)
  {
    if(arr[mid]>=t)
      u = mid;
    else
      l = mid+1;
    mid = l+(u-l)/2;
  }
  if(arr[mid]>=t)
    ans = mid;
  else
    ans = -1;
}
void lt(int *arr, int l, int u, int t, int &ans)
{
  int mid;
  mid = l+(u-l+1)/2;
  while(l<u)
  {
    if(arr[mid]>=t)
      u = mid-1;
    else
      l = mid;
    mid = l+(u-l+1)/2;
  }
  if(arr[mid]<t)
    ans = mid;
  else
    ans = -1;
}
int main()
{
  int n, *arr, i, t, tc;
  cin >> n;
  arr = new int[n];
  for(i=0; i<n; i++)
    cin >> arr[i];
  sort(arr, arr+n);
  cin >> tc;
  while(tc--)
  {
    cin >> t;
    ge(arr, 0, n-1, t, i);
    if(i!=-1)
      cout << "Greater than or equal to t, (index, value): (" << i <<", " << arr[i] << ")\n";
    else
      cout << "Greater than or equal to t, does not exist\n";
    lt(arr, 0, n-1, t, i);
    if(i!=-1)
      cout << "Less than t, (index, value): (" << i <<", " << arr[i] << ")\n";
    else
      cout << "Less than t does not exist\n";
  }
  return 0;
}
