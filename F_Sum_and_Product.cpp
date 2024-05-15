#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

pair<ll, ll > cal_ab(ll x, ll y){
    ll sab = x*x - 4*y;
    if(sqrt(sab) * sqrt(sab) == sab and sab >= 0){
        ll a = (x + sqrt(sab)) / 2;
        ll b = x - a;
        if(a + b == x and a*b == y){
            return {a,b};
        }
        else{
            return {0,0};
        }
        
    }
    else{
        return {-1, -1};
    }
}

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    map< ll, ll > mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        pair<ll, ll> xx = cal_ab(x, y);
        // cout << xx.first << " " << xx.second << endl;
        if(xx.first == xx.second){
            ll ans = (mp[xx.first] * (mp[xx.second] - 1))/2;
            cout << ans << " ";
        }
        else{
            cout << mp[xx.first] * mp[xx.second] << " ";
        }
    }
    cout << endl;
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