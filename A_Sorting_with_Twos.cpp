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
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int tm = 0;
    while(1){
        int tt = pow(2, tm);
        //cout << tt << endl;
        if(tt > n){
            cout << "YES" << endl;
            return;
        }
        // for(int i = 0; i < n; i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        if(tt == 1){
            a[0] = 0;
            tm++;
            continue;
        }
        for(int i = 1; i < tt; i++){
            if(a[i - 1] > a[i]){
                cout << "NO" << endl;
                return;
            }
        }

        for(int i = 1; i < tt; i++){
            a[i] = 0;
        }
        //cout << endl;
        tm++;
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