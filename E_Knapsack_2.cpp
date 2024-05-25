#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

ll n, w;

ll dp[105][100005];

ll dpSolve(vector< int > &weight, vector< int > &value, int pos, int val){
    if(val == 0){
        return 0;
    }
    if(val < 0 || pos == n){
        return 1e15;
    }
    if(dp[pos][val] != -1){
        return dp[pos][val];
    }
    ll ans = dpSolve(weight, value, pos + 1, val);
    ans = min(ans, weight[pos] + dpSolve(weight, value, pos + 1, val - value[pos]));
    return dp[pos][val] = ans;
}

void solve(){
    cin >> n >> w;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 1e5; j++){
            dp[i][j] = - 1;
        }
    }
    vector< int > weight(n), value(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }
    for(int i = 1e5; i >= 0; i--){
        if(dpSolve(weight, value, 0, i) <= w){
            cout << i << endl;
            return;
        }
    }
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