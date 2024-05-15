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
    int ans[n + 1];
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n == 2){
        cout << "2 1" << endl;
        return;
    }
    ans[n] = 3;
    ans[1] = 2;
    ans[(n + 1) / 2] = 1;
    int x = 4;
    for(int i = 2; i <= n - 1; i++){
        if(i == (n + 1)/ 2)continue;
        ans[i] = x++;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}


int main(){
    fast
    int t = 1;
    //cout << pm.back() << endl;
    cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}