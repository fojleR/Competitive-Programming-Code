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
    ll n, m;
    cin >> n >> m;
    ll mx = n - (m - 1);
    mx = (mx * (mx - 1)) / 2;
    ll per = n / m;
    ll rem = n % m;
    ll mn = (m - rem) * ((per * (per - 1)) / 2);
    mn += rem * (per * (per + 1) / 2);
    cout << mn << " ";
    cout << mx << endl;
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