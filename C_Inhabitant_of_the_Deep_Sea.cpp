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
    ll n, k;
    cin >> n >> k;
    deque< ll > dq;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int ans = 0;
    while(!dq.empty()){
        if(dq.size() == 1){
            int xx = dq.front();
            if(xx <= k){
                k-=xx;
                dq.pop_front();
                ans++;
            }
            else{
                break;
            }
        }
        else{
            int fst = dq.front();
            int lst = dq.back();
            int mn = min(fst, lst) * 2;
            // cout << mn << " " << k << endl;
            if(fst <= lst){
                if(mn - 1 <= k){
                    k -= mn;
                    dq.pop_front();
                    dq.pop_back();
                    dq.push_back(lst - fst);
                    ans++;
                }
                else{
                    break;
                }
            }
            else{
                if(mn <= k){
                    k -= mn;
                    dq.pop_front();
                    dq.pop_back();
                    dq.push_front(fst - lst);
                    ans++;
                }
                else{
                    break;
                }
            }
        }
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