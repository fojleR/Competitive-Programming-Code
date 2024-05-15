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
    int pos = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] > '4'){
            pos = i;
            break;
        }
    }

    if(pos == -1){
        cout << s << endl;
        return;
    }

    int pos2 = -1;

    for(int i = pos; i >=0; i--){
        if(s[i] < '4'){
            pos2 = i;
            break;
        }
    }

    if(pos2 == -1){
        string ans = "1" + string(s.size(), '0');
        cout << ans << endl;
        return;
    }

    s[pos2]++;

    for(int i = 0; i < s.size(); i++){
        if(i <= pos2)continue;
        else s[i] = '0';
    }

    cout << s << endl;
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