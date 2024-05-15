#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
ll h, w, xa, ya, xb, yb;

bool valid_move(int hh, int ww){
    if(hh < 1 || hh > h || ww < 1 || ww > w) return false;
    else return true;
}

void solve(){
     // x for height
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa >= xb){
        cout << "Draw" << endl;
        return;
    }
    int move = xb - xa;
    if(move < abs(ya - yb)){
        cout << "Draw" << endl;
        return;
    }
    int imove = move / 2;
    ll rxa, rya, rxb, ryb, lxa, lxb, lya, lyb;
    if(move % 2){
        bool ok = true;
        rxa = xa + imove; rxa = min(rxa, h);
        rya = ya + imove; rya = min(rya, w);
        rxb = xb - imove; rxb = max(rxb, 1LL);
        ryb = yb + imove; ryb = min(ryb, w);
        // cout << rxa << " " << rya << " " << rxb << " " << ryb << endl;
        if(valid_move(rxb, ryb) and ryb - 1> rya) ok = false;
        rxa = xa + imove; rxa = min(rxa, h);
        rya = ya - imove; rya = max(rya, 1LL);
        rxb = xb - imove; rxb = max(rxb, 1LL);
        ryb = yb - imove; ryb = max(ryb, 1LL);
        if(valid_move(rxb, ryb) and ryb < rya - 1) ok = false;
        if(!ok){
            cout << "Draw" << endl;
        }
        else{
            cout << "Alice" << endl;
        }
    }
    else{
        bool ok = true;
        rxa = xa + imove; rxa = min(rxa, h);
        rya = ya + imove; rya = min(rya, w);
        rxb = xb - imove; rxb = max(rxb, 1LL);
        ryb = yb + imove; ryb = min(ryb, w);
        // cout << rxa << " " << rya << " " << rxb << " " << ryb << endl;
        if(valid_move(rxb, ryb) and ryb < rya) ok = false;
        rxa = xa + imove; rxa = min(rxa, h);
        rya = ya - imove; rya = max(rya, 1LL);
        rxb = xb - imove; rxb = max(rxb, 1LL);
        ryb = yb - imove; ryb = max(ryb, 1LL);
        if(valid_move(rxb, ryb) and ryb > rya) ok = false;
        if(ok){
            cout << "Bob" << endl;
        }
        else{
            cout << "Draw" << endl;
        }
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