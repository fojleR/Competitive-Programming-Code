#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 100005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

const int Z = 30;
ll suf[Z][mx][2];
ll pre[Z][mx][2];

void solve(){
    int n;
    cin >> n;
    vector< int > v(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < Z; i++) suf[i][n + 1][0] = suf[i][n + 1][1] = 0;
    for(int i = 0; i < Z; i++){
        for(int j = 1; j <= n; j++){
            int t = !!((1 << i) & v[j]);
            for(int k = 0; k < 2; k++){
                pre[i][j][k] = (t == k) + pre[i][j - 1][k ^ t];
            }
        }
        for(int j = n; j >= 1; j--){
            int t = !!((1 << i) & v[j]);
            for(int k = 0; k < 2; k++){
                suf[i][j][k] = (t == k) + suf[i][j + 1][k ^ t];
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int z = 31 - __builtin_clz(v[i]);
        ans += (1 + pre[z][i - 1][0]) * suf[z][i + 1][1] + pre[z][i - 1][1] * (1 + suf[z][i + 1][0]);
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