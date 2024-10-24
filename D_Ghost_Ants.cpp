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
    ll n, t;
    cin >> n >> t;
    vector< ll > left, right;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        if(s[i] == '1'){
            right.push_back(x);
        }
        else{
            left.push_back(x);
        }
    }
    ll ans = 0;
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    // cout << left << endl;
    for(int i = 0; i < right.size(); i++){
        ll indi = lower_bound(left.begin(), left.end(), right[i]) - left.begin();
        ll indj = upper_bound(left.begin(), left.end(), right[i] + t * 2) - left.begin();
        ans += max(0ll, indj - indi);
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