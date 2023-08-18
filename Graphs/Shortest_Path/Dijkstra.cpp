#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

// Implementation of dijkstra algorithm
// Complexity O(nlogn + e)
// 1 based indexing of edges
// Does not work for the graphs with negative edge weights and cycles

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

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    int start ;
    cin>>start;

    vector<int> dis(n+2,inf);
    vector<int> visi(n+2,0);

    pq.push({0,start});
    dis[start] = 0;

    while (!pq.empty())
    {        
       
        pair<int,int> cur = pq.top();
        pq.pop();
        int wt = cur.first;
        int ver = cur.second;
        visi[ver]= 1;

        for (auto x : v[ver])
        {
            if (visi[x.first])
            {
                continue;
            }

            if (dis[ver] + x.second < dis[x.first])
            {
                dis [x.first] = dis[ver] + x.second;
                pq.push({x.second,x.first});
            }
        }
    }


    for (int i=1;i<=n;i++)
    {
        cout<<dis[i]<<endl;
    }

}