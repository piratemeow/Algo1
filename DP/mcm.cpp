#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int mcm_(int i, int j, int arr[])
{
    if (i==j)
        return dp[i][j] = 0;

    if (dp[i][j]!=-1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i;k<j;k++)
    {
        int steps = arr[i-1]  * arr[k] * arr[j] + mcm_(i,k,arr) + mcm_(k+1,j,arr);
        mn = min(mn,steps);
    }

    return dp[i][j]=mn;   

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof dp);
    cout<<mcm_(1,n-1,arr)<<endl;
}
