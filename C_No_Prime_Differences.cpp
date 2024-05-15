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
    int n, m;
    cin >> n >> m;
    int ans[n + 1][m + 1];
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cnt++;
            ans[i][j] = cnt;
        }
    }
    for(int i = 1; i <= n; i += 2){
        for(int j = 1; j <= m;  j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 2; i <= n; i += 2){
        for(int j = 1; j <= m;  j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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