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
    int h, w, q;
    cin >> h >> w >> q;
    vector< vector< int > > v(h + 1, vector< int > (w + 1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            v[i][j] = -1;
        }
    }
    int left[h + 1], right[h + 1], up[w + 1], down[w + 1];
    for(int i = 1; i <= h; i++){
        left[i] = -1;
        right[i] = -1;
    }
    for(int i = 1; i <= w; i++){
        up[i] = -1;
        down[i] = -1;
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        if(v[x][y] == -1){
            v[x][y] += 1;
            left[x] += 1;
            right[x] += 1;
            up[y] += 1;
            down[y] += 1;
        }
        else{
            int yy = left[x];
            while(yy >= 1 and v[x][yy] != -1){
                yy--;
            }
            if(yy >= 1){
                v[x][yy] += 1;
                left[x] = yy - 1;
            }
            yy = right[x];
            while(yy <= w and v[x][yy] != -1){
                yy++;
            }
            if(yy <= w){
                v[x][yy] += 1;
                right[x] = yy + 1;
            }
            int xx = up[y];
            while(xx >= 1 and v[xx][y] != -1){
                xx--;
            }
            if(xx >= 1){
                v[xx][y] += 1;
                up[y] = xx - 1;
            }
            xx = down[y];
            while(xx <= h and v[xx][y] != -1){
                xx++;
            }
            if(xx <= h){
                v[xx][y] += 1;
                down[y] = xx + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(v[i][j] == -1){
                ans++;
            }
        }
    }
    cout << ans << endl;
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