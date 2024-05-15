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
    stack< char > st;
    int ok = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            if(ok){
                while(st.top() != '(') st.pop();
                st.pop();
                ok--;
            }
            else{
                st.push(')');
            }
        }
        else if(s[i] == '('){
            ok++;
            st.push(s[i]);
        }
        else{
            st.push(s[i]);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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