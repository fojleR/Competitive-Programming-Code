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
    int A_block = 0;
    int cntB = 0;
    int cntA = 0;
    int cnsB = 0;
    char pre = 'Z';
    int mn = INT_MAX;
    int tm = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            cntA++;
            tm++;
            if(pre != 'A'){
                A_block++;
            }
            pre = 'A';
        }
        else{
            if(tm) mn = min(mn, tm);
            tm = 0;
            cntB++;
            if(pre == 'B')cnsB = 1;
            pre = 'B';
        }
    }
    if(tm) mn = min(mn, tm);
    //cout << cntA << endl;
    if(cnsB){
        cout << cntA << endl;
        return;
    }
    if(cntA == 0 || cntB == 0){
        cout << 0 << endl;
        return;
    }
    if(cntB >= A_block){
        cout << cntA << endl;
        return;
    }
    else{
        cout << cntA - mn << endl;
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