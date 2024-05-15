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
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    set< char > st;
    int cnt = 0;
    string ans = "";
    for(int i = 0; i < m; i++){
        st.insert(s[i]);
        if(st.size() == k){
            cnt++;
            st.clear();
            ans += s[i];
        }
    }
    if(cnt >= n){
        cout << "YES" << endl;
        return;
    }
    char x;
    for(int i = 0; i < k; i++){
        char xx = 'a' + i;
        if(st.count(xx) == 0){
            x = xx;
            break;
        }
    }
    cout << "NO" << endl;
    cout << ans;
    for(int i = 0; i < n - cnt; i++){
        cout << x;
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