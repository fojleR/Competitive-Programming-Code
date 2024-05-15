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
    int n, k;
    cin >> n >> k;
    vector< int > ans;
    int sum = 0;
    int tm = 0;
    while(sum < n){
        // tm++;
        // cout << sum << endl;
        int newElement = sum + 1;
        if(newElement == k){
            newElement++;
        }
        int mn = newElement;
        int mx = sum + newElement;
        if(k >= mn && k <= mx) ans.push_back(k - sum - 1);
        else ans.push_back(newElement);
        sum += ans.back();
    }
    int sz = ans.size();
    for(int i = 0; i < sz && ans.size() < 25; i++){
        if(ans[i] > k)ans.push_back(ans[i] + k);
    }
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x << ' ';
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