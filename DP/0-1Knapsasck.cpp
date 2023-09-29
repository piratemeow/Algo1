#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int top_down(vector<pair<int,int>> &v,int i, int wt)
{
    if(i>=v.size())
        return 0;
    if (wt==0)
    {
        return 0;
    }

    if (dp[i][wt]!=-1)
    {
        return dp[i][wt];
    }

    int a=0,b=0;
    if (wt-v[i].second>=0)
    {
        a = v[i].first + top_down(v,i+1,wt-v[i].second);
    }

    b = top_down(v,i+1,wt);

    return dp[i][wt] = max(a,b);

}


int bottom_up(vector<pair<int,int>> &v, int wt)
{
    int dp[v.size()+1][wt+1];
    memset(dp,0,sizeof dp);

    for (int i = v[0].second; i<=wt;i++)
    {
        dp[0][i] = v[0].first;
    }

    for (int i=1;i<v.size();i++)
    {
        for (int w = 0;w<=wt;w++)
        {
            int notTake = dp[i-1][w];
            int take = 0;

            if (v[i].second<=w)
            {
                take = v[i].first + dp[i-1][w-v[i].second];
            }

            dp[i][w] = max (notTake,take);
        }
    }


    return dp[v.size()-1][wt];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,wt;
    cin>>n>>wt;
    vector<pair<int,int>> v;

    for (int i=0;i<n;i++)
    {
        int a,wt;
        cin>>a>>wt;
        v.push_back({a,wt});
    }
    memset(dp,-1,sizeof dp);

    cout<<top_down(v,0,wt)<<endl;
    cout<<bottom_up(v,wt);

}