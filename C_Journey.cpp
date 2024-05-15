#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;


vector< int > lis[mx];
bool vis[mx];
ll dis[mx];
double ans[mx], tot_child[mx];
void dfs(int node){
    double sum = 0;
    int cnt = 0;
    vis[node] = true;
    for(auto child: lis[node]){
        if(!vis[child]){
            tot_child[node]++;
            dfs(child);
            ans[node] += ans[child];
        }
    }
    ans[node] =(tot_child[node] == 0? ans[node] = 0 : 1 + ans[node] / tot_child[node]);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        lis[x].push_back(y);
        lis[y].push_back(x);
    }
    dfs(1);
    cout << setprecision(8);
    cout << ans[1] << endl;

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