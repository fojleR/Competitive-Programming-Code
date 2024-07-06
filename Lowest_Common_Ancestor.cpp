#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 10003;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

vector< int > lis[mx];
int depth[mx];
int parent[mx][20];
bool vis[mx];

void dfs(int node){
    vis[node] = true;
    for(auto child: lis[node]){
        if(!vis[child]){
            depth[child] = depth[node] + 1;
            parent[child][0] = node;
            dfs(child);
        }
    }
}

int getLCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < 20; i++){
        if(diff & (1 << i)){
            u = parent[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            lis[i].pb(x);
            lis[x].pb(i);
        }
    }
    int q;
    cin >> q;
    dfs(0);
    parent[0][0] = 0;
    for(int j = 1; j < 20; j++){
        for(int i = 0; i < n; i++){
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << getLCA(u, v) << '\n';

    }
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