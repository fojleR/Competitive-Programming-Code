#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n, a, b, nd;
vector< int > lis[mx];
int vis[mx] = {0}, dis[mx] = {0};
bool dfs(int node, int par){
    vis[node] = true;
    for(auto child: lis[node]){
        if(vis[child] and par != child){
            nd = child;
            return true;
        }
        if(!vis[child]){
            if(dfs(child, node)) return true;
        }
    }
    return false;
}

void bfs(int node){
    queue< int > q;
    vis[node] = 1;
    q.push(node);
    dis[node] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: lis[u]){
            if(!vis[v]){
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> a >> b;
    for(int i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = 0, dis[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        lis[x].push_back(y);
        lis[y].push_back(x);
    }
    dfs(b, -1);
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        dis[i] = 0;
    }
    bfs(nd);
    if(dis[b] < dis[a]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
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