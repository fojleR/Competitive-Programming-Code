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
    ll n, m, h;
    cin >> n >> m >> h;
    ll a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        b[i] = b[i] * h;
    }
    sort(a, a + n);
    reverse(a, a + n);
    sort(b, b + m);
    reverse(b, b + m);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i < m){
            ans += min(a[i], b[i]);
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