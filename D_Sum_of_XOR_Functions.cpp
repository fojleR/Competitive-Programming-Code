#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 998244353;

void solve(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i = 0; i <= 30; i++){
        ll cntodd = 0;
        ll cnteven = 0;
        ll totodd = 0;
        ll toteven = 0;

        for(ll j = 0; j < n; j++){
            if((a[j] & (1LL << i)) > 0){
                // cout << (a[j] & (1LL << i)) << endl;
                swap(cntodd, cnteven);
                swap(totodd, toteven);
                cntodd++;
                totodd += j;
            }
            else{
                cnteven++;
                toteven += j;
            }
            (ans += (1ll << i) * 1ll * ((((j + 1) * 1ll * cntodd - totodd + mod) % mod))) %= mod;
            //cout << i << " " << j << " " << cntodd << " " << totodd << " " << ans << endl;
        }
    }
    cout << ans << endl;
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