#include<bits/stdc++.h>
using namespace std;

// bool solve(string &str,string &pattern,int i ,int j){
//     if(i<0 && j<0)return true;
//     if(i>=0 && j<0)return false;
//     if(i<0 && j>=0){
//         for(int k = 0;k<=j;k++){
//             if(pattern[k]!='*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     if(str[i]==pattern[j] || pattern[j]=='?')
//         return solve(str,pattern,i-1,j-1);
//     else if(pattern[j]=='*')
//         return (solve(str,pattern,i-1,j) || solve(str,pattern,i,j-1));
//     else
//         return false;
// }
// bool isMatch(string s,string p){
//     int n = s.length();
//     int m = p.length();
//     return solve(s, p,n-1,m-1);
// }
// bool solveMem(string &str, string &pattern, int i, int j, vector<vector<int>>&dp)
// {
//     if(i<0 && j<0)return true;
//     if(i>=0 && j<0)return false;
//     if(i<0 && j>=0){
//         for(int k = 0;k<=j;k++){
//             if(pattern[k]!='*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     if (dp[i][j]!=-1)
//         return dp[i][j];

//     if (str[i] == pattern[j] || pattern[j] == '?') return dp[i][j] = solveMem(str, pattern, i - 1, j - 1, dp);
//     else if (pattern[j] == '*')
//         return dp[i][j] = (solveMem(str, pattern, i - 1, j, dp) || solveMem(str, pattern, i, j - 1, dp));
//     else
//         return false;
// }
// bool isMatch(string s,string p){
//     int n = s.length();
//     int m = p.length();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return solveMem(s, p,n-1,m-1,dp);
// }
//1 base indexing
// bool solveTab(string &str, string &pattern, int i, int j, vector<vector<int>>&dp)
// {
//     if(i==0 && j==0)return true;
//     if(i>0 && j<0)return false;
//     if(i<0 && j>0){
//         for(int k = 1;k<=j;k++){
//             if(pattern[k-1]!='*'){
//                 return false;
//             }
//         }
//         return true;
//     }
//     if (dp[i][j]!=-1)
//         return dp[i][j];

//     if (str[i-1] == pattern[j-1] || pattern[j-1] == '?') return dp[i][j] = solveTab(str, pattern, i - 1, j - 1, dp);
//     else if (pattern[j-1] == '*')
//         return dp[i][j] = (solveTab(str, pattern, i - 1, j, dp) || solveTab(str, pattern, i, j - 1, dp));
//     else
//         return false;
// }
// bool isMatch(string s,string p){
//     int n = s.length();
//     int m = p.length();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//     return solveTab(s, p,n,m,dp);
// }
// bool solveTab(string &str, string &pattern)
// {
//     int n = str.length();
//     int m = pattern.length();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
//     dp[0][0] = true;
//     for(int j=1;j<=m;j++){
//         bool flag = true;
//         for (int k = 1; k <= j; k++){
//             if (pattern[k - 1] != '*'){
//                 flag = false;
//                 break;
//             }
//         }
//         dp[0][j] = flag;
//     }
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=m;j++){
//             if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
//                 dp[i][j] = dp[i - 1][j - 1];
//             else if (pattern[j - 1] == '*')
//                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//             else
//                 dp[i][j] = false;
//         }
//     }
//     return dp[n][m];
// }
// bool isMatch(string s,string p){
//     return solveTab(s, p);
// }
bool solveSo(string &str, string &pattern)
{
    int n = str.length();
    int m = pattern.length();
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);
    prev[0] = true;
    for(int j=1;j<=m;j++){
        bool flag = true;
        for (int k = 1; k <= j; k++){
            if (pattern[k - 1] != '*'){
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                curr[j] = prev[j - 1];
            else if (pattern[j - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}
bool isMatch(string s,string p){
    return solveSo(s, p);
}