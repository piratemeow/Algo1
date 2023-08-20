#include<bits/stdc++.h>
using namespace std;

const int inf = 1e6 + 7;

// Implementation of Floyad-Warshal algorithm
// Complexity O(V^3)
// Wroks on negative edges
// Does not work on negative cycles
// Can detect negative cycle

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;

    // We will be needing adjacency matrix for this algorithm

    int v[n+1][n+1];
    memset(v,0,sizeof v);

    while (m--)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        v[a][b]=wt;
        v[b][a]=wt;
    }

    // We can also do an inplace algoritm

    int dis[n+1][n+1];
    memset(dis,0,sizeof dis);

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if(v[i][j]!=0)
                dis[i][j]=v[i][j];
            else if (v[i][j]==0 && i!=j)
            {
                dis[i][j]=inf;
            }

            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for (int k = 1; k<=n;k++)
    {
        for (int i= 1;i<=n;i++)
        {
            for (int j = 1;j<=n;j++)
            {
                if (dis[i][k]<inf && dis[k][j]<inf)
                    dis[i][j] = min (dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    bool flag = 0;
    for (int i=1;i<=n;i++)
    {
        if (dis[i][i]<0)
        {
            flag = 1;
        }
    }

    if (flag)
    {
        cout<<"The graph has a negative cycel\n";
    }

    else
    {
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