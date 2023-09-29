#include<bits/stdc++.h>
using namespace std;




int naive(int arr[], int n)
{
    int ans = INT_MIN;

    vector<int> dp(n,0);

    vector<int> path_count(n,0);
    
    vector<int> pre(n,-1);

    int last = -1;
    for (int i=0;i<n;i++)
    {
        int mx = 0;
        for (int j=0;j<i;j++)
        {
            if (arr[i]>arr[j])
            {
                if (mx<dp[j])
                {
                    mx = dp[j];
                    pre[i]=j;
                }
            }
        }

        dp[i]=mx+1;
        if (ans<dp[i])
        {
            last = i;
            ans=dp[i];
        }
    }

    int i = last;
    cout<<"The longest increasing sequence in reverse \n";
    while (i!=-1)
    {
        cout<<arr[i]<<" ";
        i=pre[i];
    }

    cout<<endl;
    return ans;

}

int binary(int arr[], int n)
{
    vector<int> repli;
    
    repli.push_back(arr[0]);
    for (int i=1;i<n;i++)
    {
        int l = 0;
        int r = repli.size()-1;
        int mid;
        int x = -1;
        while (l<=r)
        {
            mid = (l+r)/2;

            if (repli[mid]>=arr[i])
            {
                r = mid - 1;
                x = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

       // cout<<x<<endl;

        if (x==-1)
        {
            repli.push_back(arr[i]);
        }
        else
        {
            repli[x]=arr[i];
        }
    
    }

    return repli.size();

}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int length = naive(arr,n);
    cout<<length<<endl;

    cout<<binary(arr,n)<<endl;


}