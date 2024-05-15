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
    ll n , m, k;
    cin >> n >> m >> k;
    ll res = m / n + (n - 1);
    if(m == 0){
        if(k == 1){
            cout << 1 << endl;
            return;
        }
        else{
            cout << 0 << endl;
            return;
        }
    }
    if(k == 1){
        cout << 1 << endl;
        return;
    }
    else if(k == 2){
        cout << min(m,max(1LL*0, res)) << endl;
    }
    else if(k == 3){
        cout <<min(m, max(1LL*0,m - res)) << endl;
    }
    else{
        cout << 0 << endl;
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