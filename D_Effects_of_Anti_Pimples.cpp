#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 998244353;

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
    int n;
    cin >> n;
    ll a[n + 1];
    ll mx[n + 1];
    ll mx1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx1 = max(mx1, a[i]);
    }

    mx[1] = mx1;
    vector< ll > v;
    v.push_back(mx1);
    for(int i = 2; i <= n; i++){
        ll tmx = 0;
        for(int j = i; j <= n; j += i){
            tmx = max(tmx, a[j]);
        }
        mx[i] = tmx;
        v.push_back(tmx);
    }

    ll ans = 0;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        ans += (v[i] * bigMod(2, n - i - 1)) % mod;
        ans = ans % mod;
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