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
    ll a[n + 1];
    ll ans = -10000;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    
    ll tm = a[1];
    for(int i = 2; i <= n; i++){
        if(tm < 0){
            tm = a[i];
            ans = max(ans, tm);
            continue;
        }
        if((a[i] + 10000) % 2 == (a[i - 1] + 1000) % 2){
            ans = max(ans, tm);
            tm = a[i];
        }
        else if(tm + a[i] < 0){
            while(i <= n and a[i] < 0){
                i++;
            }
            if(i <= n)
                tm = a[i];
        }
        else{
            tm += a[i];
            ans = max(ans, tm);
        }
        //cout << i << " " << tm << " " << ans << endl;
    }
    ans = max(ans, tm);
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