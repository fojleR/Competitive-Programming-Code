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
    a[0] = 0;
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }
    vector< ll > v;
    int cnt[n + 1] = {0};
    for(int i = 1; i < n; i++){
        ll dif = a[i] - a[i - 1];
        //cout << i << " " << dif << endl;
        if(dif <= n and cnt[dif] == 0){
            cnt[dif]++;
        }
        else{
            v.push_back(dif);
        }
    }
    // for(auto x: v){
    //     cout << x << " ";
    // }
    // cout << endl;
    if((int)v.size() == 0){
        cout << "YES" << endl;
        return;
    }
    else if((int)v.size() == 1){
        if(v[0] < 2 * n){
            for(int i = 0; i < v[0]; i++){
                int a = i;
                int b = v[0] - i;
                //cout << a << " " << b << endl;
                if(a <= n and b <= n and cnt[a] == 0 and cnt[b] == 0){
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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