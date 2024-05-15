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
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    bool wleft = false, wright = false, wup = false, wdown = false;
    bool bleft = false, bright = false, bup = false, bdown = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][0] == 'W') wleft = true;
            if(mat[i][m - 1] == 'W') wright = true;
            if(mat[0][j] == 'W') wup = true;
            if(mat[n - 1][j] == 'W') wdown = true;
            if(mat[i][0] == 'B') bleft = true;
            if(mat[i][m - 1] == 'B') bright = true;
            if(mat[0][j] == 'B') bup = true;
            if(mat[n - 1][j] == 'B') bdown = true;
        }
    }
    // cout << wleft << " " << wright << " " << wup << " " << wdown << endl;
    // cout << bleft << " " << bright << " " << bup << " " << bdown << endl;
    if((mat[0][0] == 'W' && mat[n - 1][m -1] == 'W') || (mat[0][0] == 'B' && mat[n - 1][m -1] == 'B')){
        // cout << 1 << endl;
        cout << "YES" << endl;
        return;
    }
    if((mat[0][m - 1] == 'W' and mat[n - 1][0] == 'W') || (mat[0][m - 1] == 'B' and mat[n - 1][0] == 'B')){ 
        cout << "YES" << endl;
        // cout << 2 << endl;
        return;
    }
    if((wleft and wright and wup and wdown) or (bleft and bright and bup and bdown)){
        // cout << 3 << endl;
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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