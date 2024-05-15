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
    int n, c, d;
    cin >> n >> c >> d;
    vector< int > v, ans;
    int mat[n][n];
    mat[0][0] = 1;
    for(int i = 0; i < n * n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    mat[0][0] = v[0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 < n)mat[i + 1][j] = mat[i][j] + c;
            if(j + 1 < n)mat[i][j + 1] = mat[i][j] + d;
            ans.push_back(mat[i][j]);
            //cout << mat[i][j] << " ";
        }
        // cout << endl;
    }
    sort(v.begin(), v.end());
    sort(ans.begin(), ans.end());
    if(v == ans){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
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