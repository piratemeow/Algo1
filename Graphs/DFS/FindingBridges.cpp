#include <bits/stdc++.h>
using namespace std;


//Undirected connected Graph

const int N = 1e7 + 5;
int d[N];
int low[N];
int visi[N];
int t = 0;

void dfs(vector<int> v[], int ver, int par, vector<pair<int,int>> &ans)
{
    visi[ver] = 1;
    t = t + 1;
    d[ver] = t;
    low[ver] = t;

    for (int x: v[ver])
    {
        if (x==par)
            continue;
        if (visi[x]==0)
        {
            dfs(v,x,ver,ans);
            low[ver] = min(low[x],low[ver]);
            if (low[x]>d[ver])
            {
                ans.push_back({ver,x});
            }
        }
        else
        {
            low[ver] = min(low[ver],low[x]);
        }
    }
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> v[n+3];

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<pair<int,int>> ans;

    for (int i = 1;i<=n;i++)
    {
        if (visi[i]==0)
        {
            dfs(v,i,-1,ans);
        }
    }

    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }


}