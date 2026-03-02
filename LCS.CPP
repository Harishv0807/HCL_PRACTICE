#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    
    cout << "Enter first string: ";
    cin >> s1;
    
    cout << "Enter second string: ";
    cin >> s2;
    
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    int lcs = dp[n][m];
    
    int deletions = n - lcs;
    int insertions = m - lcs;
    
    cout << "\nLength of LCS: " << lcs << endl;
    cout << "Minimum Deletions: " << deletions << endl;
    cout << "Minimum Insertions: " << insertions << endl;
    
    return 0;
}