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
    ll a, b, c;
    cin >> a >> b >> c;
    if(a < b)swap(a, b);
    ll dpos = 0;
    for(ll bit = 63; bit >= 0; bit--){
        if((a & (1LL << bit)) && !(b & (1LL << bit))){
            dpos = bit;
            break;
        }
    }
    //cout << dpos << endl;
    for(ll bit = dpos - 1; bit >= 0; bit--){
        if((a & (1LL << bit)) == (b & (1LL << bit))){
            continue;
        }
        // cout << bit << endl;
        // cout << (b & (1LL << bit)) << endl;
        if(!(b & (1LL << bit)) and ((1LL << bit) <= c)){
            //cout << bit << endl;
            b |= (1LL << bit);
            a ^= (1LL << bit);
            c -= (1LL << bit);
        }
        // cout << a << " " << b << endl;
    }
    cout << abs(a - b) << endl;
    //cout << a << " " << b << endl;
    // multiset< pair< int, int > > st;
    // for(int i = 0; i <= c; i++){
    //     //cout << i << " -:" << (a ^ i) << " " << (b ^ i ) <<((a ^ i) - (b ^ i )) << endl;
    //     int x = (a ^ i) - (b ^ i );
    //     st.insert({abs(x), i});
    // }
    // for(auto x : st){
    //     cout << x.first << " " << x.second << endl;
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