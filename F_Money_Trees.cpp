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
    ll n, x;
    cin >> n >> x;
    ll a[n + 1] = {0}, h[n + 1] = {0};

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    // for(int i = 1; i <= n; i++){
    //     cout << h[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;
    ll tm = 0;
    ll sum = 0;
    for(int i = 1; i <= n;  i++){
        //cout << i << " ";
        if(h[i - 1] % h[i]){
            ans = max(ans, tm);
            if(a[i] <= x){
                sum = a[i];
                tm = 1;
                ans = max(ans, tm);
            }
            else{
                tm = 0;
                sum = 0;
            }
            
        }
        else{
            //cout << "true" << endl;
            sum += a[i];
            tm++;
            if(sum > x){
                while(sum > x){
                    //cout << endl;
                    //cout << sum << " " << tm  << endl;
                    
                    sum -= a[i - tm + 1];
                    tm--;
                }
            }
            ans = max(ans, tm);
        }
        //cout << tm << " " << sum  << endl;
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