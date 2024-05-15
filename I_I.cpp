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


long long query(int start, int end, int left, int right,
                int node, long long seg[])
{
    if (end < left || start > right) {
        return 0;
    }
 
    else if (start >= left && end <= right) {
        return seg[node];
    }
 
    else {
        int mid = (start + end) / 2;
 
        long long leftChild = query(start, mid, left,
                                    right, 2 * node, seg);
 
        long long rightChild = query(mid + 1, end, left,
                                     right, 2 * node + 1, seg);
 
        return (leftChild | rightChild);
    }
}
 

void build(int left, int right, int node, int ar[],
           long long seg[])
{
    if (left == right) {
 
        seg[node] = (1LL << ar[left]);
 
        return;
    }
 
    int mid = (left + right) / 2;
 
    build(left, mid, 2 * node, ar, seg);
 
    build(mid + 1, right, 2 * node + 1, ar, seg);

    seg[node] = (seg[2 * node] | seg[2 * node + 1]);
}

int getDistinct(int l, int r, int n, ll seg[]){
    long long tempMask = query(0, n - 1, l - 1,r - 1, 1, seg);
    int countOfBits = 0;
    for (int i = 63; i >= 0; i--) {
        if (tempMask & (1LL << i)) {
            countOfBits++;
        }
    }
    return countOfBits;
}
 

void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    vector< int > v[m + 1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v[arr[i]].push_back(i);
    }
    long long seg[4 * n] = { 0 };
    build(0, n - 1, 1, arr, seg);
    ll ans = -1e9;
    for(int i = 1; i <= m; i++){
        int l = 1, r = n;
        // for(auto x: v[i]){
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << v[i].size() << endl;
        int dist;
        ll tm;
        if(v[i].size() != 0){
            for(int j = 1; j < v[i].size(); j++){
                l = v[i][j - 1] + 1;
                r = v[i][j] + 1;
                dist = getDistinct(l + 1, r - 1, n, seg);
                tm = dist - i;
                ans = max(ans, tm);
            }
            l = v[i][0] + 1;
            r = v[i].back() + 1;
        }
        else{
            l = 1;
            r = n;
            dist = getDistinct(1, n, n, seg);
            //cout << "xx " << dist << endl;
            tm = dist - i;
            ans = max(ans, tm);
            // continue;
        }
        //cout << i <<" " << l << " " << r << endl;
        
        //cout << "dist " << dist << endl;
        if(l - 1 >= 1){
            dist = getDistinct(1, l - 1, n, seg);
            tm = dist - i;
            ans = max(ans, tm);
        }
        if(r + 1 <= n){
            dist = getDistinct(r + 1, n, n, seg);
            tm = dist - i;
            ans = max(ans, tm);
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