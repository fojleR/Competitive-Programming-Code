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


ll zero(ll x){
    ll cnt = 0;
    while(x){
        if(x % 10 == 0){
            cnt++;
        }
        else break;
        x /= 10;
    }
    return cnt;

}
ll len(ll x){
    ll cnt = 0;
    while(x){
        cnt++;
        x /= 10;
    }
    return cnt;
}

void solve(){
    int n, m;
    cin >> n >> m;
    ll tot = 0;
    priority_queue< int > pq;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ll z = zero(x);
        ll l = len(x);
        pq.push(z);
        tot += l;
    }
    bool ok = true;
    //cout << tot << endl;
    //cout << pq.size() << endl;
    while(!pq.empty()){
        //cout << pq.top() << " ";
        if(ok){
            tot -= pq.top();
            ok = false;
        }
        else{
            ok = true;
        }
        pq.pop();
    }
    //cout << tot << endl;
    if(tot > m){
        cout << "Sasha" << endl;
    }
    else{
        cout << "Anna" << endl;
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