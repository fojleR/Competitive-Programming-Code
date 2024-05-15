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
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() < s2.size()){
        while(s1.size() < s2.size()){
            s1 = "0" + s1;
        }
    }
    ll ans = 0;
    for(int i = 0; i < s1.size(); i++){
        if(ans == 0){
            ans += int(s2[i] - s1[i]);
        }
        else{
            ans += 9;
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