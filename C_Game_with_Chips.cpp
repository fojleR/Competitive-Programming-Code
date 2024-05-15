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
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= 2 * k; i++){
        int x, y;
        cin >> x >> y;
    }
    int ans = n + m - 2 + n * m;
    string res;
    for(int i = 0; i < n - 1; i++) res +='U';
    for(int j = 0; j < m - 1; j++) res += 'L';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < m; j++){
            if(i % 2) res += 'R';
            else res += 'L';
        }
        res += 'D';
    }
    cout << ans << endl;
    cout << res << endl;
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