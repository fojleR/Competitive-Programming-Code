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
    map< ll, ll > mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ans += (it->second) * (it->second - 1);
        if(it->first == 1 || it->first == 2){
            ans += mp[1] * mp[2];
        }
    }
    //cout << ans << endl;
    cout << ans / 2 << endl;
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