#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
vector<bool> visited(1000,false);
queue<int> Q;
void bfs()
{
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		cout<<u<<" ";
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(visited[v]==false)
			{
				visited[v]=true;
				Q.push(v);
			}
		}
	}
}
int main()
{
	int n,e,j,x,y,start;
	cin>>n>>e;
	for(j=0;j<e;j++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
	}
	start=0;//assuming start vertex is 0
	Q.push(start);
	visited[start]=true;
	bfs();
	cout<<endl;
	return 0;
}