#include<bits/stdc++.h>
using namespace std;
int r[100001],p[100001],revenue;
int memoized(int n)
{
	if(r[n]!=-1)//computed
		return r[n];
	if(n==0)
		revenue=0;
	else
	{	revenue=INT_MIN;
		for(int i=1;i<=n;i++)
			revenue=max(revenue,p[i]+memoized(n-i));
	}
	r[n]=revenue;//save
	return revenue;
}
int main()
{
	int i,j,n;
	memset(r,0,100001);
	memset(p,0,100001);
	cin>>n;//given length of rod
	for(i=1;i<=n;i++)
		cin>>p[i];//price for ith length
	//using DP
	for(j=1;j<=n;j++)
	{
		revenue=INT_MIN;
		for (i = 1; i <=j ; i++)
		{
			revenue=max(revenue,p[i]+r[j-i]);// breaking it in i and j-i pieces(can be further decomposed) and getting max
		}
		r[j]=revenue;
	}
	cout<<r[n]<<endl;
	return 0;
}