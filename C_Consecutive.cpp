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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int pre[n + 1] = {0};
    for(int i = 1; i < n; i++){
        pre[i] = pre[i - 1];
        if(s[i] == s[i - 1]){
            pre[i]++;
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << pre[i] << " ";
    // }

    while(q--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << pre[y] - pre[x] << endl;
    }
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