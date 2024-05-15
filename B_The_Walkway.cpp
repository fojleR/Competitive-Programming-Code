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
    ll n, m, d;
    cin >> n >> m >> d;
    vector< ll > v;
    for(int i = 0; i < m; i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    ll ans = 0;
    v.push_back(-d + 1);
    v.push_back(n + 1);
    sort(v.begin(), v.end());
    ans += m;

    for(int i = 1; i <= m + 1; i++){
        ans += (v[i] - v[i - 1] - 1)/d;
    }

    ll res = 1e9;
    int ind;
    for(int i = 1; i <= m; i++){
        ll aans = ans - (v[i] - v[i - 1] - 1)/d - (v[i + 1] - v[i] - 1)/d + (v[i + 1] - v[i - 1] - 1)/d - 1;
        if(aans < res){
            ind = i;
            res = aans;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        ll aans = ans - (v[i] - v[i - 1] - 1)/d - (v[i + 1] - v[i] - 1)/d + (v[i + 1] - v[i - 1] - 1)/d - 1;
        if(aans == res) cnt++;
    }

    cout << res << " " << cnt << endl;
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