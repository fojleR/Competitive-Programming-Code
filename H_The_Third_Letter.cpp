#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

ll n, m;
vector< pair< ll, ll > > lis[mx];
ll vis[mx], dis[mx];
ll flag = 0;

void dfs(ll node){
    vis[node] = true;
    for(auto child: lis[node]){
        if(!vis[child.first]){
            dis[child.first] = dis[node] + child.second;
            dfs(child.first);
        }
        else{
            if(dis[child.first] != dis[node] + child.second)flag = 1;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(ll i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = dis[i] = 0;
    }
    for(ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        lis[u].push_back({v, -w});
        lis[v].push_back({u, w});
    }
    flag = 0;
    for(ll i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }

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