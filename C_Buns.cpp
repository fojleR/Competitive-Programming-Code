#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 1001;
const int mod = 1e9 + 7;

struct bun{
    int a, b, c, d, e;
};

int dp[11][mx];
vector< bun > v;
int n, m, a0, c0;

int cal(int pos, int tot){
    //cout << pos << " " << tot << endl;
    if(pos >= m || tot <= 0){
        return 0;
    }
    if(dp[pos][tot] != -1){
        return dp[pos][tot];
    }
    int mn = min(tot / v[pos].c, v[pos].a / v[pos].b);
    for(int i = 0; i <= mn; i++){
        dp[pos][tot] =max(dp[pos][tot], i * v[pos].d + cal(pos + 1, tot - i * v[pos].c)); 
    }
    return dp[pos][tot];
}

void solve(){
    cin >> n >> m >> a0 >> c0;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int e = a / b;
        bun x;
        x.a = a, x.b = b, x.c = c, x.d = d, x.e =e;
        v.push_back(x);
    }
    int ans = cal(0, n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0;  j <= n; j++){
            int tot = dp[i][j] + ((n - j)/a0) * c0;
            ans = max(ans, tot);
        }
    }
    cout << ans << endl;
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