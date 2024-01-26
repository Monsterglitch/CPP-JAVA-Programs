#include <bits/stdc++.h>
using namespace std;

int lcs (int n, int m, string s1, string s2)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            if (s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else {
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string s1 = "ABC", s2 = "AC";
    int n = 3, m = 2;
    cout<<lcs(n, m, s1, s2);
    return 0;
}
