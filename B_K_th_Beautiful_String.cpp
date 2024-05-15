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
    int tot = 0;
    int pos = 0;
    while(1){
        if(tot + pos + 1 >= m){
            break;
        }
        pos++;
        tot += pos;
    }
    pos++;
    char ans[n + 1];
    for(int i = 0; i <= n; i++) ans[i] = 'a';
    ans[n - pos] = 'b';
    pos = m - tot;
    ans[n - pos + 1] = 'b';
    for(int i = 1; i <= n; i++){
        cout << ans[i];
    }
    cout << endl;
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