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
    ll n, m;
    cin >> n >> m;
    ll a[n + 1];
    ll sub[n + m + 5] = {0};
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        sub[a[i]] = m + 1;
    }

    ll ans = n * m * (m + 1);

    for(ll i = 0; i < m; i++){
        ll p, v;
        cin >> p >> v;
        sub[a[p]] -= (m - i);
        sub[v] += (m - i);
        a[p] = v;
    }

    for(ll i = 0; i <= n + m; i++){
        ans -= (sub[i] * (sub[i] - 1)) / 2;
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