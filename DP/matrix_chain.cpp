#include<bits/stdc++.h>
using namespace std;
int m[100][100],p[100];
int memoized_cost(int i,int j)//Ai...Aj
{
	if(m[i][j]!=-1)//computed
		return m[i][j];
	if(i==j)
		m[i][j]=0;
	else
	{
		for(int k=i;k<=j-1;k++)
		{
			m[i][j]=min(m[i][j],memoized_cost(i,k)+memoized_cost(k+1,j)+p[i-1]*p[k]*p[j]);//saved
		}
	}
	return m[i][j];
}
int main()
{
	int i,l,k,n,j;
	cin>>n;
	for(i=0;i<=n;i++)
		cin>>p[i];//since from pi-1 to pn
	for(i=1;i<=n;i++)
		m[i][i]=0;
	//using DP
	for(l=2;l<=n;l++)//l is chain length
	{
		for(i=1;i<=n-l+1;i++)//Ai....Aj
		{
			j=i + l-1;
			m[i][j]=INT_MAX;

			for(k=i;k<=j-1;k++)
			{
				m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);//m[i][j] is the optimal cost
			}

		}
	}
	cout<<m[1][n]<<endl;
	return 0;
}