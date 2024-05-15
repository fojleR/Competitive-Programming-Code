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
    ll a[n], b[n], c[n];
    multiset< ll > sta, stb;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        stb.insert(b[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    ll dis[n];
    for(int i = n - 1; i >= 0; i--){
        auto it = stb.upper_bound(a[i]);
        b[i] = *it;
        //cout << *it << endl;
        stb.erase(b[i]);
    }
    for(int i = 0; i < n; i++){
        dis[i] = b[i] - a[i];
    }
    sort(dis, dis + n);
    reverse(dis, dis + n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += dis[i] * c[i];
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