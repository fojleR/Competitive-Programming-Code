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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    unordered_map< int, int > need, avail;
    //cout << n <<  " " << m << " " << k << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        need[x]++;
    }
    int smcnt = 0;
    int ans = 0;
    for(int i = 0; i < m; i++){
        avail[a[i]]++;
        if(avail[a[i]] == need[a[i]] and need[a[i]] > 0){
            smcnt++;
        }
    }
    if(smcnt >= k){
        ans++;
    }
    for(int i = 1; i <= n - m; i++){
        avail[a[i  - 1]]--;
        if(avail[a[i - 1]] < need[a[i - 1]]){
            smcnt--;
        }
        avail[a[i + m - 1]]++;
        if(avail[a[i + m - 1]] == need[a[i + m - 1]] and need[a[i + m - 1]] > 0){
            smcnt++;
        }
        if(smcnt >= k){
            ans++;
        }
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