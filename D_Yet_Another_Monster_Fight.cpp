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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll pref[n], suf[n];
    for(int i = 0; i < n; i++){
        pref[i] = a[i] + (n - i - 1);
        suf[i] = a[i] + i;
    }

    // for(int i = 0; i < n; i++){
    //     cout << pref[i] << " " << suf[i] << endl;
    // }
    for(int i = 1; i < n; i++){
        pref[i] = max(pref[i], pref[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--){
        suf[i] = max(suf[i], suf[i + 1]);
    }

    ll ans = 2e9;
    for(int i = 0; i < n; i++){
        ll cur = a[i];
        if(i > 0){
            cur = max(cur, pref[i - 1]);
        }
        if(i < n - 1){
            cur = max(cur, suf[i + 1]);
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
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