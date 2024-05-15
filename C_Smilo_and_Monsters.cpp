#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;



void solve(){
    ll n;
    cin >> n;
    ll a[n];
    ll tot = 0, sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    
    ll cnt = n;
    sort(a, a + n);
    for(ll i = 0; i < n; i++){
        tot -= a[i];
        sum += a[i];
        cnt--;
        if(tot <= sum){
            //cout << tot << " " << sum << endl;
            if(tot < sum){
                ll x = sum - tot;
                x = x / 2;
                if(x){
                    sum -= x;
                    tot += x;
                    cnt++;
                }
            }
            cout << sum + cnt << endl;
            break;
        }
    }

}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}