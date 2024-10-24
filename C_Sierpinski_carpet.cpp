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
    if(n == 0){
        cout << "#" << endl;
        return;
    }
    vector< vector< char > > a(3, vector< char > (3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            a[i][j] = '#';
        }
    }
    a[1][1] = '.';
    for(int ii = 1; ii < n; ii++){
        int len = pow(3, ii + 1);
        int dlen = pow(3, ii);
        vector< vector< char > > newa(len, vector< char > (len));
        for(int i = 0; i < len; i += dlen){
            for(int j = 0; j < len; j += dlen){
                for(int k = 0; k < dlen; k++){
                    for(int l = 0; l < dlen; l++){
                        newa[i + k][j + l] = a[k][l];
                    }
                }
            }
        }
        for(int i = 0; i < dlen; i++){
            for(int j = 0; j < dlen; j++){
                newa[i + dlen][j + dlen] = '.';
            }
        }
        a = newa;
    }
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            cout << a[i][j];
        }
        cout << endl;
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