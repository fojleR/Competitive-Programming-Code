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
    ll q;
    cin >> q;
    ll mx = 1e18, mn = 1;
    while(q--){
        ll ch;
        cin >> ch;
        if(ch == 1){
            ll a, b, n;
            cin >> a >> b >> n;
            ll tmn = (n - 2) * (a - b) + a + 1;
            ll tmx = (n - 1) * (a - b) + a;
            if(n == 1) tmn = 1, tmx = a;
            if(mn == -1){
                cout << 1 << " ";
                mn = tmn;
                mx = tmx;
            }
            else{
                if(tmx < mn || tmn > mx){
                    cout << 0 << " ";
                }
                else{
                    cout << 1 << " ";
                    mx = min(mx, tmx);
                    mn = max(mn, tmn);
                }
            }
        }
        else{
            ll a, b;
            cin >> a >> b;
            ll ans1 = max(1LL, ((mn - b - 1)/(a - b) + 1));
            ll ans2 = max(1LL, ((mx - b - 1)/(a - b) + 1));
            if(ans1 == ans2){
                cout << ans1 << ' ';
            }
            else{
                cout << -1 << " ";
            }
        }
    }
    cout << endl;
    //cout << mx << " " << mn << endl;
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