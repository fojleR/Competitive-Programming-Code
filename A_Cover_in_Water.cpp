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
    int cnt = 0, tot = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            cnt++;
            tot++;
            if(cnt >= 3){
                cout << 2 << endl;
                return;
            }
        }
        else{
            cnt = 0;
        }
    }
    cout << tot << endl;
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