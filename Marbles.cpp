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
    int a, b;
    cin >> a >> b;
    int ans = 100000;
    int tmb = b;
    int tma = a;
    for(int i = 0; i < a; i++){
        tma = a - i;
        tmb = b + i;
        if(tma % tmb == 0){
            ans = min(ans, i);
            break;
        }
    }
    tmb = b;
    tma = a;
    for(int i = 0; i < b; i++){
        tma = a + i;
        tmb = b - i;
        if(tma % tmb == 0){
            ans = min(ans, i);
            break;
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