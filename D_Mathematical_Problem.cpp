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
    ll n;
    cin >> n;
    ll cnt = n;
    if(cnt == 1){
        cout << 1 << endl;
        return;
    }
    cout << "196" + string(n - 3, '0') << endl;
    cnt--;
    for(int dist = 0; dist * 2 + 3 <= n; dist++){
        if(cnt){
            cnt--;
            cout << "1" + string(dist, '0') + "6" + string(dist, '0') + "9" + string(n - dist * 2 - 3, '0') << endl;
        }
        if(cnt){
            cnt--;
            cout << "9" + string(dist, '0') + "6" + string(dist, '0') + "1" + string(n - dist * 2 - 3, '0') << endl;
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