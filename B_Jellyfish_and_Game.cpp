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
    int n, m, k;
    cin >> n >> m >> k;
    multiset< ll > st1, st2;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        st1.insert(x);
    }
    for(int i = 0; i < m; i++){
        ll x;
        cin >> x;
        st2.insert(x);
    }

    int move = min(100, k);

    for(int i = 1; i <= move; i++){
        k--;
        if(i % 2 == 1){
            auto it = st1.begin();
            ll x = *it;
            st1.erase(it);
            it = st2.end();
            it--;
            ll y = *it;
            st2.erase(it);
            ll a = max(x, y);
            ll b = min(x, y);
            st1.insert(a);
            st2.insert(b);
        }
        else{
            auto it = st2.begin();
            ll x = *it;
            st2.erase(it);
            it = st1.end();
            it--;
            ll y = *it;
            st1.erase(it);
            ll a = max(x, y);
            ll b = min(x, y);
            st2.insert(a);
            st1.insert(b);
        }
    }
    if(!k){
        ll ans = 0;
        for(auto it = st1.begin(); it != st1.end(); it++){
            ans += *it;
        }
        cout << ans << endl;
        return;
    }
    else{
        if(k % 2 == 0){
            ll ans = 0;
            for(auto it = st1.begin(); it != st1.end(); it++){
                ans += *it;
            }
            cout << ans << endl;
            return;
        }
        else{
            ll ans = 0;
            ll mn = 1e9 + 1;
            for(auto it = st1.begin(); it != st1.end(); it++){
                ans += *it;
                mn = min(mn, *it);
            }
            ll mx = 0;
            for(auto it = st2.begin(); it != st2.end(); it++){
                mx = max(mx, *it);
            }
            ans = ans - mn + mx;
            cout << ans << endl;
            return;
        }
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