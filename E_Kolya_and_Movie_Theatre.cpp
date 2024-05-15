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
    ll n, m, d;
    cin >> n >> m >> d;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    multiset< ll > st;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll cur = sum + a[i] - (i + 1)  * d;
        ans = max(ans, cur);
        if(a[i] > 0){
            st.insert(a[i]);
            sum += a[i];
            if(st.size() >= m){
                sum -= *(st.begin());
                st.erase(st.begin());
            }
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