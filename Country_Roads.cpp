#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 505;
const int mod = 1e9 + 7;

struct Node{
    int con, wt;
};

int n, m;

void solve(){
    cin >> n >> m;
    Node mat[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            mat[i][j].con = 0;
            mat[i][j].wt = 1e9;
        }
    }
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        mat[x][y].con = 1;
        mat[y][x].con = 1;
        mat[x][y].wt = min(mat[x][y].wt, w);
        mat[y][x].wt = min(mat[y][x].wt, w);
    }
    int st;
    cin >> st;
    int ans[n + 1];
    for(int i = 0; i < n; i++){
        ans[i] = 1e9;
    }
    ans[st] = 0;
    int vis[n + 1] = {0};
    queue< int > q;
    q.push(st);
    while(!q.empty()){
        int par = q.front();
        q.pop();
        vis[par] = 1;
        //cout << par << endl;
        for(int i = 0; i < n; i++){
            int pre = ans[par];
            if(mat[par][i].con){
                // cout << par << " " << i << " " << pre << " ";
                // cout << mat[par][i].wt << endl;
                pre = max(pre, mat[par][i].wt);
                ans[i] = min(ans[i], pre);
                if(vis[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(ans[i] == 1e9){
            cout << "Impossible" << endl;
            continue;
        }
        cout << ans[i] << endl;
    }

}
int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ":" << endl;
        solve();
    }
    return 0;
}