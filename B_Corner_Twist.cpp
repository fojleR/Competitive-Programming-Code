#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define pp pair<ll,ll>
#define ll int
#define True 1
#define gcd __gcd
#define range(i,a,b,c) for(ll i=a;i<b;i+=c)
#define int long long
#define lb lower_bound
#define ub upper_bound
#define False 0
#define prmap(m) {for(auto i: m) cout<<(i.fi)<<": "<<i.sec<<"  "; print("")}
#define maxa(p,q) *max_element(p,q)
#define mina(p,q) *min_element(p,q)
#define pq priority_queue<int>
#define all(v) v.begin(),v.end()
#define len(p) p.size()
#define append pb
#define foi(p,n) for(int i=p;i<n;i++)
#define ini(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define fi first
#define sec second
#define mp make_pair
#define tc while(t--)
#define N ((ll)800009)
#define gtc(a,b) cout<<"Case #"<<a<<": "<<b<<endl;
#define va(n) vector<ar<ll,n>>
#define fo(n) for(int i=0;i<n;i++)
#define rev(n) for(int i=n-1;i>=0;i--)
#define foj(m,n) for(int j=m;j<n;j++)
#define ar array
#define vp vector<pair<int,int>>
#define vc vector<int>
#define print(p) cout<<p<<"\n";
#define pr(p) cout<<p<<" ";
#define pr2(p,q) cout<<p<<" "<<q<<endl;
#define pr3(p,q,r) cout<<p<<" "<<q<<" "<<r<<endl;
#define pr4(p,q,r,s) cout<<p<<" "<<q<<" "<<r<<" "<<s<<endl;
#define pra(a) {for(auto i: a) cout<<i<<" "; cout<<endl;}
#define prm(a) {for(auto i: a) pra(i) cout<<endl;}
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define isvalid(i,j,n,m) (1<=i and i<=n and 1<=j and j<=m)
#define gh fflush(stdout)
#define why {print("LOL") return 0;}
using namespace std;


ll n,t,k,maxn,x,y,flag=0,l1,r1,l2,r2,parity[2]={0,0},ok,need,c=0,m;
ll mod=1e9+7,INF=1e18,MAX=5e5;

string s;
ll dp[1001][1025];

ll get(ll mask){
	fo(k/2){
		ll p1=(mask&(1<<i))>0;
		ll p2=(mask&(1<<(k-i-1)))>0;
		if(p1!=p2) return 1;
	}
	return 0;
}

ll getMask(ll mask,ll i,ll c){
	if(i<k) return mask+c*(1<<i);
	return (mask>>1)+c*(1<<(k-1));
}

ll rec(ll i,ll mask){
	if(i>=k and get(mask)==0) return 0;
	if(i==n) return 1;
	if(dp[i][mask]!=-1) return dp[i][mask];
	ll ans,newmask=mask;
	if(s[i]!='?') ans=rec(i+1,getMask(mask,i,(s[i]=='A')));
	else ans=(ans+rec(i+1,getMask(mask,i,0))+rec(i+1,getMask(mask,i,1)))%mod;
	return dp[i][mask]=ans;
}

signed main()
{

fio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("all.txt", "w", stdout);
#endif

t=1;
// cin>>t;
ll uu=t;


tc{
	mod=998244353;
	cin>>n>>k;
	cin>>s;
	memset(dp,-1,sizeof(dp));
	print(rec(0,0))
}

return 0;}