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
    ll a[n];
    map< ll, int > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    int mex = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->first == mex) mex++;
    }
    ll ans = 1e9 * 50000;
    sort(a, a + n);

    for(int i = 0; i < n; i++){
        ll tm = (mp[a[i]] - 1) * mex + i * a[i];
        ans = min(ans, tm);
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