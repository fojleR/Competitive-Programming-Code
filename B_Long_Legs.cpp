#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
ll a, b, mm;

// int move(int a, int b, int m) {
//     //cout << a << " " << b << " " << m << endl;
//     if (a == 0 and b == 0) return 0;
//     if (a < 0 || b < 0 || m > max(a, b)) return 1e9;
//     int p = 1 + move(a - m, b, m);
//     int q = 1 + move(a, b - m, m);
//     int r = 1 + move(a, b, m + 1);
//     return min(p, min(q, r));
// }



void solve(){
    cin >> a >> b;
    ll ans = 1e9;
    for(ll i = 1; i <= 100000 + 1; i++){
        ll tm = (a + i - 1)/i + (b + i - 1)/i + (i - 1);
        ans = min(ans, tm);
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