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
int n, l, r;
string s;

class KMP{
    public:
    string A;
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        pi[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int frequency(string B){
        vector< int > pi = prefix_function(B);
        int i = 0, j = 0, cnt = 0;
        while(i < s.size()){
            if(s[i] == B[j]){
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = pi[j - 1];
                }
                else{
                    i++;
                }
            }
            if(j == B.size()){
                cnt++;
                j = 0;
            }
        }
        return cnt;
    }
};

bool check(string a, string b){
    if(b.size() == 0)return true;
    KMP kmp;
    kmp.A = a;
    if(kmp.frequency(b) >= l)return true;
    else return false;
}



void solve(){
    cin >> n >> l >> r;
    cin >> s;
    int ans = 0;
    int lo = 0, hi = n;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        string ss = s.substr(0, mid);
        if(check(s, ss)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
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