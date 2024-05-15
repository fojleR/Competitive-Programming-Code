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
    ll n, m;
    cin >> n >> m;
    vector< int > v;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){
        ll x = a[i];
        bool ok = true;
        //cout << a[i] << ":";
        for(int k = 0; k < 32; k++){
            int tm = (1<<k);
            int bit1 = 0, bit2 = 0;
            //cout << (tm & x) << endl;
            if(tm & x) bit1 = 1;
            if(tm & m) bit2 = 1;
            //cout << bit1 << " " << bit2 << endl;
            if(bit1 == 1 and bit2 == 0){
                ok = false;
                break;
            }
        }
        if(!ok){
            break;
        }
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        ll x = b[i];
        bool ok = true;
        for(int k = 0; k < 32; k++){
            int tm = (1<<k);
            int bit1 = 0, bit2 = 0;
            if(tm & x) bit1 = 1;
            if(tm & m) bit2 = 1;
            if(bit1 == 1 and bit2 == 0){
                ok = false;
                break;
            }
        }
        if(!ok){
            break;
        }
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        ll x = c[i];
        bool ok = true;
        for(int k = 0; k < 32; k++){
            int tm = (1<<k);
            int bit1 = 0, bit2 = 0;
            if(tm & x) bit1 = 1;
            if(tm & m) bit2 = 1;
            if(bit1 == 1 and bit2 == 0){
                ok = false;
                break;
            }
        }
        if(!ok){
            break;
        }
        v.push_back(x);
    }
    ll nw = 0;
    for(auto x: v){
        nw = (nw | x);
    }
    if(nw == m){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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