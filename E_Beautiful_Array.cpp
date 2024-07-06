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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, int > mp;
    map< ll, vector< int > > mp2;
    for(int i = 0; i < n; i++){
        ll md = a[i] % k;
        mp[md]++;
        mp2[md].push_back(a[i]);
    }
    int odd = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        int cnt = it->second;
        if(cnt % 2 == 1){
            odd++;
        }
    }
    for(auto it = mp2.begin(); it != mp2.end(); it++){
        sort(it->second.begin(), it->second.end());
        // cout << it->first << " : ";
        // for(auto x: it->second){
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    if(odd > 1){
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for(auto it = mp2.begin(); it != mp2.end(); it++){
        //cout << it -> first << " : ";
        // cout << it->second << " ";
        vector< int > v = it->second;
        ll tans = 0;
        for(int i = 0; i < v.size() - 1; i += 2){
            ll dif = v[i + 1] - v[i];
            tans += (dif / k);
        }
        if(v.size() % 2){
            ll tans2 = tans;
            ll presum[v.size()] = {0}, sufsum[v.size()] = {0};
            for(int i = 1; i < v.size(); i += 2){
                if(i != 1){
                    presum[i] = presum[i - 2];
                }
                presum[i] += v[i] - v[i - 1];
            }
            for(int i = v.size() - 1; i > 0; i -= 2){
                if(i != v.size() - 1){
                    sufsum[i] = sufsum[i + 2];
                }
                sufsum[i] += v[i] - v[i - 1];
            }
            for(int i = 0; i < v.size(); i++){
                ll ttm = 0;
                if(i % 2 == 0){
                    if(i + 2 < v.size()) ttm += sufsum[i + 2];
                    if(i - 1 >= 0) ttm += presum[i - 1];
                }
                else{
                    if(i + 2 < v.size()) ttm += sufsum[i + 3];
                    if(i - 2 >= 0) ttm += presum[i - 2];
                    ttm += v[i + 1] - v[i - 1];
                }
                //cout << ttm << endl;
                tans = min(tans, ttm / k);
                
            }
        }
        ans += tans;
        // cout << tans << endl;
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