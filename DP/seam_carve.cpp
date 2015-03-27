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
 
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< pair< int , PII > > VPIII;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int b[1000][1000],i,j,m,n,d[1000][1000];
	cin>>m>>n;
	memset(b,INT_MAX,1000*1000);
	for ( i = 1; i <=m; ++i)
	{
		for(j=1;j<=n;j++)
		{
			cin>>d[i][j];//disruptive values
			//b[i][j]=INT_MAX;
		}
	}
	for(j=1;j<=n;j++)
		b[1][j]=d[1][j];//base case

	for(i=2;i<=m;i++)
	{
		b[i][1]=min(b[i-1][1],b[i-1][2]) + d[i][1];
		b[i][n]=min(b[i-1][n],b[i-1][n-1]) + d[i][n];
		for(j=2;j<=n-1;j++)
		{
			b[i][j]=min( min(b[i-1][j-1],b[i-1][j]), b[i-1][j+1]) + d[i][j];//check with arrows
			
		}
	}
	int min_seam=INT_MAX;
	for(j=1;j<=n;j++)
	{
		min_seam=min(min_seam,b[m][j]);
	}
	cout<<min_seam<<endl;
	return 0;
}
