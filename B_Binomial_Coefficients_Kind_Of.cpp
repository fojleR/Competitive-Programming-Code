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
    // int mat[11][11];
    // for(int n = 0; n <= 10; n++){
    //     mat[n][0] = 1;
    //     mat[n][n] = 1;
    //     for(int k = 1; k < n; k++){
    //         mat[n][k] = mat[n][k - 1] + mat[n - 1][k - 1];
    //     }
    // }
    // for(int i = 0; i <= 10; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll res[100005] = {0};
    res[0] = 1;
    for(int i = 1; i <= 100000; i++){
        res[i] = res[i - 1] * 2;
        res[i] %= mod;
    }
    int t;
    cin >> t;
    int N[t], K[t];
    for(int i = 0; i < t; i++){
        cin >> N[i];
    }
    for(int i = 0; i < t; i++){
        cin >> K[i];
    }

    for(int i = 0; i < t; i++){
        if(N[i] == K[i]){
            cout << 1 << endl;
        }
        else{
            cout << res[K[i]] << endl;
        }
    }

}


int main(){
    fast
    int t = 1;
    // cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}