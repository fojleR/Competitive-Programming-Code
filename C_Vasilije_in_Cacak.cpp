#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll sum[mx];

void cal(){
    for(ll i = 1; i <= 200000; i++){
        sum[i] = sum[i - 1];
        sum[i] += i;
    }
}

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    ll mn = sum[k];
    ll mx = sum[n] - sum[n - k];
    if(x >= mn && x <= mx){
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
    cal();
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}