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
    char mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    set< pair< int, int > > st;
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '1'){
                st.insert({i, j});
                ok = true;
                break;
            }
        }
        if(ok)break;
    }
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int j = n - 1; j >= 0; j--){
            if(mat[i][j] == '1'){
                st.insert({i, j});
                ok = true;
                break;
            }
        }
        if(ok)break;
    }
    for(int i = n - 1; i >= 0; i--){
        bool ok = false;
        for(int j = 0; j < n; j++){
            if(mat[i][j] == '1'){
                st.insert({i, j});
                ok = true;
                break;
            }
        }
        if(ok)break;
    }
    for(int i = n - 1; i >= 0; i--){
        bool ok = false;
        for(int j = n - 1; j >= 0; j--){
            if(mat[i][j] == '1'){
                st.insert({i, j});
                ok = true;
                break;
            }
        }
        if(ok)break;
    }
    // for(auto x: st){
    //     cout << x.first << " " << x.second << endl;
    // }
    if(st.size() == 4){
        cout << "SQUARE" << endl;
    }
    else{
        cout << "TRIANGLE" << endl;
    }
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