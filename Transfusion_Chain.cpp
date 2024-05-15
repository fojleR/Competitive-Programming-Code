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
    string a[n];
    map< string, int > mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        ans = max(ans, mp[a[i]]);
    }
    int ans1 = mp["O"] + mp["A"] + mp["AB"];
    int ans2 = mp["O"] + mp["B"] + mp["AB"];
    ans = max(ans1, ans2);
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