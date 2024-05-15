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
    ll n, k , g;
    cin >> n >> k >> g;
    ll tot = k * g;
    ll ans = 0;
    ll md = (g + 1)/2 - 1;
    ans = md * n;
    if(ans >= tot){
        cout << tot << endl;
        return;
    }
    else{
        ll baki = tot - (md * (n - 1));
        ll ans2 = md * (n - 1);
        ll mood = baki % g;
        if(mood >= (g + 1)/ 2){
            cout << tot - (baki + (g - mood)) << endl;
        }
        else{
            cout << ans2 + mood << endl;
        }
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