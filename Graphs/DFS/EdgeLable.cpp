#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+3;
int color[N]; // 0 for while 1 for black and -1 for grey
int d[N]; // Discovery time
int f[N]; // Finish time
int pi[N]; // Tree edge
int t = 0; // To track time
vector<pair<int,int>> tree;
vector<pair<int,int>> back;
vector<pair<int,int>> forwardd;
vector<pair<int,int>> cross;

void dfs(vector<int>v[], int ver)
{
    //cout<<ver<<endl;
    color[ver] = -1;
    t = t + 1;
    d[ver] = t;
    for (int x : v[ver])
    {
        if (color[x]==-1)
        {
            back.push_back({ver,x});
        }
        else if (color[x]==1)
        {
            if (d[ver]<d[x])
            {

                forwardd.push_back({ver,x});
            }
            else
            {
                cross.push_back({ver,x});
            }
        }
        else if (color[x]==0)
        {
            dfs(v,x);
            pi[x] = ver;
            tree.push_back({ver,x});
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
        //v[b].push_back(a); // Change here for the directed graph
    }
    int time = 0;
    for (int i=1;i<=n;i++)
    {
        if (color[i]==0)
        {
            dfs(v,i);
        }
    }
    cout<<"Printing tree edge\n";
    for (int i=0;i<tree.size();i++)
    {
        cout<<tree[i].first<<" "<<tree[i].second<<endl;
    }
    cout<<"Printing back edges\n";
    for (int i=0;i<back.size();i++)
    {
        cout<<back[i].first<<" "<<back[i].second<<endl;
    }
    cout<<"Printing forward edges\n";
    for (int i=0;i<forwardd.size();i++)
    {
        cout<<forwardd[i].first<<" "<<forwardd[i].second<<endl;
    }
    cout<<"Printing cross edges\n";
    for (int i=0;i<cross.size();i++)
    {
        cout<<cross[i].first<<" "<<cross[i].second<<endl;
    }
}