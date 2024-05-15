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
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll mn = 0, mx = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] == a[0])mn++;
        if(a[i] == a[n - 1]) mx++;
    }
    cout << a[n - 1] - a[0] << " ";
    if(mn == n){
        cout << (n * (n - 1)) / 2 << endl;
    }
    else{
        cout << mn * mx <<  endl;
    }
}


int main(){
    fast
    ll t = 1;
    //cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}