//Kanv Kumar
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)//vector Traversal
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)// white space
#define pin(n) printf("%d\n",n)// newline
#define sortv(a) sort(a.begin(),a.end())// vector sort
#define all(a) a.begin(),a.end()
#define DRT() int t; cin>>t; while(t--)
#define DRI(n) int n; cin>>n;
#define DRII(n,m) int n,m; cin>>n>>m;
#define TRACE
using namespace std;
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#ifdef TRACE
#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

#define NINF INT_MIN 
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< pair< int , PII > > VPIII;

class Adjnode//each node has vetex no. & weight of edge
{
	int v;//vetex no.
	int weight;//weight of edge
public:
	Adjnode(int vertex,int wht)//constructor
	{
		v=vertex;
		weight=wht;
	}
	int getV()
	{
		return v;
	}
	int getweight()
	{
		return weight;
	}
};

class graph//represented using adjacency list
{
	int V;// no. of vertices
	void toposort(int v,bool visited[],stack<int> &Stack);
public:
	list<Adjnode> *adj;//adjacency list
	graph(int V)
	{
		this->V=V;
		adj=new list<Adjnode>[V]; 
	}
	void addedge(int u,int v,int weight)
	{
		Adjnode node(v,weight);//node initialized
		adj[u].push_back(node);
	}
	void longestPath(int s,int t);//src
};

void graph::toposort(int v,bool visited [],stack<int> &Stack)//similar to dfs
{
	visited[v]=true;
	list<Adjnode>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)//neighbors
	{
		if(!visited[i->getV()])
		{
			toposort(i->getV(),visited,Stack);
		}
	}
	Stack.push(v);//push current vertex
}

void graph::longestPath(int s,int t)
{
	stack<int> Stack;
	int dist[V];
	bool visited[V];
	memset(visited,false,V);
	for(int i=0;i<V;i++)// get & store topological order
	{
		if(!visited[i])
			toposort(i,visited,Stack);
	}
	for (int i = 0; i < V; ++i)//distance init
	{
		dist[i]=NINF;
	}
	dist[s]=0;
	// compute in topological order
	while(!Stack.empty())// update neigbhors
	{
		int u=Stack.top();
		Stack.pop();
		list<Adjnode>::iterator i;
		if(dist[u]!=NINF)
		{
			for(i=adj[u].begin();i!=adj[u].end();i++)//neighbors
			{
				if(dist[i->getV()] < dist[u] + i->getweight())
					dist[i->getV()] = dist[u] + i->getweight();
			}
		}
	}
	cout<<dist[t]<<endl;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n,e,u,v,w,t,s;
	cin>>n>>e>>s>>t;//no.of vertices,no.of edges,src,dest
	graph g(n);
	for (int i = 0; i < e; ++i)
	{
		cin>>u>>v>>w;
		g.addedge(u,v,w);
	}
	g.longestPath(s,t);
	return 0;
}
