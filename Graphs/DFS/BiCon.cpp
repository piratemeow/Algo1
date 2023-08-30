#include <bits/stdc++.h>
using namespace std;


//Undirected connected Graph

#define f first
#define s second

const int N = 1e7 + 5;
int d[N];
int low[N];
int visi[N];
int t = 0;

stack<pair<int,int>> s;
vector<vector<pair<int,int>>> p;

bool cmp(pair<int,int>&p1,pair<int,int>&p2)
{
    if (p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
void dfs(vector<int> v[], int ver, int par, set<int> &ans)
{
    visi[ver] = 1;
    t = t + 1;
    d[ver] = t;
    low[ver] = t;
    int child = 0;
    for (int x: v[ver])
    {
        if (x==par)
            continue;
        if (visi[x]==0)
        {
            s.push({min(ver,x),max(ver,x)});
            dfs(v,x,ver,ans);
            low[ver] = min(low[x],low[ver]);
            if (low[x]>=d[ver] && par!=-1)
            {
                
                int u = min(ver, x), v = max(ver, x);
                vector <pair <int, int>> comp;
                while(s.top().f != u || s.top().s != v) {
                    //cout << s.top().f << " " << s.top().s << "\n";
                    comp.push_back({s.top().first,s.top().second});
                    s.pop();
                }
                //cout << u << " " << v << "\n";
                comp.push_back({u,v});
                p.push_back(comp);
                s.pop();
                ans.insert(ver);
            }
            
        }
        else
        {
            low[ver] = min(low[ver],d[x]);
            if(d[x] < d[ver]) {
                s.push({min(ver,x),max(ver,x)});
            }
        }
        child++;
    }

    

    if (child>1 && par==-1)
    {
        // int x = par;
        // int u = min(ver, x), v = max(ver, x);
        // vector <pair <int, int>> comp;
        // while(s.top().f != u || s.top().s != v) {
        //     //cout << s.top().f << " " << s.top().s << "\n";
        //     comp.push_back({s.top().first,s.top().second});
        //     s.pop();
        // }
        // //cout << u << " " << v << "\n";
        // comp.push_back({u,v});
        // p.push_back(comp);
        // s.pop();
        // ans.insert(ver);
    }
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;

    vector<int> v[n+3];
    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    set<int> ans;

    for (int i=0;i<n;i++)
    {
        if (visi[i]==0)
        {
            dfs(v,i,-1,ans);
        }
    }
    vector<pair<int,int>> comp;
    while(!s.empty()) {
        //cout << s.top().f << " " << s.top().s << endl;
        comp.push_back({s.top().first,s.top().second});
        s.pop();
    }   
    if (comp.size()>0)
    {
        p.push_back(comp);


    }


    sort(p.begin(),p.end());

    for (auto &i:p)
    {
        sort(i.begin(),i.end(),cmp);
    }
    

    for (int i=0;i<p.size();i++)
    {
        for (int j =0 ;j<p[i].size();j++)
        {
            cout<<p[i][j].first<<" "<<p[i][j].second<<endl;
        }
        if (i==p.size()-1)
        {
            continue;
        }
        cout<<"-\n";
    }


    // for (auto x: ans)
    // {
    //     cout<<x<<endl;
    // }




}