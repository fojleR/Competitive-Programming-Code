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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(k == 1){
        cout << s << endl;
        return;
    }
    string ans;
    ans += s[0];
    if(s[k - 1] != s[0]){
        cout << s[k - 1] << endl;
        return;
    }
    if(k < n and s[k] == s[n - 1]){
        ll tot = n - k;
        ll now = tot / k;
        for(ll i = 0; i < now; i++){
            ans += s[k];
        }
        if(tot % k){
            ans += s[k];
        }
        cout << ans << endl;
    }
    else{
        for(ll i = k; i < n; i++){
            ans += s[i];
        }
        cout << ans << endl;
    }
}


ll main(){
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