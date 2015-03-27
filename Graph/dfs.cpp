#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> visited(1000,false);
int i;
void dfs(int u)
{
	if(visited[u]==true)
	{
		return ;
	}
	visited[u]=true;
	cout<<u<<" ";
	for(i=0;i<adj[u].size();i++)// check neighbors
	{
		int v=adj[u][i];
		dfs(v);
	}
} 
int main()
{
	int x,y,n,u,e,j;
	cin>>n>>e;
	for(j=0;j<e;j++)
	{
		cin>>x>>y;
		//x--;
		//y--;
		adj[x].push_back(y);
		//adj[y].push_back(x);
	}
	
	for(j=0;j<n;j++)// if in different components
	{
		if(!visited[j])
		{
			dfs(j);
		}
	}
	cout<<endl;
	return 0;
}