#include<bits/stdc++.h>
using namespace std;
int keys[100001],freq[100001];
int sum(int freq[],int i,int j)
{
	int s=0;
	for(int k=i;k<=j;k++)
	{
		s+=freq[k];
	}
	return s;
}
int optimal_tree(int n)//from keys ki...kj taking kr as root key
{
	int i,j,l,r,optcost[n][n];//optcost[0][n-1] stores final result
	
	for(i=0;i<n;i++)
		optcost[i][i]=freq[i];//j=i means single element(key)
	
	for(l=2;l<=n;l++)// l for chain length 2,3,..(similar to matrix chain)
	{
		for(i=0;i<=n-l+1;i++)
		{
			j=i+ l-1;
			optcost[i][j]=INT_MAX;
			for(r=i;r<=j;r++)// for choosing root
			{
				int c=((r>i)?optcost[i][r-1]:0) + ((r<j)?optcost[r+1][j]:0) + sum(freq,i,j); 
				optcost[i][j]=min(optcost[i][j],c);
			}
		}
	}
	return optcost[0][n-1];		
}
int main()
{
	int i,j,n;
	cin>>n;
	memset(keys,0,100001);
	memset(freq,0,100001);
	for (i = 0; i < n; ++i)
	{
		cin>>keys[i];//input in sorted order
	}
	for (i = 0; i < n; ++i)
	{
		cin>>freq[i];//input freq.
	}

	cout<<optimal_tree(n)<<endl;
	return 0;
}
