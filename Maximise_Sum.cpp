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
    vector< int > v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0] << endl;
        return;
    }
    v.push_back(0);
    int j;
    for(int j = 1; j < n; j++){
        int cur = v.back();
        if(a[cur] <= a[j]){
            v.push_back(j);
        }
    }
    

    int xx = v.back();
    v.push_back(n - 1);
    for(int i = n - 2; i > xx; i--){
        int cur = v.back();
        if(a[cur] <= a[i]){
            v.push_back(i);
        }
    }

    sort(v.begin(), v.end());
    // for(auto i : v){
    //     cout << i << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for(int i = 0; i < v.size() - 1; i++){
        ll mn = min(a[v[i]], a[v[i + 1]]);
        for(int j = v[i] + 1; j < v[i + 1]; j++){
            a[j] = mn;
        }
    }
    for(int i = 0; i < n; i++) ans += a[i];
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