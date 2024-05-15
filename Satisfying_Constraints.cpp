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
    vector< ll > v1, v2, v3;
    for(int i = 0; i < n; i++){
        ll a, x;
        cin >> a >> x;
        if(a == 1){
            v1.push_back(x);
        }
        else if(a == 2){
            v2.push_back(x);
        }
        else{
            v3.push_back(x);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int cnt = v2[0] - v1[v1.size() - 1] + 1;
    cnt = max(0, cnt);
    for(int i = 0; i < v3.size();  i++){
        if(v3[i] >= v1[v1.size() - 1] and v3[i] <= v2[0])cnt--;
    }
    cnt = max(0, cnt);
    cout << cnt << endl;
    
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