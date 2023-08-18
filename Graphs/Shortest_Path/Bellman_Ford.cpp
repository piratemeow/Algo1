#include<bits/stdc++.h>
using namespace std;

//Since in a graph of Nnodes, in the worst case,
// you will take N-1 edges to reach the first to the last
// thereby we iterate for N-1 iterations

// Implementation of Bellman Ford algorithm
// Works on negative edge weights
// Does not work on negative cycles
// Can detect negative cycles

const int inf = 1e9 + 7;

int main ()
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

    vector<pair<pair<int,int>, int>> edges;
    for (int i=1;i<=n;i++)
    {
        for (auto x: v[i])
        {
            edges.push_back({{i,x.first},x.second});
        }
    }

    int start ;
    cin>>start;

    vector<int> dis(n+1,inf);

    dis[start] = 0;

    for (int i=1;i<=n-1;i++)
    {
        for (int j =0 ;j<edges.size();j++)
        {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int wt = edges[j].second;

            if (dis[u]+wt< dis[v])
            {
                dis[v] = dis[u]+wt;
            }
        }
    }

    bool flag = 0;

    for (int j =0 ;j<edges.size();j++)
    {
        int u = edges[j].first.first;
        int v = edges[j].first.second;
        int wt = edges[j].second;

        if (dis[u]+wt< dis[v])
        {
            flag = 1;
            break;
            dis[v] = dis[u]+wt;
        }
    }


    if (flag)
    {
        cout<<"Negative cycle exists\n";
    }

    else
    {
        for (int i=1;i<=n;i++)
        {
            cout<<dis[i]<<endl;
        }

    }
    
}