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
    ll n, k, q;
    cin >> n >> k >> q;
    unordered_map< ll, ll > mp;
    vector< ll > v;
    v.push_back(0);
    mp[0] = 0;
    int a[k], b[k];
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    for(int i = 0; i < k; i++){
        cin >> b[i];
    }
    for(int i = 0; i < k; i++){
        mp[a[i]] = b[i];
        v.push_back(a[i]);
    }
    // for(auto x: v){
    //     cout << x << " ";
    // }
    // cout << endl;
    while(q--){
        ll d;
        cin >> d;
        int ind = lower_bound(v.begin(), v.end(), d) - v.begin();
        // cout << d << " " << ind << endl;
        // cout << v[ind] << endl;
        if(v[ind] == d){
            cout << mp[d] << " ";
            continue;
        }
        
        ll lo = v[ind - 1];
        ll hi = v[ind];
        // cout << d << " " << lo << " " << hi << endl;
        ll dis = hi - lo;
        ll tm = mp[hi] - mp[lo];
        float ave = (tm * 1.0)/ dis;
        int solid = int(ave);
        float precison = ave - solid;
        ll baki = d - lo;
        // cout << baki << " " << ave << " " << endl;
        // cout << mp[lo] << " " << baki * ave << " ";
        ll ans = mp[lo] + baki * solid + int(precison * baki);
        cout << ans << " ";
        // cout << endl;
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