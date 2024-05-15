#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 300005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

ll dp[mx][12];
int n;
vector< ll > v;

ll check(int pos, int k){
    if(pos == n){
        return 0;
    }
    if(dp[pos][k] != -1){
        return dp[pos][k];
    }
    ll ans = v[pos] + check(pos + 1, k);
    ll mn = v[pos];
    for(int i = 1; i <= k and pos + i < n; i++){
        mn = min(mn, v[pos + i]);
        ll temp = mn * (i + 1);
        // cout << temp << endl;
        ans = min(ans, temp + check(pos + i + 1, k - i));
    }
    return dp[pos][k] = ans;
}

void solve(){
    int k;
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = -1;
        }
    }
    v.clear();
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        v.pb(x);
    }
    cout << check(0, k) << endl;
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