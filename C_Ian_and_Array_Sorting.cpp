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
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = n - 2; i >= 0; i--){
        if(a[i] != a[n - 1]){
            if(i - 1 >= 0){
                ll x = a[n - 1] - a[i];
                a[i] += x;
                a[i - 1] += x;
            }
        }
    }
    // for(ll i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if(a[0] > a[1]){
        if(n % 2 == 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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