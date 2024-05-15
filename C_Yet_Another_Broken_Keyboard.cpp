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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector< char > v;
    for(int i = 0; i < k; i++){
        char x;
        cin >> x;
        v.push_back(x);
    }
    ll ans = 0;
    ll tm = 0;
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int j = 0; j < k; j++){
            if(s[i] == v[j]){
                tm++;
                ok = true;
                break;
            }
        }
        if(!ok){
            ans += (tm * (tm + 1))/2;
            tm = 0;
        }
    }
    if(tm){
        ans += (tm * (tm + 1))/2;
    }
    cout << ans << endl;
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