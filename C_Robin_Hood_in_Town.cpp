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

bool check(vector< ll > v, ll n, ll x){
    ll mxind = 0;
    ll mx = v[0];
    for(int i = 0; i < n; i++){
        if(v[i] > mx){
            mx = v[i];
            mxind = i;
        }
    }
    v[mxind] += x;
    long double sum = 0;
    for(long double x: v){
        sum += x;
    }
    long double ave = sum / n;
    ave /= 2;
    int unhappy = 0;
    for(int i = 0; i < n; i++){
        if(v[i] < ave){
            unhappy++;
        }
    }
    long double happy = n - unhappy;
    return happy < unhappy;
}

void solve(){
    vector< ll > v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        v.push_back(x);
    }
    ll lo = 0, hi = 1e18;
    ll ans = -1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(v, n, mid)){
            ans = mid;
            hi = mid -1;
        }
        else{
            lo = mid + 1;
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