#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 1e6 + 10;
const int mod = 1e9 + 7;
ll fact[mx];
void cal(){
    fact[0] = 1;
    for(int i = 1; i <= 1e6; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll bigMod(ll x,ll p){
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}

void solve(){
    cal();
    int n;
    cin >> n;
    ll ans = fact[n];
    ans = (ans - bigMod(2, n - 1) + mod) % mod;
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}