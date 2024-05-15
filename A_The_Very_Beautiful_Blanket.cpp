#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int mat[300][300];

void cal(){
    int cur = 0;
    for(int i = 1; i <= 256; i += 2){
        for(int j = 1; j <= 256; j += 2){
            mat[i][j] = cur; cur++;
            mat[i][j + 1] = cur; cur++;
            mat[i + 1][j] = cur; cur++;
            mat[i + 1][j + 1] = cur; cur++;
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    cout << n * m << endl;
    for(int i = 1; i <= n; i++){
        for(int j  = 1; j <= m; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    cal();
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}