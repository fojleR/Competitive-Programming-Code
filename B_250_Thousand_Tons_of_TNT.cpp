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
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    //sort(a + 1, a + n + 1);
    ll sum[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 0;
    // for(int i = 1; i <= n; i++){
    //     cout << sum[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= n / 2; i++){
        
        if(n % i == 0){
            //cout << i << endl;
            multiset< ll > st;
            for(int j = i; j <= n; j += i){
                //cout << sum[j] - sum[j - i] << " ";
                st.insert(sum[j] - sum[j - i]);
            }
            auto it = st.end();
            it--;
            ll ls = *it;
            ll tm = ls - *(st.begin());
            ans = max(ans, tm);
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