#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
// Can alse be done with bfs
int visi[N];
int color[N]; // for coloring graph vertices


// Can alse be done with bfs

bool isBipartite(vector<int> v[], int ver)
{
    visi[ver] = 1;
    bool flag = 1;
    for (int x: v[ver])
    {
        if (visi[x]==0)
        {
            color[x]=~color[ver];
            flag |= isBipartite(v,x);            
        }
        else
        {
            if (color[x]==color[ver])
            {
                return 0;
            }
        }
    }

    return flag;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> v[n+2];
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);

    }
    bool res = 1;
    for (int i=1;i<=n;i++)
    {
        if (visi[i]==0)
        {
            if (!isBipartite(v,i))
            {
                res = 0;
                break;
            }
        }
    }

    if (res)
    {
        cout<<"Bipartite\n";
    }
    else
    {
        cout<<"Not Bipartite\n";
    }
}