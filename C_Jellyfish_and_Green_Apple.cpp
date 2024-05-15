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
    ll n, m;
    cin >> n >> m;
    ll g = __gcd(n, m);
    g = m / g;
    int cnt = 0;

    for(int i = 0; i < 32; i++){
        if(g & (1 << i))cnt++;
    }
    if(cnt > 1){
        cout << -1 << endl;
        return;
    }
    n = n % m;

    ll ans = 0;
    while(n){
        ans += n % m;
        n = n % m;
        n *= 2;
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