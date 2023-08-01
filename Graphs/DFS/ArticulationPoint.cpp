#include <bits/stdc++.h>
using namespace std;


//Undirected connected Graph

const int N = 1e7 + 5;
int d[N];
int low[N];
int visi[N];
int t = 0;

void dfs(vector<int> v[], int ver, int par, set<int> &ans)
{
    visi[ver] = 1;
    t = t + 1;
    d[ver] = t;
    low[ver] = t;
    int child = 0;
    for (int x: v[ver])
    {
        if (x==par)
            continue;
        if (visi[x]==0)
        {
            dfs(v,x,ver,ans);
            low[ver] = min(low[x],low[ver]);
            if (low[x]>=d[ver] && par!=-1)
            {
                ans.insert(ver);
            }
            child++;
        }
        else
        {
            low[ver] = min(low[ver],d[x]);
        }
    }

    if (child>1 && par==-1)
    {
        ans.insert(ver);
    }
}


int main()
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

    set<int> ans;

    for (int i=0;i<n;i++)
    {
        if (visi[i]==0)
        {
            dfs(v,i,-1,ans);
        }
    }

    for (auto x: ans)
    {
        cout<<x<<endl;
    }


}