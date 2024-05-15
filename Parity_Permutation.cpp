#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

ll fact[mx];

void cal(){
    fact[0] = 1;
    for(int i = 1; i <= 200000; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] = fact[i] % mod;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2){
            odd++;
        }
        else{
            even++;
        }
    }
    if(k == 0 and (even == n || odd == n)){
        cout << fact[n] << endl;
        return;
    }
    else if(k and abs(even - odd) == 1){
        ll ans = (fact[even] * fact[odd]) % mod;
        cout << ans << endl;
    }
    else if(k and abs(even - odd) == 0){
        ll ans = (fact[even] * fact[odd]) % mod;
        ans = (ans * 2) % mod;
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
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