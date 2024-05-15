#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 998244353;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

const int N = 5001;
ll dp[N][N];

void solve(){
    int n;
    cin >> n;
    vector< int > v(n);
    for(auto &x: v){
        cin >> x;
    }
    sort(v.begin(), v.end());
    ll cnt[N] = {0};
    dp[0][0]++;
    cnt[0]++;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 5000; j > v[i]; j--){
            dp[j][v[i]] += cnt[j - v[i]];
            dp[j][v[i]] %= mod;
        }
        for(int j = 5000; j > v[i]; j--){
            cnt[j] += cnt[j - v[i]];
            cnt[j] %= mod;
        }
        dp[v[i]][v[i]]++;
        cnt[v[i]]++;
    }
    ll ans = 0;
    for(int i = 1; i <= 5000; i++){
        for(int j = 1; j <= i; j++){
            if(j <= i / 2)ans += ((dp[i][j]) * ((i + 1)/ 2)) % mod;
            else ans += ((dp[i][j]) * j) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}