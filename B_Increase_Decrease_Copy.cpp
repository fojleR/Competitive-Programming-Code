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
    ll a[n], b[n + 1];
    vector< ll > vt;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        vt.push_back(a[i]);
    }
    for(int j = 0; j < n + 1; j ++){
        cin >> b[j];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        //cout << a[i] << " " << b[i] << endl;
        ans += abs(a[i] - b[i]);
    }
    //cout << ans << endl;
    for(int i = 0; i < n; i++){
        ll mn = min(a[i], b[i]);
        ll mx = max(a[i], b[i]);
        if(b[n] <= mx and b[n] >= mn){
            cout << ans + 1 << endl;
            return;
        }
    }
    sort(vt.begin(), vt.end());
    ans++;
    ll tans = 1e16;
    for(int i = 0; i < n; i++){
        ll tm = abs(b[i] - b[n]);
        tm = ans + tm;
        tans = min(tans, tm);
    }
    for(int i = 0; i < n; i++){
        ll tm = abs(a[i] - b[n]);
        tm = ans + tm;
        tans = min(tans, tm);
    }
    cout << tans << endl;
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