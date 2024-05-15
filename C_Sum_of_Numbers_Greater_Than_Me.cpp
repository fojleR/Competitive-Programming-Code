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
    ll a[n];
    vector< ll > v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    vector< ll > sum(n);
    sum[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--){
        sum[i] = sum[i + 1] + v[i];
    }
    // for(auto x: sum){
    //     cout << x << " ";
    // }
    // cout << endl;
    for(int i = 0; i < n; i++){
        int ind = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
        if(ind >= n){
            cout << 0 << " ";
        }
        else{
            cout << sum[ind] << " ";
        }
    }
    cout << endl;
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