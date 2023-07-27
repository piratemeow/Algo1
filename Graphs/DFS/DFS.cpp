#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+3;
int color[N]; // 0 for while 1 for black and -1 for grey
int d[N]; // Discovery time
int f[N]; // Finish time
int pi[N]; // Tree edge
int t = 0; // To track time

void dfs(vector<int>v[], int ver)
{
    //cout<<ver<<endl;
    color[ver] = -1;
    t = t + 1;
    d[ver] = t;
    for (int x : v[ver])
    {
        if (color[x]==0)
        {
            dfs(v,x);
            pi[x] = ver;
        }
    }
    t = t + 1;
    f[ver] = t;
    color[ver] = 1;
}

int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v[n+2];

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a); // Change here for the directed graph
    }
    int time = 0;
    for (int i=1;i<=n;i++)
    {
        if (color[i]==0)
        {
            dfs(v,i);
        }
    }

    for (int i=1;i<=n;i++)
    {
        cout<<i<<" "<<d[i]<<" "<<f[i]<<endl;
    }
    

}