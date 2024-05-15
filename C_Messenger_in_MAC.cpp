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
    ll n, l;
    cin >> n >> l;
    vector< pair< ll, ll > > v(n);
    ll ans = 0;
    ll mat[n + 1][n + 1];
    ll mat2[n + 1][n + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            mat[i][j] = 1e18;
            mat2[i][j] = 1e18;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        if(v[i].first <= l){
            ans = 1;
        }
    }
    priority_queue< pair< ll, pair< ll, ll > > > pq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            ll tr = v[i].first + v[j].first + abs(v[i].second - v[j].second);
            pq.push({-tr, {i, j}});
            mat[i][j] = tr;
            mat2[i][j] = tr;
        }
    }
    int st1 = -1, st2 = -1;
    if(!pq.empty() and pq.top().first * - 1 <= l){
        ans = 2;
        st1 = pq.top().second.first;
        st2 = pq.top().second.second;
        l -= (pq.top().first * -1); 
    }
    ll ans1 = ans, ans2 = ans;
    if(st1 == -1){
        cout << ans << endl;
        return;
    }
    ll l2 = l;
    mat[st1][st2] = l + 1;
    mat[st2][st1] = l + 1;
    //cout << st1 << " " << st2 << endl;
    // cout << l << endl;
    while(l > 0){
        cout << "%%" << l << endl;
        ll newl = 1e9;
        ll newst = -1;
        for(int i = 0; i < n; i++){
            if(mat[st2][i] - v[st2].first < newl and i != st2){
                newl = mat[st2][i] - v[st2].first;
                newst = i;
            }
        }
        if(newl > l){
            break;
        }
        ans1 ++;
        l -= newl;
        mat[st2][newst] = l + 1;
        mat[newst][st2] = l + 1;
        st2 = newst;
    }
    mat2[st1][st2] = l + 1;
    mat2[st2][st1] = l + 1;
    l = l2;
    st2 = st1;
    while(l > 0 and pq.size() > 0){
        //cout << "%%" << l << endl;
        ll newl = 1e9;
        ll newst = -1;
        for(int i = 0; i < n; i++){
            if(mat[st2][i] - v[st2].first < newl){
                newl = mat2[st2][i] - v[st2].first;
                newst = i;
            }
        }
        if(newl > l){
            break;
        }
        ans2 ++;
        l -= newl;
        mat[st2][newst] = l + 1;
        mat[newst][st2] = l + 1;
        st2 = newst;
    }
    cout << max(ans2, ans1) << endl;
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