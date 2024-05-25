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
    for(int i = 0; i < n; i++) cin >> a[i];
    stack< int > st1, st2;
    int start = 0;
    for(int i = 0; i < n; i++){
        while(st1.size() > 1 && st1.top() > a[i]){
            int vl = st1.top();
            st1.pop();
            if(st1.top() <= vl){
                st2.pop();
            }
            else{
                st1.push(vl);
                break;
            }
        }
        st1.push(a[i]);
        st2.push(i);
    }
    ll lst = st1.top();
    st1.pop();
    ll j = st2.top();
    st2.pop();
    ll ans = 0;
    //cout << lst << " " << j << endl;
    while(!st1.empty()){
        ll vl = st1.top();
        st1.pop();
        ll i = st2.top();
        //cout << vl << " " << i << endl;
        st2.pop();
        ans += (j - i) * max(lst, vl);
        lst = vl;
        j = i;
        //cout << ans << endl;
    }
    cout << ans << endl;
    
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