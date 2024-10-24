#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { ll n=a.size(); if (!n) return cout; cout<<a[0]; for (ll i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================




void solve(){
    ll n, q;
    cin >> n >> q;
    vector< ll > v(n);
    cin >> v;
    ll dif[n];
    for(ll i = 1; i < n; i++){
        dif[i] = abs(v[i] - v[i - 1]);
    }
    dif[0] = 0;
    for(ll i = 2; i < n; i++){
        dif[i] += dif[i - 1];
    }
    while(q--){
        ll l, r, k;
        cin >> l >> r >> k;
        l--, r--;
        ll totalDif = dif[r] - dif[l];
        ll firstToLast = abs(v[l] - v[r]);
        ll doubleDif = totalDif - firstToLast;
        if(totalDif <= k){
            cout << 0 << endl;
            continue;
        }
        if(k >= firstToLast){
            ll baki = k - firstToLast;
            ll ans = (doubleDif - baki + 1) / 2;
            cout << ans << endl;
        }
        else{
            ll ans = doubleDif / 2 + (firstToLast - k);
            cout << ans << endl;
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