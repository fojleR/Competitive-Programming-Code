#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
int s, m, l;
ll dp[mx];
ll egg(int n){
    if(n <= 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    ll p = s + egg(n - 6);
    ll q = m + egg(n - 8);
    ll r = l + egg(n - 12);
    return dp[n] = min(p, min(q, r));
}

void solve(){
    int n;
    cin >> n >> s >> m >> l;
    for(int i = 0; i <= n; i++) dp[i] = -1;
    cout << egg(n) << endl;
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