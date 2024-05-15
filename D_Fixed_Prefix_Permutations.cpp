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
    vector< vector< int > > v;
    set< vector< int > > avail;
    for(int i = 0; i < n; i++){
      vector< int > curr(m, 0);
      cin >> curr;
      v.push_back(curr);
      avail.insert(curr);
      for(int ind = m; ind > 0; ind--){
        for(int j = 0; j < m; j++){
            if(curr[j] == ind){
                curr[j] = -1;
                break;
            }
        }
        avail.insert(curr);
      }
    }
    for(int i = 0; i < n; i++){
        vector< int > tm(m, 0);
        for(int j = 0; j < m; j++){
            tm[v[i][j]- 1] = j + 1;
        }
        if(avail.count(tm)){
            cout << m << " ";
            continue;
        }
        bool found = false;
        for(int j = m; j >= 1; j--){
            for(int k = 0; k < m; k++){
                if(tm[k] == j){
                    tm[k] = -1;
                    break;
                }
            }
            if(avail.count(tm)){
                cout << j - 1 << " ";
                found = true;
                break;
            }
        }
        if(!found){
            cout << 0 << " ";
        }
    }
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