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
    // vector< pair< ll, ll > > v;
    // for(ll i = 0; i < n; i++){
    //     ll x, y;
    //     cin >> x >> y;
    //     v.push_back({x,y});
    // }

    // sort(v.begin(), v.end());
    // ll ans = 0;
    // for(ll i = 0; i < n; i++){
    //     ll x1 = v[i].first;
    //     ll y1 = v[i].second;
    //     for(ll j = i + 1; j < n; j++){
    //         ll x2 = v[j].first;
    //         ll y2 = v[j].second;
    //         ll x = x2 - x1;
    //         ll y = y2 - y1;
    //         if(x == 0 || y == 0 || abs(x) == abs(y)){
    //             //cout << x1 << "," << y1 << "   " << x2 << "," << y2 << endl;
    //             ans++;
    //         }
    //     }
    // }

    // cout << ans * 2 << endl;
    map< ll, ll > vertical, horigental, diogonal1, digonal2;
    for(ll i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        vertical[x]++;
        horigental[y]++;
        diogonal1[(x - y)]++;
        digonal2[(x + y)]++;
    }

    ll ans = 0;
    for(auto x: vertical){
        ans += (x.second * (x.second - 1));
    }

    for(auto x: horigental){
        ans += (x.second * (x.second - 1));
    }

    for(auto x: diogonal1){
        ans += (x.second * (x.second - 1));
    }

    for(auto x: digonal2){
        ans += (x.second * (x.second - 1));
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