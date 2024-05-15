#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll ans = 1;

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



ll prime_factorization(ll n){
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            ans *= (bigMod(i, cnt + 1) - 1) % mod;
            ans = ans % mod;
            ans * (bigMod(i - 1, mod - 2)) % mod;
            ans = ans % mod;
        }
    }
    if(n != 1){
        ans = (ans * (bigMod(n, 2) - 1) % mod) % mod;
        ans = (ans * bigMod(n - 1, mod - 2)) % mod;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll pre = 0, i = 1, p;
    ll ans = 0;
    while(i < n){
        p = n / i;
        ll next = (n / p + 1);
        next = min(n + 1, next);
        ll x = (next - i);
        ll tm = (x * (i + next - 1) % mod) % mod;
        tm = (tm * p) % mod;
        tm = (bigMod(2, mod - 2) * tm) % mod;
        ans = (ans + tm) % mod;
        //cout << i << " " << p << " " << ans << endl;
        i = next;
    }
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