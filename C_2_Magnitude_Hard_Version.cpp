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


void solve(){
    int n;
    cin >> n;
    ll a[n + 1];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans += a[i];
    }
    ll preSum[n + 1] = {0};
    ll sufSum[n + 1] = {0};

    for(int i = 1; i <= n; i++){
        preSum[i] = preSum[i - 1] + a[i];
    }
    
    for(int i = n; i >= 1; i--){
        if(i == n) sufSum[i] = a[i];
        else sufSum[i] = sufSum[i + 1] + a[i];
    }
    
    int ind = -1;
    for(int i = 1; i <= n; i++){
        ll tsum = 0;
        tsum += preSum[i - 1];
        tsum = abs(tsum + a[i]);
        if(i < n) tsum += sufSum[i + 1];
        if(tsum > ans){
            ans = tsum;
            ind = i;
        }
    }
    
    ll way = 1;

    for(int i = 1; i <= n; i++){
        if(a[i] >= 0){
            way = (way * 2) % mod;
        }
        else{
            ll tsum = 0;
            tsum += preSum[i - 1];
            tsum = abs(tsum + a[i]);
            if(i < n) tsum += sufSum[i + 1]; 
            if(i != ind && tsum == ans){
                way = (way * 2) % mod;
            }
        }
    }
    cout << way << endl;

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