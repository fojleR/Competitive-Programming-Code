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
    int n, k;
    cin >> n >> k;
    ll a[n], b[n], premx[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    premx[0] = b[0];
    for(int i = 1; i < n; i++){
        premx[i] = max(b[i], premx[i - 1]);
    }
    ll ans = 0;
    ll sum = 0;

    for(int i = 0; i < min(n, k); i++){
        sum += a[i];
        int bk = k - i - 1;
        ll tm = sum + premx[i] * bk;
        ans = max(ans, tm);
    }
    cout << ans << endl;
    // for(int i = 0; i < n; i++){
    //     cout << premx[i] << " ";
    // }
    // cout << endl;
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