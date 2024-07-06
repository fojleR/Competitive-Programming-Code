#include <bits/stdc++.h>

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

bool check(ll num, ll tot, ll mi, ll now){
    if(num * (now - mi) > tot - mi) return true;
    else return false;
}

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans[n];
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        ans[i] = 100;
        tot += ans[i];
    }
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++) {
        v.push_back({a[i], ans[i]});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++) {
        ll num = v[i].first;
        ll hi = v[i].second;
        ll now = v[i].second;
        ll lo = 0;
        ll as = -1;
        while(lo <= hi) {
            cout << lo << " " << hi << endl;
            ll mid = (lo + hi) / 2;
            if(check(num, tot, mid, now)) {
                as = mid;
                lo = mid + 1;  // Search in the higher range
            } else {
                hi = mid - 1;
            }
        }
        cout << as << endl;
        if(as == -1) {
            cout << -1 << endl;
            return;
        }
        v[i].second = v[i].second - as;
        tot -= as;
    }
    tot = 0;
    for(int i = 0; i < n; i++){
        tot += v[i].second;
    }
    cout << tot << endl;
    if(tot >= v[n - 1].first * v[n - 1].second) {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    fast
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
