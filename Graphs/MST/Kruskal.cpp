#include<bits/stdc++.h>
using namespace std;

// Complexity: O(ElogV)


bool same_set(int v1,int v2, int dsu[])
{
    
    while (dsu[v1]!=v1)
    {
        v1=dsu[v1];
    }
    while (dsu[v2]!=v2)
    {
        v2=dsu[v2];
    }

    if (v1==v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int path_compress(int v, int dsu[])
{
    if (dsu[v]==v)
    {
        return v;
    }
    return dsu[v]=path_compress(dsu[v],dsu);
}


void dsu_union(int v1, int v2, int dsu[])
{
    int p = path_compress(v1,dsu);
    int q = path_compress(v2,dsu);
    dsu[q]=p;
    return;

}


int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v[n+2];
    while (m--)
    {
        int a, b ,wt;
        cin>>a>>b>>wt;
        v[a].push_back({b,wt});
        v[b].push_back({a,wt});
    }

    vector<pair<int,pair<int,int>>> g;

    for (int i=1;i<=n;i++)
    {
        for (auto it:v[i])
        {
            int wt = it.second;
            int v1 = i;
            int v2 = it.first;
            g.push_back({wt,{v1,v2}});
        }
    }

    sort(g.begin(),g.end());
    int dsu[n+2];
    for (int i=1;i<=n;i++)
    {
        dsu[i]=i;
    }

    int total_wt = 0;

    vector<pair<int,int>> ans[n+2];

    for (auto e:g)
    {
        int wt = e.first;
        int v1 = e.second.first;
        int v2 = e.second.second;
        if (!same_set(v1,v2,dsu))
        {
            total_wt+=wt;
            ans[v1].push_back({v2,wt});
            ans[v2].push_back({v1,wt});
            dsu_union(v1,v2,dsu);

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


    // DSU testing code

    // int n;
    // cin>>n;
    // int dsu[n+2];
    // for (int i=1;i<=n;i++)
    // {
    //     dsu[i]=i;
    // }

    // dsu_union(1,2,dsu);
    // dsu_union(3,4,dsu);
    // dsu_union(3,6,dsu);
    // dsu_union(3,5,dsu);
    // dsu_union(6,7,dsu);
    // dsu_union(7,9,dsu);
    // dsu_union(8,10,dsu);
    // cout<<same_set(5,6,dsu)<<endl;

    // for (int i=1;i<=n;i++)
    // {
    //     cout<<dsu[i]<<"\n";
    // }




}