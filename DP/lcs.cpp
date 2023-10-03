#include<bits/stdc++.h>
using namespace std;


// Longest increasing subsequence problem
// Complexity O(n*m)
// Space complexity O(n*m)
int dp[1001][1001];

int top_down(int i, int j, string &a, string &b)
{
    if (i<0 || j<0)
    {
        return 0;
    }

    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(a[i]==b[j])
    {
        return dp[i][j] = 1 + top_down(i-1,j-1,a,b);
    }

    else
    {
        return dp[i][j] = max(top_down(i-1,j,a,b),top_down(i,j-1,a,b));
    }
}


int bottom_up(string &a, string &b)
{
    memset(dp,0,sizeof dp); // Base case initialization
    int n = a.size();
    int m = b.size();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i-1]==b[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}


string lcs(string &a, string &b) // To print the LCS
{
    int answer = bottom_up(a,b); // Creating the dp table

    int n = a.size();
    int m = b.size();

    int i = n;
    int j = m;

    string lcs_string = "";

    while (i>0 && j>0)
    {
        if (a[i-1]==b[j-1])
        {
            lcs_string+=a[i-1];
            i--;
            j--;
        }
        else
        {
            if (dp[i-1][j]>=dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    reverse(lcs_string.begin(),lcs_string.end());
    return lcs_string;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    int n = a.size() - 1;
    int m = b.size() - 1;
    cout<<"The result from the top down appraoch\n";

    cout<<top_down(n,m,a,b)<<endl;

    cout<<"The result from the bottom up appraoch\n";

    cout<<bottom_up(a,b)<<endl;

    cout<<"The LCS is\n";

    cout<<lcs(a,b)<<endl;

}