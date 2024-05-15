#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

ll kadane(vector< ll > v){
    ll sum = 0;
    ll ans = 0;
    for(auto x: v){
        sum += x;
        ans = max(sum, ans);
        sum = max(1LL*0, sum);
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i = 0; i < n; i += 2){
        ans += a[i];
    }
    //cout << ans << endl;
    vector< ll > dif;
    for(ll i = 0; i < n; i += 2){
        if(i + 1 < n){
            dif.push_back(a[i + 1] - a[i]);
        }
    }
    ll xx = kadane(dif);
    dif.clear();

    for(ll i = 1; i < n; i += 2){
        if(i + 1 < n){
            dif.push_back(a[i] - a[i + 1]);
        }
    }
    ll yy = kadane(dif);
    xx = max(xx, yy);
    cout << max(ans, ans + xx) << endl;
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