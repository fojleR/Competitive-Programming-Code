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
    int n;
    cin >> n;
    map< string, int > mp;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(!mp[s[i]]){
            string ss = s[i];
            string ans;
            ans += ss[ss.size() - 1];
            ans += ss[ss.size() - 2];
            reverse(ans.begin(), ans.end());
            mp[s[i]]++;
            cout << ans;
        }
    }
    cout << endl;
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