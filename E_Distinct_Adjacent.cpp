#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 998244353;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans = m;
    for(int i = 1; i <= n - 2; i++){
        ans = (ans * (m - 1)) % mod;
    }
    if(m - 2){
        if(n % 2)
            ans = (ans * (m - 2)) % mod;
        else ans = (ans * (m - 1)) % mod;
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