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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    bool ok = false;
    int ans = 0;

    for(int i = 0; i < n; i++){
        int j;
        int ti = i;
        int tm = m;
        for(j = 0; j < m; j++){
            if(ti >= tm ){
                ans++;
                tm += tm;
            }
            if(s[j] != x[ti % n])break;
            ti++;
        }
        if(j == m)ok = true;
    }
    if(!ok){
        cout << -1 <<endl;
        return;
    }
    // ok = false;
    // for(int i = 0; i < n; i++){
    //     int j;
    //     int ti = i;
    //     for(j = 0; ti < n and j < m; j++){
    //         if(x[ti] != s[j])break;
    //         ti++;
    //     }
    //     //cout << i << " " << ti << " " << j <<endl;
    //     if(j >= m)ok = true;
    // }
    // if(ok){
    //     cout << 0 << endl;
    //     return;
    // }
    // if(n >= m){
    //     cout << 1 << endl;
    //     return;
    // }
    // int ans = 0;
    // while(n < m){
    //     ans++;
    //     n += n;
    // }
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