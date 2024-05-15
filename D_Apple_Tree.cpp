#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

vector< ll > lis[mx];
bool vis[mx];
ll tc[mx];
void dfs(ll node){
    vis[node] = true;
    ll tot = 0;
    for(auto child: lis[node]){
        if(!vis[child]){
            dfs(child);
            tot += tc[child];
        }
    }
    tc[node] = max(tc[node], tot);
}

void solve(){
    ll n;
    cin >> n;
    for(ll i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = 0;
        tc[i] = 1;
    }
    for(ll i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        lis[x].push_back(y);
        lis[y].push_back(x);
    }
    dfs(1);
    // for(ll i = 1; i <= n; i++){
    //     cout << tc[i] << " ";
    // }
    // cout << endl;
    ll q;
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        cout << tc[x] * tc[y] << endl;
    }
    // for(ll i = 0; i <= n; i++){
    //     if(lis[i].size() == 1){
    //         child[i] = 1;
    //     }
    // }
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