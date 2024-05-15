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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr ^ a[i];
    }
    sort(b, b + n);
    reverse(b, b + n);
    //cout << xr << endl;
    int mx = xr, mn = xr;
    for(int i = 0; i < m; i++){
        mx = max(mx, mx ^ b[i]);
        mn = min(mn, mn ^ b[i]);
    }
    cout << mn << " " << mx << endl;
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