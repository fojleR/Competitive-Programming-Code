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
    ll a[n], mn[n], cnt[n] = {0};
    for(int i = 0; i < n; i++) cin >> a[i];
    map< ll, int > mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
        cnt[i] = mp[a[i]];
        if(!i){
            mn[i] = a[i];
        }
        else mn[i] = min(a[i], mn[i - 1]);
    }
    // for(int i = 0; i < n; i++){
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    ll lst = 0;
    ll ans = 0;
    ll ans1[n] = {0};
    for(int i = n - 1; i >= 0; i--){
        if(i != n - 1){
            ans1[i] = ans1[i + 1];
        }
        if(mn[i] >= a[i]){
            ans1[i] += (a[i] - lst);
            lst += (a[i] - lst);
        }
        else{
            ans1[i]++;
        }
    }
    ans = n;
    for(int i = 0; i < n; i++){
        ans = min(ans, i + ans1[i]);
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