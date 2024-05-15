#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool ok = true;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            ok = false;
        }
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else{
        ok = true;
        for(int i = 0; i < m - 1; i++){
            if(t[i] == t[i + 1]){
                cout << "No" << endl;
                return;
            }
        }
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                if(t[0] == s[i] || t[m - 1] == s[i + 1]){
                    cout << "No" << endl;
                    return;
                }
            }
        }
        cout << "Yes" << endl;
    }
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