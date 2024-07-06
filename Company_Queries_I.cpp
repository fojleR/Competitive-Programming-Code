#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
const int logN = 20;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

vector< vector< int > > v(mx, vector< int >(logN, 0));
vector< int > depth(mx, 0);

void solve(){
    int n, q;
    cin >> n >> q;
    v[1][0] = -1;
    for(int i = 2; i <= n; i++){
        cin >> v[i][0];
        depth[i] = depth[v[i][0]] + 1;
    }
    for(int j = 1; j < logN; j++){
        for(int i = 1; i <= n; i++){
            if(v[i][j - 1] != -1){
                v[i][j] = v[v[i][j - 1]][j - 1];
            }
        }
    }
    while(q--){
        int x, k;
        cin >> x >> k;
        if(depth[x] < k){
            cout << -1 << '\n';
            continue;
        }
        for(int i = 0; i < logN; i++){
            if(k & (1 << i)){
                x = v[x][i];
                if(x == -1) break;
            }
        }
        cout << x << '\n';
    }
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