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

set< int > st;

bool check(int x){
    if(st.find(x) != st.end())return true;
    int xx = x;
    while(xx){
        int d = xx % 10;
        xx /= 10;
        if(d != 0 and d != 1)return false;
    }
    return true;
}

void cal(){
    st.insert(1);
    for(int x = 2; x <= 100000; x++){
        int xx = x;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                if(check(i) and check(x / i)){
                    st.insert(x);
                    break;
                }
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    if(st.find(n) != st.end()){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    cal();
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}