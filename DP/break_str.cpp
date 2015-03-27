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

int cost[100][100],k,t1,br[1000];
 
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

int cut(int i,int j,int start,int end)//br's i,j //string's start,end
{
	if(i==j)//single break point,thus->return length of that string
		return end-start+1;
	else if(cost[i][j]!=-1)//computed
		return cost[i][j];
	
	else
	{	
	
		cost[i][j]=min(cut(i+1,j,br[i]+1,end) + end-start+1,cut(i,j-1,start,br[j])+end-start+1);//break at start or end
		for(k=i+1;k<j;k++)// in b/w
		{ 
			cost[i][j]=min(cost[i][j],cut(i,k-1,start,br[k])+cut(k+1,j,br[k]+1,end)+end-start+1);

		}
	}
	return cost[i][j];
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n,m,i,x,j;
	fs(n);fs(m);
	memset(cost,-1,sizeof(cost));
	for(i=0;i<m;i++)
	{
		fs(br[i]);
	}
	sort(br,br+m);
	cout<<cut(0,m-1,0,n-1)<<endl;
	/*cut(0,m-1,0,n-1);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			trace3(cost[i][j],i,j)
	}*/
	return 0;
}
