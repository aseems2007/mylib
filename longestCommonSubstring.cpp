#include "myheader.h"
#define MAX_STR_LENGTH 1000

int dp[MAX_STR_LENGTH][MAX_STR_LENGTH];

string longestCommonSubstring(string &s1, string &s2)
{
  int n1, n2, i, j, mi, mtn;
  n1 = s1.size();
  n2 = s2.size();
  i = 0;
  j = 0;
  mtn = 0;
  mi = 0;
  for(i=0; i<n1; i++)
  {
    for(j=0; j<n2; j++)
    {
      if(s1[i]==s2[j])
      {
        if(i==0 || j==0)
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i-1][j-1]+1;
        if(dp[i][j]>mtn)
        {
          mtn = dp[i][j];
          mi = i;
        }
      }
      else
        dp[i][j]=0;
    }
  }
  if(mtn==0)
    return "";
  return s1.substr(mi-mtn+1, mtn);
}
int main()
{
  string s1, s2, sc;
  while(true)
  {
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(int)*MAX_STR_LENGTH*MAX_STR_LENGTH);
    sc = longestCommonSubstring(s1, s2);
    cout << sc << endl;
  }
  return 0;
}
