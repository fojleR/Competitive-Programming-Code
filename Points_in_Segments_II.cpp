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
    int n, q;
    cin >> n >> q;
    vector< pair< int, int > > v, qr, ans;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        qr.push_back({x, i});
    }
    sort(v.begin(), v.end());
    sort(qr.begin(), qr.end());
    priority_queue< int, vector< int > , greater<int> > pq;
    int i = 0;
    for(int j = 0; j < q; j++){
        while(i < n and j < q and v[i].first <= qr[j].first){
            pq.push(v[i].second);
            i++;
        }
        while(!pq.empty() and pq.top() < qr[j].first){
            pq.pop();
        }
        ans.push_back({qr[j].second, pq.size()});
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans){
        cout << x.second << endl;
    }
    
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": " << endl;
        solve();
    }
    return 0;
}