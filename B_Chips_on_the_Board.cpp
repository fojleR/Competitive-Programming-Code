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
    int n;
    cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll ans1 = 0, ans2 = 0;

    ll mn1 = a[0], mn2 = b[0];
    for(int i = 0; i < n; i++){
        mn1 = min(mn1, a[i]);
        mn2 = min(mn2, b[i]);
    }

    for(int i = 0; i < n; i++){
        ans1 += (mn2 + a[i]);
    }

    for(int i = 0; i < n; i++){
        ans2 += (mn1 + b[i]);
    }

    cout << min(ans1, ans2) << endl;
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