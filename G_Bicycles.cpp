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
vector< pair< ll, ll > > lis[1005];
ll arr[1005];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        lis[i].clear();
    }
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        lis[x].push_back({y, w});
        lis[y].push_back({x, w});
    }
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    priority_queue< pair< ll, pair< ll, ll > >, vector< pair< ll, pair< ll, ll > > >, greater< pair< ll, pair< ll, ll > > > > pq;
    pq.push({0, {1, arr[1]}});
    vector< vector<ll > > vis(n + 1, vector< ll > (1005, 0));
    while(!pq.empty()){
        pair< ll, pair< ll, ll> > p = pq.top();
        pq.pop();
        //cout << p.first << " " << p.second.first << " " << p.second.second << endl;
        if(p.second.first == n){
            cout << p.first << endl;
            return;
        }
        // cout << 
        if(vis[p.second.first][p.second.second])continue;
        vis[p.second.first][p.second.second] = 1;
        for(auto x: lis[p.second.first]){
            ll new_wight = min(p.second.second, arr[x.first]);
            ll new_cost = p.first + p.second.second * x.second;
            pq.push({new_cost, {x.first, new_wight}});
        }
    }
    cout << -1 << endl; 
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