#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
int h, w;
char mat[501][501];

map< pair< int, int >,vector< pair< int, int > > > lis;
map< char, char > mp;

bool vis[501][501];

void dfs(pair< int, int > node){
    vis[node.first][node.second] = true;
    for(auto child: lis[node]){
        if(!vis[child.first][child.second] and mp[mat[child.first][child.second]]== mat[node.first][node.second]){
            //cout << child.first << " " << child.second << endl;
            dfs(child);
        }
    }
}

void solve(){
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> mat[i][j];
        }
    }
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(j < w)
                lis[{i, j}].push_back({i, j + 1});
            if(i < h)
                lis[{i, j}].push_back({i + 1, j});
            if(i != 1){
                lis[{i, j}].push_back({i - 1, j});
            }
            if(j != 1){
                lis[{i, j}].push_back({i, j - 1});
            }
        }
    }
    
    mp['s'] = 'e';
    mp['n'] = 's';
    mp['u'] = 'n';
    mp['k'] = 'u';
    mp['e'] = 'k';

    dfs({1,1});

    cout << (vis[h][w] ? "Yes": "No") << endl;
    // for(int i = 1; i <= h; i++){
    //     for(int j = 1; j <= w; j++){
    //         cout << i << " " << j << ": ";
    //         for(auto x: lis[{i, j}]){
    //             cout << x.first << " " << x.second << endl;
    //         }
    //     }
    //     cout << endl;
    // }
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