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
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll xx = 1e11;
    ll ans = LONG_LONG_MAX;
    ll x = 1;
    while(1){
        ll y = x, sum = 0;
        for(ll i = 0; i < n; i++){
            y = pow(x, i);
            sum += abs(a[i] - y);
            if(y > xx){
                cout << ans << endl;
                return;
            }
        }
        if(sum > ans){
                cout << ans << endl;
                return;
            }
        ans = min(ans, sum);
        x++;
    }
}


int main(){
    fast
    ll t = 1;
    //cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}