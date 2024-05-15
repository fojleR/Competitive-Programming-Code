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
    ll n;
    cin >> n;
    ll a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll pre[n + 1] = {0};
    pre[1] = 1;
    for(int i = 2; i <= n - 1; i++){
        ll tm1 = abs(a[i] - a[i + 1]);
        ll tm2 = abs(a[i] - a[i - 1]);
        if(tm1 < tm2){
            pre[i] = 1;
        }
        else{
            pre[i] = tm1;
        }
    }
    ll suf[n + 1] = {0};
    suf[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        ll tm1 = abs(a[i] - a[i - 1]) ;
        ll tm2 = abs(a[i] - a[i + 1]);
        if(tm1 < tm2){
            suf[i] = 1;
        }
        else{
            suf[i] = tm1;
        }
    }
    suf[1] = 0;
    ll apre[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        apre[i] = apre[i - 1] + pre[i - 1];
    }
    ll asuf[n + 1] = {0};
    for(int i = n - 1; i >= 1; i--){
        asuf[i] = asuf[i + 1] + suf[i + 1];
    }
    // for(int i = 1; i <= n; i++){
    //     cout << apre[i] << " ";
    // }
    // cout << endl;
    int m;
    cin >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        if(x < y){
            cout << apre[y] - apre[x] << endl;
        }
        else{
            cout << abs(asuf[x] - asuf[y]) << endl;
        }
    }
    cout << endl;

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