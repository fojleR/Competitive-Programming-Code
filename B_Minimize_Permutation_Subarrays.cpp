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
    int a[n];
    int ind[n + 1] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ind[a[i]] = i;
    }
    if(ind[1] < ind[n] and ind[2] > ind[n]){
        cout << 1 << " " << 1 << endl;
    }
    else if(ind[1] > ind[n] and ind[2] < ind[n]){
        cout << 1 << " " << 1 << endl;
    }
    else{
        if(abs(ind[n] - ind[1]) < abs(ind[n] - ind[2])){
            cout << ind[1] + 1<< " " << ind[n] + 1<< endl;
        }
        else{
            cout << ind[2] + 1<< " " << ind[n] + 1<< endl;
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