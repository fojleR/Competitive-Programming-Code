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
    int n, k, x;
    cin >> n >> k >> x;
    if(k > x + 1){
        cout << -1 << endl;
        return;
    }
    if(k > n){
        cout << -1 << endl;
        return;
    }

    int ans = 0;

    for(int i = 0; i < k; i++){
        ans += i;
    }
    if(k == x) x--;
    for(int i = k + 1; i <= n; i++){
        ans+=x;
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