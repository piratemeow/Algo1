// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

// Complexity O(n*m)
int bottom_up(vector<vector<int>> &grid)
{
    memset(dp,0,sizeof dp);
    int n = grid.size();
    int m = grid[0].size();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            
            if (i==1)
            {
                dp[i][j] = grid[i-1][j-1] + dp[i][j-1];
            }
            else if (j==1)
            {
                dp[i][j] = grid[i-1][j-1] + dp[i-1][j];
            }
            else
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
            
        }
        
    }

    return dp[n][m];
}

int top_down(int i, int j, int n, int m, vector<vector<int>> &grid)
{
    if (i>=n || j>=m)
        {
            return 10000;
        }
        if (i==n-1 && j==m-1)
            return dp[i][j] = grid[i][j];
        
        if (dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int a = grid[i][j] + top_down(i+1,j,n,m,grid);
        int b = grid[i][j] + top_down(i,j+1,n,m,grid);
        //cout<<i<<" "<<j<<endl;
        
        return dp[i][j] = min(a,b);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m,0));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<"Answer using bottom up approach\n";

    cout<<bottom_up(grid)<<endl;

    cout<<"Answer using top down approach\n";

    memset(dp,-1,sizeof dp);

    cout<<top_down(0,0,n,m,grid)<<endl;
        
}