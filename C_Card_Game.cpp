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
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= 0){
            sum += a[i];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0){
            sum -= a[i];
        }
        ll tm = sum;
        if(i % 2 == 0){
            tm += a[i];
        }
        ans = max(ans, tm);
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