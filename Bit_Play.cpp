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
    string s;
    cin >> s;
    ll ans = 1;
    for(int i = 2; i < n; i += 2){
        if(s[i - 1] == '1' and s[i - 2] == '0' and s[i] == '1'){
            ans *= 2;
            ans = ans % mod;
        }
        else if(s[i - 1] == '0' and s[i - 2] == '1' and s[i] == '1'){
            ans *= 2;
            ans = ans % mod;
        }
        else if(s[i] == '0' and s[i - 1] == '0' and s[i - 2] == '0'){
            ans *= 3;
            ans = ans % mod;
        }
        else if(s[i] == '1' and s[i - 1] == '0' and s[i - 2] == '0'){
            ans *= 0;
        }
        else if(s[i] == '1' and s[i - 1] == '1' and s[i - 2] == '1'){
            ans *= 2;
            ans = ans % mod;
        }
    }
    cout << ans << endl;
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