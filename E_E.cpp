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
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll l, r;
    cin >> l >> r;
    deque<ll> dq;
    for(int i = 0; i < n; i++){
        if(a[i] % 2)dq.push_back(i);
    }
    int sz = dq.size();
    if(sz % 2){
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    ll cost = min(l, r);
    while(dq.size() > 0){
        ll item = dq.front();
        dq.pop_front();
        ll right = n + n;
        ll left = n + n;
        if(dq.size() > 0)right = dq.front();
        if(dq.size() > 0)left = dq.back();
        ll dis1 = abs(item - left);
        ll dis2 = abs(item - right);
        if(dis1 < dis2){
            ans += dis1 * cost;
            dq.pop_back();
        }
        else{
            ans += dis2 * cost;
            dq.pop_front();
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