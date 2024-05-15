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
    ll A, B, C, k;
    cin >> A >> B >> C >> k;
    if(C < A || C < B){
        cout << -1 << endl;
        return;
    }
    ll a = 1;
    ll c = 0;
    for(int i = 1; i < A; i++){
        a *= 10;
    }
    ll mxc = c;
    ll mnb = 1;
    ll mxb;
    if(B == C){
        mnb = 1 * pow(10, (B - 1));
    }
    else{
        mnb = 1 * pow(10, (C - 1)) - a;
        ll mmb = 1 * pow(10, B - 1);
        mnb = max(mnb, mmb);
    }
    if(B == C){
        mxc = 0;
        for(int i = 0; i < C; i++){
            mxc = mxc * 10 + 9;
        }
        mxb = mxc - a;
    }
    else{
        mxb = 0;
        for(int i = 0; i < B; i++){
            mxb = mxb * 10 + 9;
        }
    }
    cout << mxb << " " << mnb << endl;
    ll tm = a;
    ll ans = 0;
    ll mmb = 1 * pow(10, B - 1);
    while(tm < a * 10){
        ll cnt = mxb - mnb + 1;
        cout << cnt << endl;
        ans += cnt;
        if(ans >= k){
            ll extend = ans - k;
            ll bb = mxb - extend;
            cout << tm << " + " << bb << " = " << tm + bb << endl;
            // cout << ans << endl;
            return;
        }
        tm++;
        if(B == C){
            mxb--;
            mxb = max(mmb, mxb);
        }
        else{
            mnb--;
            mnb = max(mnb, mmb);
        }
    }
    cout << -1 << endl;
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