#include <bits/stdc++.h>
using namespace std;


//This algorithm works only on DAGs
// Topologically sorts the vertices and then relaxes the connected vertices from the topologically sorted vertices in that order
// Complexity O(V+E)
const int N = 1e7+5;
const int inf = 1e9+5;
int color[N]; // 0 for while 1 for black -1 for grey
int par[N]; // To store the path
bool flag; // To detect cycles


void TopoSort(int ver, vector<pair<int,int>>v[], stack<int> &sortList)
{
    color[ver] = -1;
    
    for (auto x: v[ver])
    {
        if (color[x.first]==0)
        {
            TopoSort(x.first,v,sortList);
            par[x.first]=ver;
        }

        else if (color[x.first]==-1)
        {
            flag = 0;
        }
    }

    sortList.push(ver);

    color[ver] = 1;
}


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
        v[a].push_back({b,wt}); // As the graph has to DAG
    }

    int start;
    cin>>start;

    stack<int> sortList;
    flag = 1;

    TopoSort(start,v,sortList);
    if (flag==0)
    {
        cout<<"Has cycle in the graph\n";
        return 0;
    }

    int dis[n+1];
    for (int i=1;i<=n;i++)
    {
        dis[i]=inf;
    }

    dis[start] = 0;

    

    while (!sortList.empty())
    {

        int ver = sortList.top();
        cout<<ver<<endl;
        sortList.pop();
        for (auto x: v[ver])
        {
            if (dis[x.first]>dis[ver]+x.second)
            {
                dis[x.first]=dis[ver]+x.second;
            }
        }
    }

    cout<<dis[5]; // To print the distance of any vertex from the starting one

}