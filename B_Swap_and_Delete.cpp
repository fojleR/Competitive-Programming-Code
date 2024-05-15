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
    int cnt0 = 0, cnt1= 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0')cnt0++;
        else cnt1++;
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' and cnt1){
            cnt1--;
        }
        else if(s[i] == '1' and cnt0){
            cnt0--;
        }
        else{
            cout << s.size() - i << endl;
            return;
        }
    }
    cout << 0 << endl;
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