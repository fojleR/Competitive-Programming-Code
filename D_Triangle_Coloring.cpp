#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 300005;
const int mod = 998244353;
ll fact[mx];

void cal_fact(){
    fact[0] = 1;
    for(int i = 1; i < mx; i++){
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

ll inverse_mod(ll a){
    return bigMod(a, mod - 2);
}

ll nCr(ll n, ll r){
    ll ans = (fact[n] * ((inverse_mod(fact[r] * fact[n - r])) % mod)) % mod;
    return ans;
}



void solve(){
    ll n;
    cin >> n;
    int nn = n;
    n = n / 3;
    ll ans = nCr(n, n / 2);

    ll a[nn];
    for(int i = 0; i < nn; i++){
        cin >> a[i];
    }

    for(int i = 0; i < nn; i += 3){
        vector< int > v;
        for(int j = i; j < i + 3; j++){
            v.push_back(a[j]);
        }
        // for(auto x: v){
        //     cout << x << " ";
        // }
        // cout << endl;
        sort(v.begin(), v.end());
        if(v[0] == v[1] and v[1] == v[2]){
            ans = (ans * 3) % mod;
        }
        else if(v[0] == v[1]){
            ans = (ans * 2) % mod;
        }
        else{
            ans = ans;
        }
    }

    cout << ans << endl;

}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    cal_fact();
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}