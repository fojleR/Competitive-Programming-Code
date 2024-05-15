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
    int n, W, ans = 0;
    cin >> n;
    int w[n], p[n];
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++) cin >> p[i];
    cin >> W;
    vector< pair< int, int > > p_w;
    for(int i = 0; i < n; i++){
        p_w.push_back({p[i]/w[i], i});
    }
    sort(p_w.begin(), p_w.end());
    reverse(p_w.begin(), p_w.end());
    for(int i = 0; i < n; i++){
        ans += min(W, w[p_w[i].second]) * p_w[i].first;
        W -= min(W, w[p_w[i].second]);
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