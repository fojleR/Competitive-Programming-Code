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
    string s;
    cin >> s;
    // cout << s << endl;
    for(int i = 0; i < n - 1; i++){
        if((s[i + 1] >= '0' and s[i + 1] <= '9') and (s[i] >= 'a' && s[i] <= 'z')){
            cout << "NO" << endl;
            return;
        }
    }
    string s1 = "", s2 = "";
    int i;
    for(i = 0; i < n; i++){
        if(s[i] >= 'a' and s[i] <= 'z')break;
        s1 += s[i];
    }
    for(int j = i; j < n; j++){
        s2 += s[j];
    }
    int n2 = s1.size();
    for(int j = 0; j < n2 - 1; j++){
        if(s1[j] > s1[j + 1]){
            cout << "NO" << endl;
            return;
        }
    }
    // cout << s2.size() << endl;
    int nn = s2.size();
    for(int j = 0; j < nn - 1; j++){
        // cout << j << endl;
        // cout << s2[j] << endl;
        if(s2[j] > s2[j + 1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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