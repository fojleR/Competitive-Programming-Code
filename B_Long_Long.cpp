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
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            cnt++;
            while(a[i] <= 0){
                a[i] = abs(a[i]);
                i++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        ans += a[i];
    }
    cout << ans << " " << cnt << endl;

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