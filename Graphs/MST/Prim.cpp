#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 +5;
int visi[N];
// Complexity: O(ElogE + ElogV) = O(ElogV)

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v[n+2];
    while (m--)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        v[a].push_back({b,wt});
        v[b].push_back({a,wt});
    }
    // The default order is largest first. This is the method to change it to ascending order
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;

    q.push({0,{1,-1}});

    vector<pair<int,int>> ans[n+2];
    int total_wt = 0;

    while (!q.empty())
    {
        int cur = q.top().second.first;
        int wt = q.top().first;
        int par = q.top().second.second;
        
        
        q.pop();
        if (visi[cur]==1)
        {
            continue;
        }
        visi[cur]=1;
        if (par!=-1)
        {
            ans[par].push_back({cur,wt});
            ans[cur].push_back({par,wt});
        }
           

        total_wt+=wt;
        for (auto it: v[cur])
        {
            if (visi[it.first]==1)
            {
                continue;
            }
            q.push({it.second,{it.first,cur}});
        }


    }

    for (int i=1;i<=n;i++)
    {
        for(auto it:ans[i])
        {
            cout<<i<<" "<<it.first<<" "<<it.second<<endl;
        }
    }

    cout<<total_wt<<endl;

}