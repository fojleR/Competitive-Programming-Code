#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

vector< ll > dp;
vector< bool > used;
vector< vector< ll > > sl;

ll get(ll v){
    if(used[v]){
        return dp[v];
    }

    used[v] = true;

    ll s = 0;
    for(ll u: sl[v]){
        s += get(u);
    }

    if(!sl[v].empty()) dp[v] = min(dp[v], s);
    return dp[v];
}

void solve(){
    ll n, k;
    cin >> n >> k;
    dp.resize(n);
    sl.assign(n, vector<ll>(0));
    used.assign(n, false);
    for(auto &e: dp){
        cin >> e;
    }
    for(ll i = 0; i < k; i++){
        ll e;
        cin >> e;
        dp[--e] = 0;
    }

    for(ll i = 0; i < n; i++){
        ll m;
        cin >> m;
        //cout << m << endl;
        sl[i].resize(m);
        for(auto &e: sl[i]){
            cin >> e;
            e--;
        }
    }

    for(ll i = 0; i < n; i++){
        cout << get(i) << " ";
    }
    cout << endl;
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