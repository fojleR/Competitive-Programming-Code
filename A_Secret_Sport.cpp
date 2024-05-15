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
    set< char > v;
    for(int x = 1; x <= n; x++){
        int winA = 0,  winB = 0;
        int cntA = 0, cntB = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                cntA++;
            }
            else{
                cntB++;
            }
            if(cntA == x){
                winA++;
                cntA = 0;
                cntB = 0;
            }
            else if(cntB == x){
                winB++;
                cntA = 0;
                cntB = 0;
            }
        }
        //cout << x << " " << winA << " "<< winB << endl;
        if(winA > winB and s[n - 1] == 'A'){
            v.insert('A');
        }
        else if(winB > winA and s[n - 1] == 'B'){
            v.insert('B');
        }
    }

    if(v.size() == 2){
        cout << "?" << endl;
    }
    else{
        cout << *(v.begin()) << endl;
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