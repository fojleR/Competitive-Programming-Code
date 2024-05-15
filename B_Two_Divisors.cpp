#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
ll lcm(ll a, ll b){
    return (a * b)/__gcd(a, b);
}

void solve(){
    ll a, b;
    cin >> a >> b;
    ll ans = lcm(a, b);
    // cout << ans << endl;
    if(ans !=  b){
        cout <<  ans << endl;
    }
    else{
        cout << (b / a) * b << endl;
    }
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