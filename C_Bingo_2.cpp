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
    int n, t;
    cin >> n >> t;
    map< int, pair< int, int > > mp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x = n * (i - 1) + j;
            mp[x] = {i, j};
        }
    }
    vector< set< int > > row(n + 1);
    vector< set< int > > col(n + 1);
    set< int > digona1, digonal2;
    for(int i = 0; i < t; i++){
        int tt;
        cin >> tt;
        int x, y;
        x = mp[tt].first;
        y = mp[tt].second;
        row[x].insert(tt);
        col[y].insert(tt);
        if(x == y){
            digona1.insert(tt);
        }
        if(x + y == n + 1){
            digonal2.insert(tt);
        }
        if(row[x].size() == n){
            cout << i + 1 << endl;
            return;
        }
        if(col[y].size() == n){
            cout << i + 1 << endl;
            return;
        }
        if(digona1.size() == n){
            cout << i + 1 << endl;
            return;
        }
        if(digonal2.size() == n){
            cout << i + 1 << endl;
            return;
        }

    }
    cout << -1 << endl;
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