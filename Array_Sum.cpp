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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0; i < n; i += 2){
        a[i] = 1;
        k--;
    }

    for(ll i = 1; i < n; i += 2){
        a[i] = 2;
        k -= 2;
    }

    if(k < 0 || k % 2){
        cout << -1 << endl;
        return;
    }

    for(ll i = 0; i < n; i++){
        a[i] += min(k, (ll)99998);
        k -= min(k, (ll)99998);
    }
    if(k){
        cout << -1 << endl;
        return;
    }
    for(ll i = 0; i < n; i++){
        cout << a[i] << " ";
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