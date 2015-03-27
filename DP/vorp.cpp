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
VPII players[100001];
 //players::iterator it;
int v[1000][1000];
int vorp(int i,int x)
{
    if(i<0 || x==0)//base
        return 0;
    else if(v[i][x]!=-1)//computed
        return v[i][x];
    else
    {
        v[i][x]=vorp(i-1,x);//player for pos i not choosen
        TR(players[i],it)
        {
            if(it->S <=x)
                v[i][x]=max(v[i][x], it->F +vorp(i-1,x - it->S));//player for pos i choosen
        }
    }
    return v[i][x];
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int pos,P,N,X,i,j,vrp,k,c;//v is vorp (for player),c is cost(for player), N is no. of positions,P are no. of players
    cin>>N>>P>>X;//X is the budget
    for (i = 1; i <=P; ++i)
    {
        fs(pos);fs(vrp);fs(c);
        players[pos].PB(MP(vrp,c));
    }
    memset(v,-1,1000000);
    cout<<vorp(N,X)<<endl;
    return 0;
}
