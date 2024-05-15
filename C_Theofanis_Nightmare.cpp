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
    int ind = n;
    int track[n];
    track[n - 1] = n;
    ll sum = 0;
    for(int i = n - 1; i >= 0; i--){
        track[i] = ind;
        sum += a[i];
        if(sum >= 0)ind--;
    }
    for(int i = n - 1; i >= 0; i--){
        track[i] = track[i] - track[0] + 1;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += track[i] * a[i];
    }
    cout << ans << endl;
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