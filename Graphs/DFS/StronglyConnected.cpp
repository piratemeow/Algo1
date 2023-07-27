#include<bits/stdc++.h>
using namespace std;


const int N = 1e7+3;
int color[N]; // 0 for while 1 for black and -1 for grey
int d[N]; // Discovery time
int f[N]; // Finish time
int pi[N]; // Tree edge
int t = 0; // To track time

void dfs(vector<int> v[], int ver)
{
    //cout<<ver<<endl;
    color[ver] = -1;
    t = t+1;
    d[ver] = t;

    for (int x : v[ver])
    {
        if (color[x] == 0)
        {
            dfs(v,x);
        }
    }

    color[ver] = 1;
    t = t+1;
    f[ver] = t;
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
        
    }
    
    for (int i=1;i<=n;i++)
    {
        if (color[i] == 0)
        {
            //cout<<i<<endl;
            dfs(v,i);
        }
    }
    vector<pair<int,int>> p;
    
    for (int i=1;i<=n;i++)
    {
        p.push_back({f[i],i});
    }    

    sort(p.begin(),p.end());

    vector<int> trans[n+1];

    for (int i=1;i<=n;i++)
    {
        for (int j = 0;j<v[i].size();j++)
        {
            trans[v[i][j]].push_back(i);
        }
    }

    memset(color,0,sizeof color);

    int count = 0;

    for (int i=p.size()-1;i>=0;i--)
    {
        if (color[p[i].second]==0)
        {
            dfs(trans,p[i].second);
            cout<<p[i].second<<endl;
            
            count++;
        }
    }
    
    cout<<count<<endl;

}