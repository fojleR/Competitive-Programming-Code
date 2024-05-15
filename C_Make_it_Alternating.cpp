#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 998244353;
ll fact[mx];
void cal(){
    fact[0] = 1;
    for(int i = 1; i <= 200000; i++) fact[i] = (fact[i - 1] * i) % mod;
}

void solve(){
    int n;
    string s;
    cin >> s;
    n = s.size();
    ll ans = 1;
    ll tot = 0;
    int tm = 1;

    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]){
            tm++;
            continue;
        }
        tot += tm - 1;
        ans *= tm;
        ans %= mod;
        tm = 1;
    }

    tot += tm - 1;
    ans *= tm;
    ans %= mod;
    ans = (ans * fact[tot]) % mod;


    cout << tot << " " << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    cal();
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}