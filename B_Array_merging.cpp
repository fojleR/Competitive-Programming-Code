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
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int cnta[2 * n + 1] = {0}, cntb[2 * n + 1] = {0};
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            cnta[a[i - 1]] = max(cnta[a[i - 1]], cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    cnta[a[n - 1]] = max(cnta[a[n - 1]],cnt);
    cnt = 1;
    for(int i = 1; i < n; i++){
        if(b[i] != b[i - 1]){
            cntb[b[i - 1]] = max(cntb[b[i - 1]], cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    cntb[b[n- 1]] = max(cntb[b[n - 1]], cnt);
    int ans = 0;
    for(int i = 1; i <= 2 * n; i++){
        int tm = cnta[i] + cntb[i];
        ans = max(ans, tm);
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