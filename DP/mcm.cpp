#include<bits/stdc++.h>
using namespace std;

// Finding the minimum number of multiplications required to multiply a chain of matrices
// Complexity O(n^3)
int dp[1000][1000];
void print_parenthesis(int i, int j, vector<vector<int>> &pos, int n, char& name)
{
    if (i==j)
    {
        cout<<name++;
        return;
    }

    cout<<"(";
    print_parenthesis(i,pos[i][j],pos,n,name);
    print_parenthesis(pos[i][j]+1,j,pos,n,name);

    cout<<")";
    
}
int top_down(int i, int j, int arr[])
{
    if (i==j)
        return dp[i][j] = 0;

    if (dp[i][j]!=-1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i;k<j;k++)
    {
        int steps = arr[i-1]  * arr[k] * arr[j] + top_down(i,k,arr) + top_down(k+1,j,arr);
        mn = min(mn,steps);
    }

    return dp[i][j]=mn;   

}

int bottom_up (int arr[], int n)
{
    int dp[n+1][n+1];
    vector<vector<int>> pos(n+1,vector<int>(n+1,0));
    memset(dp,0,sizeof dp);

    for (int i=n-1;i>=1;i--)
    {
        for (int j=i+1;j<n;j++)
        {
            int mn = INT_MAX;
            for (int k = i;k<j;k++)
            {
                int steps = arr[i-1]  * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                if (steps<mn)
                {
                    mn=steps;
                    pos[i][j]=k;
                }
            }
            dp[i][j] = mn;

        }
    }

    // for (int i=0;i<pos.size();i++)
    // {
    //     for (int j=0;j<pos[i].size();j++)
    //     {
    //         cout<<pos[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    char name = 'A';
    print_parenthesis(1,n-1,pos,n,name); // to print the parentheses
    cout<<endl;
    return dp[1][n-1];
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
    cout<<top_down(1,n-1,arr)<<endl;

    cout<<bottom_up(arr,n)<<endl;
}
