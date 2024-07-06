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

vector< vector< int > > mat;
class dsu{
    public:
        vector<int> parent, size;
        int n;
        dsu(int n){
            this->n = n;
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 0;
            }
        }
        int find(int x){
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int x, int y){
            x = find(x);
            y = find(y);
            if(x != y){
                if(size[x] < size[y]) swap(x, y);
                parent[y] = x;
                size[x] += size[y];
            }
        }
};

void solve(){
    int n, m;
    cin >> n >> m;
    char matrix[n][m];
    int nn = n * m;
    mat = vector< vector< int > >(n, vector< int >(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = i * m + j + 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    
    dsu d(nn + 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '#'){
                // cout << mat[i][j] << endl;
                d.size[mat[i][j]] = 1;
            }
        }
        // cout << endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '#'){
                if(i + 1 < n && matrix[i + 1][j] == '#'){
                    d.unite(i * m + j + 1, (i + 1) * m + j + 1);
                }
                if(j + 1 < m && matrix[i][j + 1] == '#'){
                    d.unite(i * m + j + 1, i * m + j + 2);
                }
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         int par = d.find(mat[i][j]);
    //         cout << d.size[par] << " ";
    //     }
    //     cout << endl;
    // }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        set< int > unique;
        int tans = 0;
        for(int j = 0; j < m; j++){
            if(i - 1 >= 0){
                int par = d.find(mat[i - 1][j]);
                if(unique.find(par) == unique.end()){
                    unique.insert(par);
                    tans += (d.size[par]);
                }
            }
            if(i + 1 < n){
                int par = d.find(mat[i + 1][j]);
                if(unique.find(par) == unique.end()){
                    unique.insert(par);
                    tans += (d.size[par]);
                }
            }
            int par = d.find(mat[i][j]);
            if(unique.find(par) == unique.end()){
                tans += max(1, d.size[par]);
                unique.insert(par);
            }
        }
        ans = max(ans, tans);

    }
    for(int j = 0; j < m; j++){
        set< int > unique;
        int tans = 0;
        for(int i = 0; i < n; i++){
            if(j - 1 >= 0){
                int par = d.find(mat[i][j - 1]);
                if(unique.find(par) == unique.end()){
                    unique.insert(par);
                    tans += d.size[par];
                }
            }
            if(j + 1 < m){
                int par = d.find(mat[i][j + 1]);
                if(unique.find(par) == unique.end()){
                    unique.insert(par);
                    tans += (d.size[par]);
                }
            }
            int par = d.find(mat[i][j]);
            if(unique.find(par) == unique.end()){
                tans += max(d.size[par], 1);
                unique.insert(par);
            }
        }
        ans = max(ans, tans);
    }
    cout << ans << endl;
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