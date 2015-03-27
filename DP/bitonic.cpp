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
typedef pair<int,int> point;
typedef vector<int> VI;
typedef vector< point > VPII;
typedef vector< pair< int , point > > VPIII;

point p[100001];//array of points

float dist(point a, point b)
{
	return sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}
bool comp(point a, point b)
{
	return (a.F < b.F);
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int i,j,n,k,x,y;
	float b[1000][1000];//b  & p can be vectors  vector<vector< float > > and vector< int > 
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		p[i]=MP(x,y);
	}
	sort(p,p+n,comp);
	b[0][1]=dist(p[0],p[1]);
	for(j=2;j<n;j++)
	{
			for(i=0;i<j-1;i++)//leftgoing
			{
				b[i][j]=b[i][j-1] + dist(p[j-1],p[j]);
			}
			//i=j-1
			for(k=0;k<j-1;k++)//rightgoing from p(j-1)
			{
				float temp=b[k][j-1]+dist(p[k],p[j]);
				if(k==0||temp < b[j-1][j])
				{
					b[j-1][j]=temp;		
				}
			}
	}
	b[n-1][n-1]=b[n-2][n-1]+ dist(p[n-1],p[n-2]);
	printf("%f\n",b[n-1][n-1]);
	return 0;
}
