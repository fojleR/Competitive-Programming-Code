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

ll n, k, pb, ps;
ll p[mx], a[mx];

ll check(ll st){
    ll tk = k;
    ll ans = 0;
    ll tm = 0;
    set< int > stt;
    while(tk){
        stt.insert(st);
        ll tcal = tm + a[st] * tk;
        ans = max(ans, tcal);
        tk--;
        tm += a[st]; 
        st = p[st];
        if(stt.find(st) != stt.end()){
            break;
        }
    }
    return ans;
}

void solve(){
    cin >> n >> k >> pb >> ps;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll bod = check(pb);
    ll sas = check(ps);
    if(bod > sas){
        cout << "Bodya" << endl;
    }
    else if(sas > bod){
        cout << "Sasha" << endl;
    }
    else{
        cout << "Draw" << endl;
    }
    
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