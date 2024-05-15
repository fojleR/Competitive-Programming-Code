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
    int a[n][n], dp[n][n];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = s[j] - '0';
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 < n and j - 1 >= 0){
                dp[i + 1][j - 1] ^= dp[i][j];
            }
            if(i + 1 < n and j + 1 <= n){
                dp[i + 1][j + 1] ^= dp[i][j];
            }
        }
        for(int j = 0; j < n; j++){
            if(j) dp[i][j] ^= dp[i][j - 1];
            cout << dp[i][j] << " ";
            if(dp[i][j] != a[i][j]){
                ans++;
                if(i + 1 < n and j - 1 >= 0){
                    dp[i + 1][j - 1] ^= 1;
                }
                if(i + 1 < n and j + 2 <= n){
                    dp[i + 1][j + 2] ^= 1;
                }
            }
            // cout << dp[i][j] << " ";
        }
        cout << endl;
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