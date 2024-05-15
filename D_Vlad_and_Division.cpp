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
    int n;
    cin >> n;
    ll cnt[64] = {0};
    ll a[n];
    int cnt0 = 0;
    ll ans = 0;
    map< ll, int > mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    map<ll, ll > mm;
    for(int i = 0; i < n; i++){
        ll x;
        x = a[i];
        ll rev = 0;
        // if(x == 0)cnt0++;
        bool ok = false;
        for(int j = 0; j < 31; j++){
            if(x & (1LL << j)){
                cnt[j]++;
                //cout << 1 << " ";
                // if(cnt[j] == 0){
                //     cnt[j] = 1;
                //     ok = true;
                //     break;
                // }
            }
            else{
                rev += (1LL << j);
                // cout << 0 << " ";
            }
        }
        mm[x] = rev;
    }
    // ll ans = 0;
    ll revcnt = 0;
    for(auto x: mm){
        //cout << x.first << " " << x.second << endl;
        //cout << mp[x.first] <<" " << mp[x.second] << endl;
        revcnt += min(mp[x.first], mp[x.second]);
    }
    //cout << revcnt / 2 << endl;
    cout << n - revcnt/2 << endl;
    // for(int i = 0; i < 32; i++){
    //     cout << i << " " << cnt[i] << endl;
    // }
    //cout << ans << endl;
    // ans = cnt0;
    // for(int i = 0; i <= 32; i++){
    //     //cout << i << " " << cnt[i] << endl;
    //     ans += cnt[i];
    // }
    // cout << ans << endl;
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