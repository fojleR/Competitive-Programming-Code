#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll dp[31][31];

ll path(int x, int y){
    if(x <= 0 || y <= 0)return 0;
    if(x == 1 and y == 1){
        return dp[x][y] = 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    ll p = path(x, y - 1);
    ll q = path(x - 1, y);
    return dp[x][y] = p + q;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            dp[i][j] = -1;
        }
    }
    ll xx = path(30, 30);
    int lx, ly;
    int x = 1, y = 1;
    while(dp[x][y] < n){
        x++, y++;
    }
    lx = x, ly = y;
    int dif = dp[lx][ly] - n;
    //cout << lx << " " << ly << endl;
    // for(int i = 1; i <= ly; i++){
    //     for(int j = 1; j <= lx; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    map< ll, pair< int, int > > mp;
    for(int i = 1; i <= lx; i++){
        for(int j = 1;  j <= lx; j++){
            mp[dp[i][j]] = {i, j};
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    vector< int > v;
    for(auto it : mp){
        v.push_back(it.first);
    }
    sort(v.begin(), v.end());
    // for(auto x: v){
    //     cout << x << " ";
    // }
    // int ind = upper_bound(v.begin(), v.end(), dif) - v.begin();
    // ind--;
    //cout << ind << endl;
    while(dif > 0){
        int ind = upper_bound(v.begin(), v.end(), dif) - v.begin();
        ind--;
        ll xx = v[ind];
        dp[mp[xx].first][mp[xx].second] = 0;
        //cout <<  << " "<<  << endl;
        dif -= xx;
    }
    cout << lx << endl;
    for(int i = 1; i <= lx; i++){
        for(int j = 1; j <= lx; j++){
            cout << (dp[i][j] ? 1 : 0) << " ";
        }
        cout << endl;
    }
    //cout << dif << endl;

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