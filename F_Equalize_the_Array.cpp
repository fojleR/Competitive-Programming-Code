#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n];
    map< int, int > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector< int > v;
    for(auto x: mp){
        v.push_back(x.second);
    }
    sort(v.begin(), v.end());
    int ans = n;
    for(int i = 0; i < v.size(); i++){
        int element = v.size() - i;
        int tot = n - element * v[i];
        ans = min(ans, tot);
    }
    cout << ans << endl;
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}