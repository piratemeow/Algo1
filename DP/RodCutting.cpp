#include <bits/stdc++.h>
using namespace std;

int cut[100000];
int price[1000000];
int dp[1000000];

int r[1000000];

int bottom_up(int n)
{
   memset(dp,0,sizeof dp);
   for (int i=1;i<=n;i++)
   {
      int q = INT_MIN;
      for (int j=1;j<=i;j++)
      {
         q = max(q,price[j]+dp[i-j]);
      }

      dp[i]=q;
   }

}


int top_down(int n)
{
   if (n==0)
   {
      return 0;
   }

   if (dp[n]!=-1)
   {
      return dp[n];
   }
   int q = INT_MIN;
   for (int i=1;i<=n;i++)
   {
      q = max(q,price[i]+top_down(n-i));
   }
   return dp[n]=q;
}

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int n;
   cin>>n;
   
   for (int i=1;i<=n;i++)
   {
      cin>>price[i];
   }

   memset(dp,-1,sizeof dp);

   cout<<top_down(n)<<endl;
   bottom_up(n);
   cout<<dp[n]<<endl;


}