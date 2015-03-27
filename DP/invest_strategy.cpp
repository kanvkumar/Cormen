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

float amount[1000][1000],rate[1000][1000];
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
    int i,j,n,m,k;
    fs(n);fs(m);//n policies,m years
    //DP(optimal substructure + overlapping subproblems)
    for (i = 1; i <=n; ++i)//policies
    {
        for ( j =1 ; j <=m; ++j)//years
        {
            scanf("%f",&rate[i][j]);

        }
    }
    float f1, f2, init_am;
    scanf("%f%f%f",&f1,&f2,&init_am);
    memset(amount,INT_MIN,sizeof(amount));
    for(i=1;i<=n;i++)
    {
        amount[i][1]=init_am*rate[i][1];
    }
    for(j=1;j<=m;j++)//jth year
    {
        for(i=1;i<=n;i++)//ith policy(in jth year) 
        {
            for(k=1;k<=n;k++)//for year j+1 ,choosing kth policy
            {    
                if(k==i)
                    amount[k][j+1]=max(amount[k][j+1],amount[i][j]*rate[k][j+1]-f1);
                else
                    amount[k][j+1]=max(amount[k][j+1],amount[i][j]*rate[k][j+1]-f2);
            }
        }
    }
    float temp=INT_MIN;
    for(i=1;i<=n;i++)
    {
        temp=max(temp,amount[i][m]);//from mth year
    }
    printf("%f\n",temp);;
    return 0;
}
