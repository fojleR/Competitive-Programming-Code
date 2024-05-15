#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

ll n, k, c;
vector< ll > lis[mx];
ll vis[mx], dis[mx];
ll u, mxdis = 0;
ll ans = 0;
ll tc = 0;

void dfs(ll node){
    vis[node] = true;
    // cout << node << endl;
    for(auto child: lis[node]){
        // cout << child <<" ";
        if(!vis[child]){
            dis[child] = dis[node] + 1; 
            if(dis[child] > mxdis){
                mxdis = dis[child];
                u = child;
            }
            dfs(child);
        }
    }
}
void dfs2(ll node){
    vis[node] = true;
    for(auto child: lis[node]){
        if(!vis[child]){
            dis[child] = dis[node] + k - tc; 
            if(child == 1) tc = c;
            ans = max(ans, dis[child]);
            dfs2(child);
        }
    }
}

void solve(){
    cin >> n >> k >> c;
    for(ll i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = 0;
        dis[i] = 0;
    }
    for(ll i = 1; i < n; i++){
        ll x, y;
        cin >> x >> y;
        lis[x].push_back(y);
        lis[y].push_back(x);
    }
    mxdis = 0;
    dfs(1);
    
    //cout << "#" << u << endl;
    ans = 0;
    tc = 0;
    for(ll i = 0; i <= n; i++){
        dis[i] = 0;
        vis[i] = 0;
    }
    // for(auto x: lis[4]){
    //     cout << x << " ";
    // }
    //  cout << endl;
    dfs2(u);
    cout << ans << endl;
    // for(ll i = 1; i <= n; i++){
    //     cout << i << " " << dis[i] << endl;
    // }
    // cout << endl << endl;
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