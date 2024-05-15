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

vector< ll > ans(100002);
bool check(ll x, ll y, ll cmp){
    ll tm = x * x + y * y;
    tm = sqrt(tm);
    if(tm >= cmp){
        return false;
    }
    else return true;
}
bool check2(ll x, ll y, ll cmp){
    ll tm = x * x + y * y;
    tm = sqrt(tm);
    if(tm >= cmp){
        return true;
    }
    else return false;
}
ll findr(ll lo, ll hi, ll i, ll cmp){
    int mx = 0;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(check(i, mid, cmp + 1)){
            lo = mid + 1;
            mx = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    return mx;
}

ll findl(ll lo, ll hi, ll i, ll cmp){
    int mx = 0;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(check2(i, mid, cmp)){
            hi = mid - 1;
            mx = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return mx;
}
ll cal(ll x){
    ll tot = 0;
    for(int i = x; i <= x; i++){
        int mx = 0;
        ll lo = 0, hi = i;
        mx = findr(lo, hi, i, i);
        ll oneSide = (mx * 2 + 1);
        tot = oneSide * 4;
        if(i == mx){
            tot -= 4;
        }
        for(ll j = i - 1; j >= 1; j--){
            ll tm = j * j + j * j;
            tm = sqrt(tm);
            if(tm < i)break;
            lo = 0, hi = j;
            ll right = findr(lo, hi, j, i);
            lo = 0, hi = right;
            ll left = findl(lo, hi, j, i);
            //cout << "# " << j << " " << left << " " << right << endl;
            ll d = right - left + 1;
            ll oneSide = (d * 2);
            ll ttot = oneSide * 4;
            if(right == j){
                ttot -= 4;
            }
            tot += ttot;
        }
        //cout << i << " " << mx << " " << tot << endl;
    }
    return tot;
}
void solve(){
    int n;
    cin >> n;
    cout << cal(n) << endl;
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