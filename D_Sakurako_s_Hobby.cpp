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

class dsu{
    public:
        vector<int> parent, size, wt;
        int n;
        dsu(int n){
            this->n = n;
            parent.resize(n);
            size.resize(n);
            wt.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                size[i] = 1;
                wt[i] = 0;
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
                wt[x] += wt[y];
            }
        }
};

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    string s;
    cin >> s;
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    dsu d(n);
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            d.wt[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        d.unite(i, a[i]);
    }
    for(int i = 0; i < n; i++){
        cout << d.wt[d.find(a[i])] << " ";
    }
    cout << endl;
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