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

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int n,M,i,j,l[100001],extras[100][100],lc[100][100],c[100];
    fs(M);fs(n);
    for(i=1;i<=n;i++)
        fs(l[i]);
    //  1<=i<=j<=n
    for(i=1;i<=n;i++)//compute extra spaces from i(word) to j(word) in a line
    {
        extras[i][i]=M-l[i];
        for(j=i+1;j<=n;j++)
        {
            extras[i][j]=extras[i][j-1]+l[j]-1;//since -(j-i)=-1
        }
    }
    //  1<=i<=j<=n
    for (i = 1; i <=n ; ++i)//compute cost from i(word) to j(word) in a line
    {
        for(j=i;j<=n;j++)
        {
            if(extras[i][j]<0)//can't fit in same line
                lc[i][j]=INT_MAX;//INF
            else if(j==n && extras[i][j]>=0)
                lc[i][j]=0;//last line
            else
                lc[i][j]=extras[i][j]*extras[i][j];//*extras[i][j];
        }
    }
    c[0]=0;
    for(j=1;j<=n;j++)
    {
        c[j]=INT_MAX;//INF
        for(i=1;i<=j;i++)
        {
            //if(c[i-1]+lc[i][j]<c[j]))
            c[j]=min(c[j],c[i-1]+lc[i][j]);
        }
    }
    /*for(i=1;i<=n;i++)//last line's cost is 0
        cout<<c[i]<<" ";*/
    cout<<c[n-1]<<endl;
    return 0;
}
