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
    vector< int > l, r;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        l.push_back(x);
        r.push_back(y + 1);
    }

    vector< pair< int, int > > v;
    for(int i = 0; i < n; i++){
        if(l[i] != 1){
            v.push_back({l[i], 1});
            v.push_back({r[i], - 1});
        }
    }
    int cur = 0, ans = 0;
    sort(v.begin(), v.end());
    for(auto x: v){
        cur += x.second;
        ans = max(ans, cur);
    }
    //cout << ans << endl;
    v.clear();
    for(int i = 0; i < n; i++){
        if(r[i] != m + 1){
            v.push_back({l[i], 1});
            v.push_back({r[i], - 1});
        }
    }
    sort(v.begin(), v.end());
    cur = 0;
    for(auto x: v){

        cur += x.second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    //cout << endl;
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