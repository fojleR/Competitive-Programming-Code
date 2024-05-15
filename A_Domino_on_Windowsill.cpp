#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    char grid[2][n];

    for(int i = 0; i < n; i++){
        if(k1){
            grid[0][i] = 'w';
            k1--;
        }
        else{
            grid[0][i] = 'b';
        }
        if(k2){
            grid[1][i] = 'w';
            k2--;
        }
        else{
            grid[1][i] = 'b';
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << grid[0][i];
    // }
    // cout << endl;
    // for(int j = 0; j < n; j++){
    //     cout << grid[1][j];
    // }
    // cout << endl;

    int w, b;
    cin >> w >> b;

    for(int i = 0; i < n; i++){
        if(grid[0][i] == 'w' and grid[1][i] == 'w' and w){
            grid[0][i] = '#'; grid[1][i] = '#'; w--;
        }
        else if(grid[0][i] == 'w' and grid[0][i + 1] == 'w' and w){
            grid[0][i] = '#'; grid[0][i + 1] = '#'; w--;
        }
        else if(grid[1][i] == 'w' and grid[1][i + 1] == 'w' and w){
            grid[1][i] = '#'; grid[1][i + 1] = '#'; w--;
        }
        if(grid[0][i] == 'b' and grid[1][i] == 'b' and b){
            grid[0][i] = '#'; grid[1][i] = '#'; b--;
        }
        else if(grid[0][i] == 'b' and grid[0][i + 1] == 'b' and b){
            grid[0][i] = '#'; grid[0][i + 1] = '#'; b--;
        }
        else if(grid[1][i] == 'b' and grid[1][i + 1] == 'b' and b){
            grid[1][i] = '#'; grid[1][i + 1] = '#'; b--;
        }
    }
    if(w + b){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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