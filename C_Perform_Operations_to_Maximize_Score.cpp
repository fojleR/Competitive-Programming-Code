#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { ll n=a.size(); if (!n) return cout; cout<<a[0]; for (ll i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

bool check(vector< pair< ll, ll > > v, ll n, ll k, ll need){
    //cout << "check " << need << endl;
    ll sum = v[n - 1].first;
    ll mid = n / 2;
    ll rem = need - sum;
    //cout << "rem " << rem << endl;
    ll cnt = 0;
    if(v[n - 1].second == 1){
        sum += k;
        sum += v[mid - 1].first;
        if(sum >= need){
            return true;
        }
    }
    for(ll i = n - 2; i >= 0; i--){
        if(v[i].first >= rem){
            cnt++;
            continue;
        }
        if(v[i].second == 1){
            ll xx = rem - v[i].first;
            xx = min(k, xx);
            v[i].first += xx;
            k -= xx;
            if(v[i].first >= rem)cnt++;
        }
    }
    
    ll needCnt = n - mid;
    //cout << cnt << " " << needCnt << endl;
    return needCnt <= cnt;
}

ll check2(vector< pair< ll, ll > > v, ll n, ll k){
    ll tans = 0;
    for(int i = 1; i <= n; i++){
        ll mc;
        if(v[i - 1].second){
            if(i <= n / 2) mc = v[n / 2].first;
            else mc = v[(n - 2)/2].first;
            tans = max(tans, mc + k + v[i - 1].first);
        }
    }
    return tans;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll a[n], b[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    vector< pair< ll, ll > > v;
    for(ll i = 0; i < n; i++){
        v.push_back({a[i], b[i]});
    }
    sort(v.begin(), v.end());
    ll lo = 1, hi = 1e18;
    ll ans = 1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(v, n, k, mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    ans = max(ans, check2(v, n, k));
    cout << ans << endl;
}


int main(){
    fast
    ll t = 1;
    cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}