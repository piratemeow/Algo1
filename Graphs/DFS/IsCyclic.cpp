#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int color[N];
bool isCyclic(vector<int> v[],int ver,int par)
{
    //cout<<ver<<endl;
    color[ver] = -1;
    bool flag = 0;
    for (int x : v[ver])
    {
        if (color[x]==0)
        {
            flag |= isCyclic(v,x,ver);
        }
        else if (color[x]==-1 && x!=par)
        {
            return 1;
        }
    }
    color[ver]=1;

    return flag;

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
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        //v[b].push_back(a); // Change here for directed graph
    }

    bool res = 0;
    for (int i=1;i<=n;i++)
    {
        if (color[i]==0)
        {
            if (isCyclic(v,i,-1))
            {
                res = 1;
                break;
            }

        }
        
    }
    if (res)
    {
        cout<<"Cyclic\n";
    }
    else
    {
        cout<<"Acyclic\n";
    }

}