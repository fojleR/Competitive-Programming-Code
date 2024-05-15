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
    ll a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    ll tot = 0;
    ll c[n];
    for(int i = 0; i < n; i++){
        tot += a[i] * b[i];
        c[i] = a[i] * b[i];
    }
    ll ans = tot;
    for(int i = 0; i < n; i++){
        int x = i - 1, y = i + 1;
        ll tot2 = tot;
        while(1){
            if(x < 0 || y >= n)break;
            tot2 -= (a[x] * b[x] + a[y] * b[y]);
            tot2 += (a[x] * b[y] + a[y] * b[x]);
            // cout << x << " " << y << endl;
            // cout << tot2 << endl;
            ans = max(ans, tot2);
            x--, y++;
        }
        x = i, y = i + 1;
        tot2 = tot;
        while(1){
            if(x < 0 || y >= n)break;
            tot2 -= (a[x] * b[x] + a[y] * b[y]);
            tot2 += (a[x] * b[y] + a[y] * b[x]);
            ans = max(ans, tot2);
            x--, y++;
        }
        ans = max(ans, tot2);
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