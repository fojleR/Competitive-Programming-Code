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
    ll n, m, k;
    cin >> n >> m >> k;
    ll mx = ((n - 1) * n)/2;
    ll mn = (n - 1);
    //cout << mx << endl;
    if(n == 1 and m == 0 and k >= 2){
        cout << "YES" << endl;
        return;
    }
    int need = 2;
    if(m > mx || m < mn){
        cout << "NO" << endl;
        return;
    }
    else if(m == mx){
        need = 1;
    }
    else{
        need = 2;
    }
    k--;
    if(need < k){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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