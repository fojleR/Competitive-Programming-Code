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
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n){
        cout << "No" << endl;
        return;
    }
    ll sm = sum / n;
    vector< int > cn(100, 0);
    for(int i = 0; i < n; i++){
        ll vl = abs(sm - a[i]);
        ll tm = vl;
        int cnt = 0, cnt1 = 0;
        while(tm){
            if(tm % 2){
                cnt1++;
            }
            cnt++;
            tm /= 2;
        }
        ll num = 0;
        for(int bit = cnt - cnt1; bit < cnt; bit++){
            num += (1ll << bit);
        }
        if(num != vl){
            cout << "No" << endl;
            return;
        }
        int bit1 = cnt - cnt1 + 1;
        int bit = cnt + 1;
        if(sm > a[i]){
            cn[bit]++;
            cn[bit1]--;
        }
        else{
            cn[bit1]++;
            cn[bit]--;
        }
    }
    for(int i = 0; i < 100; i++){
        if(cn[i]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

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