#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v[n+4];
    while (m--)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        v[a].push_back({b,wt});
        //v[b].push_back({a,wt});
    }
    vector<int> h(n+4,inf);
    vector<pair<pair<int,int>, int>> edges;
    for (int i=1;i<=n;i++)
    {
        for (auto x: v[i])
        {
            edges.push_back({{i,x.first},x.second});
        }
    }

    for (int i=1;i<=n;i++)
    {
        edges.push_back({{n+1,i},0});
    }
    h[n+1]=0;

    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<edges.size();j++)
        {
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            int wt = edges[j].second;
            
            if (h[v]>h[u]+wt)
            {

                h[v]=h[u]+wt;
            }
        }
    }
    // for (int i=1;i<=n;i++)
    // {
    //     cout<<h[i]<<endl;
    // }
   
    bool flag = 0;

    for (int j =0 ;j<edges.size();j++)
    {
        int u = edges[j].first.first;
        int v = edges[j].first.second;
        int wt = edges[j].second;

        if (h[u]+wt< h[v])
        {
            flag = 1;
            break;
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
            for (auto x: v[i])
            {
                int u = i;
                int v = x.first;
                int wt = x.second;
                x.second = wt +h[u]-h[v];
            }
        }


        // Run dijkstra from all the vertices
        vector<vector<int>> dis(n+1,vector<int>(n+1,inf));

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for (int start = 1;start<=n;start++)
        {
            pq.push({0,start});
            dis[start][start] = 0;

            while (!pq.empty())
            {        
                
                pair<int,int> cur = pq.top();
                pq.pop();
                int wt = cur.first;
                int ver = cur.second;
                // visi[ver]= 1;

                for (auto x : v[ver])
                {
                    if (dis[start][ver] + x.second < dis[start][x.first])
                    {
                        dis[start][x.first] = dis[start][ver] + x.second;
                        pq.push({x.second,x.first});
                    }
                }
            }
        }

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }

    }


}