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
    int n, q;
    cin >> n >> q;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(q--){
        ll k, ans = 0;
        cin >> k;
        ll p[n];
        for(int i = 0; i < n; i++){
            p[i] = a[i];
        }
        for(int i = 60; i >= 0; i--){
            ll x = (1LL << i) - 1;
            ll sum = 0;
            for(int j = 0; j < n; j++){
                if((1LL << i) & p[j])continue;
                ll vl = (1LL << i) - (p[j] & x);
                sum += vl;
                if(sum > k){
                    break;
                }
            }
            if(sum > k)continue;
            for(int j = 0; j < n; j++){
                if((1LL << i) & p[j])continue;
                p[j] = (1LL << i);
            }
            ans += (1LL << i);
            k -= sum;
        }
        cout << ans << endl;
    }
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