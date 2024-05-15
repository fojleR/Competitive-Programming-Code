#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

ll lcm(ll a, ll b){
    return (a * b)/__gcd(a, b);
}

void solve(){
    ll a, b, q;
    cin >> a >> b >> q;
    ll lm = lcm(a, b);
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--;
        ll dv = l / lm;
        ll mx = max(a, b);
        ll baki = l - dv * lm + 1;
        ll lf = dv * mx + min(baki, mx);
        if(lf >= mx)lf--;
        if(dv == 0){
            lf = min(l, mx - 1);
        }
        dv = r / lm;
        baki = r - dv * lm + 1;
        ll rt = dv * mx + min(baki, mx);
        if(rt >= mx)rt--;
        if(dv == 0){
            rt = min(r, mx - 1);
        }
        ll tot = rt - lf;
        //cout << lf << " " << rt << endl;
        cout << (r - l) - tot << " ";
    }
    cout << endl;

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