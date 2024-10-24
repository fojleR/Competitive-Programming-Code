#include <bits/stdc++.h>

using namespace std;

#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast            ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector, pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin >> a.first >> a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin >> x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout << a.first << ' ' << a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout << x << '\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }
// ===================================END Of the input module ==========================================
vector< pair< int, int > > check(vector< ll > prefixA, vector< ll > prefixB, vector< ll > prefixC, ll ave){
    vector< pair< int , int> > ans;
    int n = prefixA.size() - 1;
    // cout << n << endl;
    for (int i = 2; i < n; i++) {
        if (prefixA[i - 1] >= ave) {
            int ind = lower_bound(prefixB.begin() + i, prefixB.end(), prefixB[i - 1] + ave) - prefixB.begin();
            if(ind < n){
                if(prefixC[n] - prefixC[ind] >= ave){
                    ans.push_back({1, i - 1});
                    ans.push_back({i, ind});
                    ans.push_back({ind + 1, n});
                    return ans;
                }
            }
            
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    vector<ll> prefixA(n + 1, 0), prefixB(n + 1, 0), prefixC(n + 1, 0);
    ll suma = 0, sumb = 0, sumc = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma += a[i];
        prefixA[i] = prefixA[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sumb += b[i];
        prefixB[i] = prefixB[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sumc += c[i];
        prefixC[i] = prefixC[i - 1] + c[i];
    }
    
    ll ave = (suma + 2) / 3;
    // cout << ave << endl;
    vector< pair< int, int > > ans = check(prefixA, prefixB, prefixC, ave);
    if(ans.size() != 0){
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[2].first << " " << ans[2].second << endl;
        return;
    }
    ans = check(prefixA, prefixC, prefixB, ave);
    if(ans.size() != 0){
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[1].first << " " << ans[1].second << endl;
        return;
    }
    ans = check(prefixB, prefixA, prefixC, ave);
    if(ans.size() != 0){
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[2].first << " " << ans[2].second << endl;
        return;
    }
    ans = check(prefixB, prefixC, prefixA, ave);
    if(ans.size() != 0){
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[1].first << " " << ans[1].second << endl;
        return;
    }
    ans = check(prefixC, prefixA, prefixB, ave);
    if(ans.size() != 0){
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[0].first << " " << ans[0].second << endl;
        return;
    }
    ans = check(prefixC, prefixB, prefixA, ave);
    if(ans.size() != 0){
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[0].first << " " << ans[0].second << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while (t--) {
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}
