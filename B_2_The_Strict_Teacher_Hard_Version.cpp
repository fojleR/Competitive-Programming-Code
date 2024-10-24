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
    ll n, m, k;
    cin >> n >> m >> k;
    ll b[m];
    for(ll i = 0; i < m; i++){
        cin >> b[i];
    } 
    sort(b, b + m);
    while(k--){
        ll x;
        cin >> x;
        if(b[m - 1] < x){
            cout << n - b[m - 1] << endl;
            continue;
        }
        if(x < b[0]){
            cout << b[0] - 1 << endl;
            continue;
        }
        ll ind1 = lower_bound(b, b + m, x) - b;
        if(b[ind1] == x){
            cout << 0 << endl;
            continue;
        }
        ll ind2 = ind1 - 1;
        ll dis = b[ind1] - b[ind2];
        ll ans = dis / 2;
        cout << ans << endl;
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