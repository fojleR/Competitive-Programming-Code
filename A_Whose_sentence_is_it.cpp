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
    getline(cin, s);
    //cout << s << endl;
    bool f = false, r = false;
    if(s.size() < 5){
        cout << "OMG>.< I don't know!" << endl;
        return;
    }
    if(s.substr(0, 5) == "miao."){
        r = true;
    }
    int x = s.size() - 5;
    //cout << s.substr(x, 5) << endl;
    //cout << f << " " << r << endl;
    if(s.substr(x, 5) == "lala."){
        f = true;
    }
    if(f and r){
        cout << "OMG>.< I don't know!" << endl;
    }
    else if(!f and !r){
        cout << "OMG>.< I don't know!" << endl;
    }
    else if(f){
        cout << "Freda's" << endl;
    }
    else{
        cout << "Rainbow's" << endl;
    }
}


int main(){
    fast
    int t = 1;
    cin >> t;
    cin.ignore();
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}