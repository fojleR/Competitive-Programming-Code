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
    ll x = (int)(ceil(sqrt(2 * n)));
    ll y = x + 1;
    x--, y--;
    ll tot = (y * (y - 1))/2;
    //cout << tot << endl;
    ll tot2 = (x * (x - 1))/2;

    if(tot > n){
        //cout << x << endl;
        //cout << x * (x - 1) << endl;
        cout << x + (n - tot2) << endl;
        return;
    }

    cout << y + (n - tot) << endl;
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