#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        sum += x;
    }
    //cout << sum << endl;
    ll a = sum / n;
    ll b = a + 1;
    ll ans = LONG_LONG_MAX;
    //cout << a << " " << b << endl;
    for(ll i = 0; i <= n; i++){
        ll tm = a * i + b * (n - i);
        if(tm == sum){
            ans = min(ans, (i * (n - i)));
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