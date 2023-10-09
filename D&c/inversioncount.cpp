#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Counting inversions using merge sort
// Merge sort to sort in ascending order
// Complexity O(nlogn)
// Not an inplace sorting algorithm 
// Auxiliary space needed
// Stable sorting algorithm

int merge(int l,int r,int mid,int n,int arr[])
{
	int cnt = 0;
	int sz=mid-l+1;

	int x[sz];
	int y[r-mid];

	for (int i=0;i<sz;i++)
	{
		x[i]=arr[l+i];
	}

	for (int i=0;i<r-mid;i++)
	{
		y[i]=arr[mid+i+1];
	}

	int i=0,j=0;
    int t = l;
	for (;i<sz && j<r-mid;t++)
	{
		if (x[i]<=y[j])
		{
			arr[t]=x[i];
			i++;

		}
		else
		{
			arr[t]=y[j];
            cnt+=sz-i;
			j++;
		}
	}
    
    while (i<sz)
    {
        arr[t]=x[i];
        i++;
        t++;
    }

    while (j<r-mid)
    {
        arr[t]=y[j];
        j++;
        t++;
    }

	return cnt;

}

int merge_sort(int l,int r,int n,int arr[])
{
	int cnt = 0;
	if (l==r)
		return 0;


	int mid = (l+r)/2;
	cnt+=merge_sort(l,mid,n,arr);

	cnt+=merge_sort(mid+1,r,n,arr);
	cnt+=merge(l,r,mid,n,arr);

	return cnt;

}

int main ()
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

	cout<<merge_sort(0,n-1,n,arr);

}