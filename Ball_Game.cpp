#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
    long double a[n];  // Use long double for higher precision
    long double b[n];
    long double time[n];
    vector< pair<long double, long double> > v;  // Use long double for the pair

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        v.push_back({a[i], b[i]});
    }
    sort(v.begin(), v.end());
    
    // Set precision to 15 decimal places
    cout << fixed << setprecision(15);
    
    for(int i = 0; i < n; i++){
        //cout << v[i].first << " " << v[i].second << endl;
        time[i] = v[i].first / v[i].second;
    }
    // for(int i = 0; i < n; i++){
    //     cout << time[i] << " ";
    // }
    // cout << endl;
    
    int ans = 1;
    long double mn = time[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(time[i] <= mn){
            ans++;
            mn = time[i];
        }
    }
    cout << ans << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        solve();
    }
    return 0;
}
