#include "myheader.h"

int longestCommonSubsequence(string s1, string s2)
{
  vector<vector<int> > dp_table;
  int n, m;
  n = s1.length();
  m = s2.length();
  dp_table.resize(n+1, vector<int>(m+1, 0));
  int i, j, t1;
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=m; j++)
    {
      dp_table[i][j] = max(dp_table[i-1][j], dp_table[i][j-1]);
      if(s1[i-1]==s2[j-1])
      {
        t1 = 1+dp_table[i-1][j-1];
        dp_table[i][j] = max(dp_table[i][j], t1);
      }
    }
  }
  t1 = dp_table[n][m];
  for(i=0; i<=n; i++) dp_table[i].clear();
  dp_table.clear();
  return t1;
}

int main()
{
  int t;
  string s1, s2;
  cin >> t;
  while(t--)
  {
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2) << endl;
    s1.clear();
    s2.clear();
  }
  return 0;
}
