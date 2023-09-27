#include <bits/stdc++.h>
using namespace std;

// problem : Fractional Knapsack: Given a set of items with their weights and prices, find the maximum profit that can be obtained by taking a fraction of each item
// Sort the items by their price/weight in decreasing order
// take the items in that order until the knapsack is full
// Complexity O(n) although sorting takes O(nlogn)

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> items;
    vector<pair<double,int>> price_per_wt;

    for (int i=0;i<n;i++)
    {
        double p,wt;
        cin>>p>>wt;

        items.push_back({p,wt});
        price_per_wt.push_back({p/wt,i});
    }

    sort(price_per_wt.begin(),price_per_wt.end(),greater<pair<double,int>>());
    // for(int i =0 ;i<n;i++)
    // {
    //     cout<<price_per_wt[i].first<<" "<<price_per_wt[i].second<<endl;
    // }

    int i = 0;

    double ans = 0;
    while(k)
    {
        if (i==n)
        {
            break;
        }
        
        if (k>=items[price_per_wt[i].second].second)
        {
            k-=items[price_per_wt[i].second].second;
            ans+=items[price_per_wt[i].second].first;
        }

        else
        {
            ans+= price_per_wt[i].first*k;
            k=0;
        }
        i++;
    }

    cout<<ans<<endl;

}