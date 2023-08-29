#include<bits/stdc++.h>
using namespace std;

const int inf = 1e6 + 7;
const int N = 1e4+5;
int v[N][N];
int dis[N][N];
int path [N][N];

// Implementation of Floyad-Warshal algorithm
// Complexity O(V^3)
// Wroks on negative edges
// Does not work on negative cycles
// Can detect negative cycles


void printPath(int start, int ver , int path[][N])
{
    if (path[start][ver]==-1)
    {
        return;
    }

    printPath(start,path[start][ver],path);
    cout<<path[start][ver]<<" ";
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;

    // We will be needing adjacency matrix for this algorithm

    
    memset(v,0,sizeof v);

    while (m--)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        v[a][b]=wt;
        v[b][a]=wt; // Change here for the directed graph
    }

    // We can also do an inplace algoritm

    memset(dis,0,sizeof dis);

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (v[i][j]!=0)
            {
                path[i][j]=i;
                path[j][i]=j;// Change here for the directed graph
            }
            else
            {
                path[i][j]=-1;
            }

        }
    }

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

            //cout<<dis[i][j]<<" ";
        }
        //cout<<endl;
    }

    //cout<<endl;

    for (int k = 1; k<=n;k++)
    {
        for (int i= 1;i<=n;i++)
        {
            for (int j = 1;j<=n;j++)
            {
                if (dis[i][k]<inf && dis[k][j]<inf)
                {
                    if (dis[i][j]>dis[i][k]+dis[k][j])
                    {
                        dis[i][j] = dis[i][k]+dis[k][j];
                        path[i][j] = k;
                    }
                    
                }
                    
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
        printPath(1,5,path);
        cout<<endl;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cout<<path[i][j]<<" ";
            }   
            cout<<endl;
        }
    }

    

}