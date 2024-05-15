#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 1004;
const ll mod = 1e9 + 7;
ll n, k;
ll a[mx];

bool check(ll x){
    for(ll i = 0; i < n; i++){
        ll tmx = x, cnt = 0;
        //cout << i << ": " << endl;
        for(ll j = i; j < n; j++){
            ll dif = tmx - a[j];
            if(dif <= 0)break;
            if(j == n - 1 and dif > 0){
                cnt += k + 1;
            }
            cnt += dif;
            //cout << tmx << ": " << dif << endl;
            tmx--;
        }
        if(cnt <= k){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    ll mn = 1e8, mx = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mn = min(mn, (ll)a[i]);
        mx = max(mx, (ll)a[i]);
    }

    ll lo = mn, hi = mx + k;
    ll ans = 0;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(check(mid)){
            lo = mid + 1;
            ans = mid;
        }
        else{
            hi = mid - 1;
        }
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