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
    ll n;
    cin >> n;
    vector< int > v;
    while(n){
        v.push_back(n % 9);
        n /= 9;
    }
    reverse(v.begin(), v.end());

    ll ans = 0;

    for(int i = 0; i < v.size(); i++){
        ans *= 10;
        ans += (v[i] > 3 ? v[i] + 1 : v[i]);
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