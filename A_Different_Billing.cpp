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
    ll x, y;
    cin >> x >> y;
    ll n = y / 1000;
    for(int i = 0; i <= n; i++){
        ll fora = i * 1000;
        ll baki = y - fora;
        ll bb = baki / 2500;
        if(baki % 2500 == 0 and i + bb <= x){
            cout <<(x - i - bb) << " " << i << " " << bb << endl;
            return;
        }
    }
    cout << -1 << endl;
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