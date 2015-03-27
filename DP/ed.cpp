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
	DRT()
	{
		int i,j,left,top,cor,m,n;
		char str1[2001],str2[2001];
		cin>>str1;
		cin>>str2;
		m=strlen(str1),n=strlen(str2);
		for(i=0;i<m;i++)
		{
			if(str1[i]>='a' && str1[i]<='z')
				str1[i]=str1[i]-32;
		}
		for(i=0;i<n;i++)
		{
			if(str2[i]>='a' && str2[i]<='z')
				str2[i]=str2[i]-32;
		}
		m+=1;// for '\0'
		n+=1;//for '\0'
		int *t=(int *)malloc((m*n)*sizeof(int));

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				*(t+i*n + j)=-1;
			}
		}
		for(i=0;i<m;i++)
		{
			*(t+ i*n)=i;//t[i][0]=i
		}
		for(j=0;j<n;j++)
			*(t+j)=j;//t[0][j]=j
	
		for(i = 1; i<m;i++)
		{
			for(j=1;j<n;j++)
			{
				left=*(t+i*n +j-1);//del
				left+=1;

				top=*(t+(i-1)*n+j);//ins
				top+=1;

				cor=*(t+(i-1)*n+j-1);//rep
				cor+=(str1[i-1]!=str2[j-1]);

				*(t+(i)*n+j)=min(min(left,top),cor);
			}
		}
		int c=*(t+m*n -1);
		cout<<c<<endl;
		free(t);
	}
	return 0;
}
