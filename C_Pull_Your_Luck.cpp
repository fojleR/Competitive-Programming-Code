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
    ll n, x, p;
    cin >> n >> x >> p;
    ll tot = -((n - x) % n);
    
    for(int i = 1; i <= min(2 * n, p); i++){
        tot += i;
        if(tot % n == 0){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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