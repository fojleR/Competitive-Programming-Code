#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n, k;
int a[mx], vis[mx], dis[mx];
vector< int > lis[mx];
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
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        vis[i] = 0, dis[i] = 0;
        lis[i].clear();
    }
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        lis[x].push_back(y);
        lis[y].push_back(x);
    }
    if(k == 1){
        cout << 0 << endl;
        return;
    }
    bfs(1);
    int mxdis = 0, v1;
    for(int i = 0; i < k; i++){
        if(dis[a[i]] > mxdis){
            v1 = a[i];
            mxdis = dis[a[i]];
        }
    }
    for(int i = 0; i <= n; i++){
        vis[i] = 0, dis[i] = 0;
    }
    //cout << mxdis << " " << v1 << endl;
    bfs(v1);
    mxdis = 0;
    int v2;
    for(int i = 0; i < k; i++){
        if(dis[a[i]] > mxdis){
            v2 = a[i];
            mxdis = dis[a[i]];
        }
    }
    cout << (mxdis + 1)/ 2 << endl;
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