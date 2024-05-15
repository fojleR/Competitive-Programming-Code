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

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
void myerase(ordered_set &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    ordered_set st;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        st.insert(b[i]);
    }
    int i = 0, j = n - 1;
    int md = (n + 1) / 2;
    md--;
    // cout << *(st.find_by_order(md)) << endl;
    ll ans = *(st.find_by_order(md));
    while(i <= j){
        bool ok = false;
        myerase(st, b[i]);
        st.insert(a[i]);
        ll tm = *(st.find_by_order(md));
        if(tm >= ans){
            ans = tm;
            ok = true;
            i++;
        }
        else{
            myerase(st, a[i]);
            st.insert(b[i]);
        }
        myerase(st, b[j]);
        st.insert(a[j]);
        tm = *(st.find_by_order(md));
        if(tm >= ans){
            ans = tm;
            ok = true;
            j--;
        }
        else{
            myerase(st, a[j]);
            st.insert(b[j]);
        }
        if(!ok)break;

    }
    cout << ans << endl;

}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}