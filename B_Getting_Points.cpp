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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll h_day = n / 7;
    if(n % 7)h_day++;
    ll dh_day = h_day / 2;
    ll mx = t * 2 + l;
    ll tot = dh_day * (t * 2 + l);
    if(tot >= p){
        cout << n - min(dh_day, (p + mx - 1)/ mx) << endl;;
        return;
    }
    if(h_day % 2){
        tot += t + l;
        dh_day++;
    }
    if(tot >= p){
        cout << n - dh_day << endl;
        return;
    }
    ll rm = p - tot;
    cout <<n - (dh_day + (rm + l - 1)/l) << endl;
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