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
    string s;
    cin >> s;
    int cnt[27] = {0};
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        cnt[x]++;
        mx = max(mx, cnt[x]);
    }
    int nd = n - mx;
    if(n % 2){
        cout << max(1, mx - nd) << endl;
    }
    else{
        cout << max(0, mx - nd) << endl;
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