#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
using namespace __gnu_pbds; 


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

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first > b.first;
}

void solve(){
    ll n;
    cin >> n;
    ll a[n + 1];
    vector< pair<ll, ll> > v;
    ordered_set st;
    map< ll, ll > mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back({a[i] + i, i});
        mp[a[i] + i]++;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    vector< ll > ans;
    for(int i = 0; i < n; i++){
        ll tm = v[i].first;
        if(mp[v[i].first] > 1)
            st.insert(v[i].second);
        ll pos = st.order_of_key(v[i].second);
        tm -= pos;
        ans.push_back(tm);
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
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