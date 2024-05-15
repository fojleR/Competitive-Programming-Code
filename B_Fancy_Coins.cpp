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
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    ll div = m / k;
    m -= min(ak, div) * k; 
    m -= min(m, a1);
    //cout << m << endl;
    ll ans1 = m / k + m % k;
    ll ans2 = m;
    ll mod = m % k;
    ll rem = k - mod;
    if(rem <= a1){
        ans2 = m / k + 1;
    }
    cout << min(ans1, ans2) << endl;
    //cout << ans << endl;
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