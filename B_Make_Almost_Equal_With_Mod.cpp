#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    bool odd = false, even = false;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2)odd = 1;
        else even = 1;
    }
    if(odd and even){
        cout << 2 << endl;
        return;
    }
    ll gd = a[0];
    for(int i = 0; i < n; i++){
        gd = __gcd(a[i], gd);
    }

    while(1){
        set< int > st;
        for(int i = 0; i < n; i++){
            st.insert(a[i] % gd);
        }
        if(st.size() == 2){
            cout << gd << endl;
            return;
        }
        gd++;
    }

}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}