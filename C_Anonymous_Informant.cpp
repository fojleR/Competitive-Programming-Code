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
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int start = 0;
    int end = n - 1;

    for(int i = 0; i < min(n, k); i++){
        //cout << start << " " << end << endl;
        if(a[end] > n){
            cout << "No" << endl;
            return;
        }
        else{
            start = end - a[end] + 1;
            if(start < 0) start += n;
            end = start - 1;
            if(end < 0){
                end += n;
            }
        }
    }

    cout << "Yes" << endl;
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