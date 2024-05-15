#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

ll lcm(ll a, ll b){
    return (a * b) / __gcd(a, b);
}

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    ll mx = -1e9;
    map<ll, ll > mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mp[a[i]] = 1;
    }
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector< ll > dif;
    for(ll i = 1; i < n; i++){
        dif.push_back(abs(a[i] - a[i - 1]));
    }
    ll gd = dif[0];
    for(ll i = 1; i < dif.size(); i++){
        gd = __gcd(gd, dif[i]);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += abs(a[i] - mx) / gd;
    }
    while(1){
        ans++;
        mx -= gd;
        if(mp[mx] == 0){
            cout << ans << endl;
            break;
        }
    }
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