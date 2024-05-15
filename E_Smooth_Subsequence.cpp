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

int par[500005];
int sz[500005];

void build(int node){
    par[node] = node;
    sz[node] = 1;
}

int find(int u){
        if(par[u] == u)return u;
        return par[u] = find(par[u]);
    }
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(sz[u] < sz[v])swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
}


// class dsu{
//     public:
//     vector< int > par, sz;
//     dsu(int n){
//         par.resize(n + 1);
//         sz.resize(n + 1);
//         for(int i = 1; i <= n; i++){
//             par[i] = i;
//             sz[i] = 1;
//         }
//     }
//     int find(int u){
//         if(par[u] == u)return u;
//         return par[u] = find(par[u]);
//     }
//     void merge(int u, int v){
//         u = find(u);
//         v = find(v);
//         if(u != v){
//             if(sz[u] < sz[v])swap(u, v);
//             par[v] = u;
//             sz[u] += sz[v];
//         }
//     }
// };

void solve(){
    ll n, d;
    cin >> n >> d;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        build(a[i]);
    }
    int ans = 1;
    set< int > st;
    
    for(int i = n - 1; i >= 0; i--){
        auto xx = st.lower_bound(a[i]);
        if(xx == st.end()){
            st.insert(a[i]);
            continue;
        }
        st.insert(a[i]);
        int x = *xx;
        cout << a[i] << " " << x << endl;
        if(x - a[i] <= d){
            merge(a[i], x);
        }
        ans = max(ans, sz[find(a[i])]);
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