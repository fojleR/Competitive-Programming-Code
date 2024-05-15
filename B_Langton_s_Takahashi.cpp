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
    int n, m, p;
    cin >> n >> m >> p;
    char grid[n + 1][m + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            grid[i][j] = '.';
        }
    }
    int i = 0, j = 0;
    string direc = "up";
    while(p--){
        //cout << i << " " << j << endl;
        //cout << i << 
        if(direc == "up"){
            if(grid[i][j] == '.'){
               // cout << p << endl;
                grid[i][j] = '#';
                direc = "right";
                j++;
                j %= m;
            }
            else{
                grid[i][j] = '.';
                direc = "left";
                j--;
                j = (j + m) % m;
            }
            
        }
        else if(direc == "left"){
            if(grid[i][j] == '.'){
                grid[i][j] = '#';
                direc = "up";
                i--;
                i = (i + n) % n;
            }
            else{
                grid[i][j] = '.';
                direc = "down";
                i++;
                i %= n;
            }
        }
        else if(direc == "right"){
            if(grid[i][j] == '.'){
                grid[i][j] = '#';
                direc = "down";
                i++;
                i %= n;
            }
            else{
                grid[i][j] = '.';
                direc = "up";
                i--;
                i = (i + n) % n;
            }
        }
        else{
            if(grid[i][j] == '.'){
                grid[i][j] = '#';
                direc = "left";
                j--;
                j = (j + m) % m;

            }
            else{
                grid[i][j] = '.';
                direc = "right";
                j++;
                j %= m;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout <<grid[i][j];
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