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
    string s1, s2;
    cin >> s1 >> s2;
    int mov1 = 0, mov2 = 0;
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i]){
            mov1++;
        }
    }
    reverse(s2.begin(), s2.end());
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i]){
            mov2++;
        }
    }
    int ans1, ans2;
    if(mov1 % 2){
        ans1 = mov1 + mov1 - 1;
    }
    else{
        ans1 = mov1 + mov1;
    }
    if(mov2 % 2){
        ans2 = mov2 + mov2;
    }
    else{
        ans2 = max(2, mov2 + mov2 - 1);
    }
    //cout << ans1 << " " << ans2 << endl;
    cout << min(ans1, ans2) << endl;
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