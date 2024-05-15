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
    int n;
    cin >> n;
    int a[n];
    set< int > st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    if(st.size() == 1){
        cout << -1 << endl;
        return;
    }
    for(int i = 1; i < n - 1; i++){
        if(a[i] != a[0]){
            if(a[i - 1] == a[0] and a[i + 1] == a[0])continue;
            else{
                cout << 0 << endl;
                return;
            }
        }
    }
    int ans = 0;
    int cnt = n;
    int tm = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == a[0])tm++;
        else{
            cnt = min(cnt, tm);
            tm = 0;
        }
    }
    if(tm)
        cnt = min(cnt, tm);
    cout << cnt << endl;
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