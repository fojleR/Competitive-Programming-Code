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
    ll m[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
    vector< ll > v;
    for(int i = 0; i < n; i++){
        ll tm = (1 << 30);
        tm--;
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            tm = tm & m[i][j];
        }
        v.push_back(tm);
    }
    for(auto x: v){
        cout << x << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j and v[i]|v[j] != m[i][j]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(auto x: v){
        cout << x << " ";
    }
    cout << endl;
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