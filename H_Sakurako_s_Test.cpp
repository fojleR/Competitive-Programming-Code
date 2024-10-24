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
    vector< int > v(n);
    vector< int > c(n + 1, 0), res(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        c[v[i]]++;
    }
    for(int i = 1; i <= n; i++){
        c[i] += c[i - 1];
    }
    for(int x = 1; x <= n; x++){
        int l = 0, r = x;
        while(l < r){
            int mid = (l + r) / 2;
            int cnt = c[mid];
            for(int k = 1; k * x <= n; k++){
                cnt += c[min(k * x + mid, n)] - c[k * x - 1];
            }
            if(cnt - 1>= n / 2){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        res[x] = l;
        
    }
    while(q--){
        int x;
        cin >> x;
        cout << res[x] << " ";
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