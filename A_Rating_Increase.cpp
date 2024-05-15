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
    string a, b;
    bool ok = false;
    for(int i = 0; i < s.size(); i++){
        if((i != 0 and s[i] != '0') || ok){
            b += s[i];
            ok = true;
        }
        else{
            a += s[i];
        }
    }
    ll xx = 0, yy = 0, p = 1;
    for(int i = 0; i < a.size(); i++){
        xx *= 10;
        xx += (a[i] - '0');
    }
    p = 1;
    for(int i = 0; i < b.size(); i++){
        yy *= 10;
        yy += (b[i] - '0');
    }
    if(xx >= yy){
        cout << -1 << endl;
    }
    else{
        cout << xx << " " <<  yy << endl;
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