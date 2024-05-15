#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;
ll n, k;
ll a[mx];
ll dp[mx][66][2];

ll subsegment(ll pos, ll AND, ll empty){
    // cout << pos << " " << AND << " " << empty << endl;
    if(pos >= n){
        if(empty)return 0;
        // cout << "###" << endl;
        if(__builtin_popcount(AND) == k)return 1;
        else return 0;
    }
    if(dp[pos][AND][empty] != -1){
        // cout << "***" << endl;
        return dp[pos][AND][empty];
    }
    if(empty){
        // cout << "***" << endl;
        return dp[pos][AND][empty] = (subsegment(pos + 1,a[pos],0) % mod + subsegment(pos + 1, AND, 1) )% mod;
    }
    else{
        return dp[pos][AND][empty] = (subsegment(pos + 1, a[pos] & AND, 0) % mod + subsegment(pos + 1, AND, 0)) % mod;
    }
}

void solve(){
    cin >> n >> k;
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j < 65; j++){
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = subsegment(0, 0, 1);
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