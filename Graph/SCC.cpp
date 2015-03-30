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
#define all(a) a.begin(),a.end():wq
#define DRT() int t; cin>>t; while(t--)
#define DRI(n) int n; cin>>n;
#define DRII(n,m) int n,m; cin>>n>>m;
#define gc getchar_unlocked
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
 
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< pair< int , PII > > VPIII;

inline void fs(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

class graph//directed graph
{
public:
    int V,c;//no. of vertices
    list<int> *adj;//adjacency list for graph
    graph(int V);
    void order(int v,bool visited[],stack<int> &Stack);
    void DFS(int v,bool visited[]);
    void addedge(int v,int w);
    void SCC();
    graph transpose(); 
};
graph::graph(int V)//constructor
{
    this->V=V;
    this->c=0;
    adj=new list<int>[V];//allocate list(memory) for V vertices
}
void graph::DFS(int v,bool visited[])
{
    visited[v]=true;
    //cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)//neighbors
    {
        if(!visited[*it])
            DFS(*it,visited);
    }
}
graph graph::transpose()
{
    graph g(V);//re-initialised
    int v;
    list<int>::iterator i;
    for(v=0;v<V;v++)
    {
        for(i=adj[v].begin();i!=adj[v].end();i++)//neighbors of v
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;//graph
}
void graph::addedge(int v, int w)
{
    adj[v].push_back(w);
}
void graph::order(int v,bool visited[],stack<int> &Stack)//using dfs and putting in stack for finishing time
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)//neighbors
    {
        if(!visited[*i])
            order(*i,visited,Stack);
    }
    Stack.push(v);
}
void graph::SCC()
{
    stack<int> Stack;
    bool visited[V];
    memset(visited,false,V);

    for(int i=0;i<V;i++)//filling in stack to get finish time
    {
        if(!visited[i])
            order(i,visited,Stack);
    }
    //graph transpose
    graph g=transpose();
    memset(visited,false,V);// now DFS for the transpose graph i.e g
    while(!Stack.empty())
    {
        int v=Stack.top();//top element and apply dfs
        Stack.pop();
        if(!visited[v])
        {    g.DFS(v,visited);
             c++;
             //cout<<endl;
        }        
    } 
    cout<<c<<endl;   
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
    int i,n,e,u,v;
    cin>>n>>e;//n vertices,e edges
	graph g(n);
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        g.addedge(u,v);   
    }    
    g.SCC();
    return 0;
}
