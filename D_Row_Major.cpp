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
    char st = 'a';
    string s;
    bool ok = false;
    for(int i = 1; i <= n; i++){
        if(!ok){
            s += st;
            st++;
        }
        if(n % i){
            ok = true;
        }
    }
    int pos = 0;
    int tot = s.size();
    string ans;
    for(int i = 0; i < n; i++){
        ans += s[pos % tot];
        pos++;
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