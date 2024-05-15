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
    int n, m;
    cin >> n >> m;
    set< int > lis[m + 1];
    set< int > st;
    vector< int > ans;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                int a = i;
                int b = x / i;
                if(a <= m){
                    lis[a].insert(x);
                }
                if(b <= m){
                    lis[b].insert(x);
                }
            }
        }
    }
    for(int i = 1; i <= m; i++)st.insert(i);
    bool first = true;
    for(int i = m; i >= 1; i--){
        if(st.count(i)){
            if(!lis[i].empty()){
                int xx = *(lis[i].rbegin());
                st.erase(i);
                ans.push_back(xx);
                for(int j = 1; j * j <= xx; j++){
                    if(xx % j == 0){
                        if(st.count(j))st.erase(j);
                        if(st.count(xx/j))st.erase(xx/j);
                    }
                }
            }
        }
    }
    if(!st.empty()){
        cout << -1 << endl;
        return;
    }
    sort(ans.begin(), ans.end());
    cout << ans.back() - ans[0] << endl;
    //cout << ans << endl;
    // for(int i = 1; i <= m; i++){
    //     cout << i << ": ";
    //     for(auto x: lis[i]){
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
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