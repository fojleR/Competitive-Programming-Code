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


bool cmp(pair< ll, ll > a, pair< ll, ll > b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector< pair< ll, ll > > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    // for(auto x: v){
    //     cout << x.first << " " << x.second << endl;
    // }
    ll ans = 0;
    ll suma = 0;
    ll sumb = 0;
    ll bad = 0;
    multiset< ll > st;
    for(int i = 0; i < n; i++){
        suma += v[i].first;
        sumb += v[i].second;
        //cout << i << " " << suma << " " << sumb << " ";
        bad += v[i].second;
        st.insert(v[i].second);
        // cout << st.size() << " ";
        if(st.size() > k){
            auto it = st.begin();
            bad -= *it;
            st.erase(it);
        }
        ll tans = sumb - suma - bad;
        //cout << bad << " " << tans << endl;
        ans = max(ans, tans);
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