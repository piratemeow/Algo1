#include <bits/stdc++.h>
using namespace std;

// problem : activity selection: select the maximum activity from a set of activities that do not overlap
// Sort the activities by their finish time in decreasing order
// take the activities that do not overlap in that order
// Complexity O(n) although sorting takes O(nlogn)
bool comp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second<p2.second;
}

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    vector<pair<int,int>> v; // To store the activities

    for (int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end(),comp);

    // for (int i=0;i<n;i++)
    // {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    vector<pair<int,int>> selected_activity;

    selected_activity.push_back(v[0]);
    for (int i=1;i<n;i++)
    {
        if (selected_activity.back().second<=v[i].first)
        {
            selected_activity.push_back(v[i]);
        }
    }
    for (int i=0;i<selected_activity.size();i++)
    {
        cout<<selected_activity[i].first<<" "<<selected_activity[i].second<<endl;
    }


}