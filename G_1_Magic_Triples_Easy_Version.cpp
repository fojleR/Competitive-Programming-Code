#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

void solve(){
    ll n;
    cin  >> n;
    ll a[n];
    unordered_map< ll, ll > cnt;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        // cout << a[i] << " " << cnt[a[i]] << endl;
        ans += ((cnt[a[i]]) * (cnt[a[i]] - 1) * (cnt[a[i]] - 2))/cnt[a[i]];
        for(ll j = 2; j * j <= a[i]; j++){
            if(a[i] % j == 0){
                ll x = a[i] / j;
                ll y = j;
                if(y % x == 0){
                    ans +=  cnt[y] * cnt[y / x];
                }
                if(y != x and x % y == 0){
                    ans += cnt[x] * cnt[x / y];
                }
                // cout << x << " " << y <<
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}