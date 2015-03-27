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
#define sii(n,m) scanf("%d%d",&n,&m)
#define ss(x) scanf("%s",x)
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
	//int k,t;
	//cin>>t;
	//for(k=1;k<=t;k++)
	//{
		int n,m,c[1002][1002],i,j;
		int x[1002],y[1002];
		cin>>n>>m;
		for(i=0;i<n;i++)
			cin>>x[i];
		for(i=0;i<m;i++)
			cin>>y[i];
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(i==0 || j==0)
					c[i][j]=0;
				else if(x[i-1]==y[j-1])
					c[i][j]=c[i-1][j-1]+1;//added to lcs
				else 
					c[i][j]=max(c[i-1][j],c[i][j-1]);
			}
		}
		//cout<<"Case "<<k<<": "<<min(n,m)+max(n,m)-c[n][m]<<endl;
	//}	
		//cout<<c[n][m]<<endl;
		int len=c[n][m];
		int lcs[len],temp;
		i=n;
		j=m;
		temp=len;
		while(i>0&&j>0)
		{
			if(x[i-1]==y[j-1])
			{
				lcs[len-1]=x[i-1];
				i--;
				j--;
				len--;
			}
			else if(c[i-1][j]>c[i][j-1])
			{
				i--;
			}
			else //if(c[i][j-1]>c[i-1][j])
			{
				j--;
			}	
		}
		for(i=0;i<temp;i++)
			cout<<lcs[i]<<" ";
		cout<<endl;	
		return 0;
}
