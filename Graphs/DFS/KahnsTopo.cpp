#include <bits/stdc++.h>
using namespace std;


int main ()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v[n +1];
    int indegree[n+2];
    memset(indegree,0,sizeof indegree);

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
        if (indegree[i]==0)
        {
            //cout<<i<<endl;
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int x: v[cur])
        {
            indegree[x]--;
            if (indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
    if (ans.size()==0)
    {
        cout<<"Topological sorting can not be done for this graph\n";
    }
    else
    {
        for (int a: ans)
        {
        cout<<a<<" ";
        }

    }
}