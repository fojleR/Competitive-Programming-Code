#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll n, k;

bool check(ll x){
    ll sum = x;
    ll xx = k;
    while(x / xx > 0){
        sum += x / xx;
        xx *= k;
    }
    //cout << sum << endl;
    return sum >= n;
}

void solve(){
    cin >> n >> k;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    ll lo = 2, hi = n;
    ll ans = 2;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
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