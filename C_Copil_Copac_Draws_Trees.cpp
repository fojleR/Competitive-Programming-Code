#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

vector< pair< int, int > > lis[mx];
int dp[mx], id[mx];

void dfs(int node){
    for(auto child: lis[node]){
        if(dp[child.first] == 0){
            dp[child.first] = dp[node] + (child.second < id[node]);
            id[child.first] = child.second;
            dfs(child.first);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        lis[i].clear();
        dp[i] = 0;
        id[i] = 0;
    }

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        lis[x].push_back({y, i});
        lis[y].push_back({x, i});
    }

    dp[1] = 1;
    id[1] = 0;

    dfs(1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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