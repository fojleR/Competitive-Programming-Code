#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll n, x;
ll a[mx];

bool check(ll h){
    ll tot = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < h){
            tot += h - a[i];
        }
    }

    if(tot <= x){
        return true;
    }
    else{
        return false;
    }
}

void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll lo = 1, hi = 1e10 + 3;

    ll ans = 1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}