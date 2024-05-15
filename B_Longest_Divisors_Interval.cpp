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
    ll tot = min(1LL*1000, n);
    int mx = 0;
    int tm = 0;
    for(int i = 1; i <= tot; i++){
        //cout << i << " " << n % i << endl;
        if(n % i == 0)tm++;
        else tm = 0;
        mx = max(mx, tm);
    }
    cout << mx << endl;;
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