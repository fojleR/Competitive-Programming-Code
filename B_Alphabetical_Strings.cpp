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
    char x = 'a' + (s.size() - 1);
    //cout << x << endl;
    int fst = 0, lst = s.size() - 1;
    for(int i = 0; i < s.size(); i++){
        if(x == s[fst]){
            fst++; x--; continue;
        }
        else if(x == s[lst]){
            lst--, x--;
            continue;
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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