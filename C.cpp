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
int n, k;
vector< int > lis[mx];
bool vis[mx];
int wt[mx];
int tmx = 0, tmk = 0;

void dfs(int node){
    vis[node] = true;
    wt[node] = 1;
    for(auto child: lis[node]){
        if(!vis[child]){
            dfs(child);
            wt[node] += wt[child];
        }
    }
    if(wt[node] >= tmx){
        tmk++;
        wt[node] = 0;
    }
}

void solve(){
    for(int i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = 0;
        wt[i] = 0;
    }
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        lis[x].push_back(y);
        lis[y].push_back(x);
    }
    int lo = 1, hi = n;
    ll ans = 1;
    // tmx = 3;
    // dfs(1);
    // cout << tmk << endl;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        tmx = mid;
        tmk = 0;
        for(int i = 0; i <= n; i++){
            vis[i] = false;
            wt[i] = 0;
        }
        dfs(1);
        if(tmk > k){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    
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