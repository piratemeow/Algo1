#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int d[N];
int low[N];
int visi[N];
int t = 0;

stack<pair<int,int>> s;
vector<vector<pair<int,int>>> ans;
void dfs(int ver, int par, vector<int> v[], set<int> &ArtiPoint)
{
    visi[ver]=1;
    t = t+1;
    d[ver]=low[ver]=t;
    int child = 0;

    for (auto x:v[ver])
    {
        if (x==par)
        {
            continue;
        }
        else if (visi[ver]==0)
        {
            //s.push({min(ver,x),max(ver,x)});
            dfs(x,ver,v,ArtiPoint);
            low[ver] = min (low[x],low[ver]);
            if (low[x]>=d[ver] && par!=-1)
            {
                ArtiPoint.insert(ver);
                int u = min(x,ver), v = max(x,ver);
                vector<pair<int,int>> comp;
                while (s.top().first!=u || s.top().second!=v)
                {
                    comp.push_back({s.top().first,s.top().second});
                    s.pop();
                }
                comp.push_back({u,v});
                ans.push_back(comp);
                s.pop();
            }
        }
        else
        {
            low[ver] = min(low[ver],d[x]);
            if (d[x]<d[ver])
            {
                int u = min(x,ver), v = max(x,ver); 
                s.push({u,v});
            }
        }

        child++;
    }

    if (child>1 && par==-1)
    {
        // vector<pair<int,int>> comp;
        // int x = par;
        // int u = min(ver,x) , v= max(ver,x);

        // while (s.top().first!=u || s.top().second!=v)
        // {
        //     comp.push_back({s.top().first,s.top().second});
        //     s.pop();
        // }

        // comp.push_back({u,v});
        // s.pop();
        // ans.push_back(comp);
        // ArtiPoint.insert(ver);
        
    }

    
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> v[n+1];

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    set<int> ArtiPoint;

    for (int i=0;i<n;i++)
    {
        if (visi[i]==0)
        {
            dfs(i,-1,v,ArtiPoint);
        }
    }

    vector<pair<int,int>> comp;
    while(!s.empty()) 
    {
        //cout << s.top().f << " " << s.top().s << endl;
        comp.push_back({s.top().first,s.top().second});
        s.pop();
    }   
    if (comp.size()>0)
    {
        ans.push_back(comp);
    }

    //cout<<ans.size();
    for (int i=0;i<ans.size();i++)
    {
        for (int j =0 ;j<ans[i].size();j++)
        {
            cout<<ans[i][j].first<<" "<<ans[i][j].second<<endl;
        }
        if (i==ans.size()-1)
        {
            continue;
        }
        cout<<"-\n";
    }



}