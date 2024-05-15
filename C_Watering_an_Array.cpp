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
    ll n, k, d;
    cin >> n >> k >> d;
    ll mxi = max(n, k);
    ll a[n + 1], b[k + 1], bb[mxi + 2];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++){
        cin >> b[i];
    }
    ll ans = 0;
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == i)cnt++;
    }
    for(int i = 1; i <= mxi; i++){
        bb[i] = b[(i - 1) % k + 1];
    }
    // for(int i = 1; i <= n; i++){
    //     cout << bb[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= min(k, d); i++){
        ll tm = cnt + (d - i)/2;
        ans = max(ans, tm);
        // cout << cnt << " " << tm << endl;
        for(int j = 1; j <= bb[i]; j++){
            if(a[j] == j)cnt--;
            a[j]++;
            if(a[j] == j)cnt++;
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