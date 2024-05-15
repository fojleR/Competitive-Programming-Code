#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

bool check(string s){
    int n = s.size();
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1]){
            return false;
        }
    }
    return true;
}


void solve(){
    int n;
    cin >> n;
    vector< string > v;
    for(int i = 0; i < n; i++){
        string xx;
        cin >> xx;
        if(v.size()){
            for(auto x : v){
                string ss = x + xx;
                if(check(ss)){
                    cout << "Yes" << endl;
                    return;
                }
                ss = xx + x;
                if(check(ss)){
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        v.push_back(xx);
    }
    cout << "No" << endl;
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