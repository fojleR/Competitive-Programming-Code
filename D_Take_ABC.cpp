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
    string str;
    int n = s.size();
    for(int i = 0; i < n; i++){
        str += s[i];
        if(str.size() < 3)continue;
        int sz = str.size();
        if(str[sz - 1] == 'C' and str[sz - 2] == 'B' and str[sz - 3] == 'A'){
            for(int i = 0; i < 3; i++){
                str.pop_back();
            }
        }
    }
    cout << str << endl;
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