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
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 0; i < n; i++){
        cin >> a[i + 1];
    }
    int dp[n + 1][2];
    for(int i = 0; i <= n; i++){
        dp[i][0] = dp[i][1] = 0;
    }
    int pos[n + 1];
    for(int i = 0; i <= n; i++){
        pos[i] = -1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(pos[a[i]] != -1){
            int lst = pos[a[i]];
            int a = i - lst + 1 + max(dp[lst - 1][0], dp[lst - 1][1]);
            int b = i - lst + dp[lst][1];
            dp[i][1] = max(a, b);
        }
        pos[a[i]] = i;
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    // for(int i = 1; i <= n; i++){
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }
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