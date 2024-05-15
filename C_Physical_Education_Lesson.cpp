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
    ll n, x;
    cin >> n >> x;
    ll n1 = n - x;
    ll n2 = n + x - 2;
    set< ll > st;
    // cout << n1 << endl;
    // if(n1)
    //cout << n1 << " " << n2 << endl;
    for(int i = 1; i * i <= n1; i++){
        if(n1 % i == 0){
            ll tm = i + 2;
            //cout << tm << endl;
            if(tm % 2 == 0 and tm <= n){
                st.insert(tm/2);
            }
            ll tm2 = n1 / i + 2;
            if(tm2 % 2 == 0 and tm2 <= n){
                st.insert(tm2/2);
            }
        }
    }
    
    for(int i = 1; i * i <= n2; i++){
        if(n2 % i == 0){
            ll tm = i + 2;
            if(tm % 2 == 0 and tm / 2 <= n){
                st.insert(tm/2);
            }
            ll tm2 = n2 / i + 2;
            //cout << tm2 << endl;
            if(tm2 % 2 == 0 and tm2 / 2 <= n){
                if(tm2 <= n)
                    st.insert(tm2/2);
            }
        }
    }
    for(auto x: st){
        cout << x << " ";
    }
    cout << endl;
    cout << st.size() << endl;
    // cout << n << endl;
    // for(auto x: st){
    //     cout << x << " ";
    // }
    // cout << endl;

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