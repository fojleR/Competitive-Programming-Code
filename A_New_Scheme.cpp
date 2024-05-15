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
    int a[8];
    for(int i = 0; i < 8; i++){
        cin >> a[i];
    }
    for(int i = 1; i < 8; i++){
        if(a[i - 1] > a[i]){
            cout << "No" << endl;
            return;
        }
    }
    for(int i = 0; i < 8; i++){
        if(a[i] % 25){
            cout << "No" << endl;
            return;
        }
        if(a[i] < 100 || a[i] > 675){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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