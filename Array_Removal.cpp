#include<bits/stdc++.h>

using namespace std;

#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly! ==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// =================================== END Of the input module ==========================================

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll cur = 1LL << 33;
    cur = cur - 1;
    ll ans = 0;
    while(cur > 0){
        cur = cur >> 1;
        ll cnt = 0;
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            bool ok = true;
            for(ll bit = 0; bit <= 33; bit++){
                if((cur & (1LL << bit)) == 0 && (a[i] & (1LL << bit)) != 0){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cnt++;
                tmp = tmp | a[i];
            }
        }
        if(tmp == cur){
            ans = max(ans, cnt);
        }
        
    }
    cout << n - ans << endl;
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
