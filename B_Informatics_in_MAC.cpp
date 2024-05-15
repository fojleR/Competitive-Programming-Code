#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds; 


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
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 



int MEX(ordered_set st){
    int mex = 0;
    int lo = 0, hi = st.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(*st.find_by_order(mid) == mid){
            mex = mid + 1;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return mex;
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    int cnt1[n + 2] = {0}, cnt2[n + 2] = {0};
    int mex1 = 0, mex2 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt1[a[i]]++;
        if(cnt1[mex1]){
            while(cnt1[mex1]){
                mex1++;
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        int x = a[i];
        cnt2[x]++;
        if(cnt2[mex2]){
            while(cnt2[mex2]){
                mex2++;
            }
        }
        cnt1[x]--;
        if(cnt1[x] == 0){
            mex1 = min(mex1, x);
        }
        if(mex1 == mex2){
            cout << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            return;
        }
    }
    cout << -1 << endl;
    

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