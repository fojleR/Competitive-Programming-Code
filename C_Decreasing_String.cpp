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
    string s;
    cin >> s;
    int n;
    cin >> n;
    int curtot = s.size();
    int cur = curtot;
    int track[n] = {0};
    int curpos = 0;
    while(curtot < n){
        while(curpos + 1 < n and s[curpos] <= s[curpos + 1]){
            track[curpos] = 1;
            curpos++;
        }
        if(curpos < n - 1)
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