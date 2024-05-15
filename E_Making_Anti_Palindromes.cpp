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
    if(n % 2){
        cout << -1 << endl;
        return;
    }
    set< pair< int, char > > problem_set; // storing the charters which are making problem right now
    set< char > st;
    map< char, int > pbCnt;
    map< char, set< int > > mp;
    for(int i = 0; i < n / 2; i++){
        if(s[i] == s[n - i - 1]){
            pbCnt[s[i]]++;
            if(pbCnt[s[i]] > n / 2){
                cout << -1 << endl;
                return;
            }
            mp[s[i]].insert(i);
            st.insert(s[i]);
        }
    }
    for(auto it = pbCnt.begin(); it != pbCnt.end(); it++){
        int cnt = it->second;
        if(cnt){
            problem_set.insert({cnt * -1, it->first});
        }
    }
    int ans = 0;
    // cout << problem_set.size() << endl;
    // for(auto it = problem_set.begin(); it != problem_set.end(); it++){
    //     cout << it->first << " " << it->second << endl;
    // }
    while(!problem_set.empty()){
        auto it = problem_set.begin();
        char first = it->second;
        int first_cnt = it->first * -1;
        int first_id = *(mp[first].begin());
        


        it = problem_set.end();
        it--;
        char second = it->second;
        int second_cnt = it->first * -1;
        int second_id = *(mp[second].begin());
        
        //cout << first_id << " " << second_id << endl;

        if(first == second){
            break;
        }
        mp[first].erase(mp[first].find(first_id));
        mp[second].erase(mp[second].find(second_id));

        ans++;
        first_cnt--;
        second_cnt--;
        problem_set.erase(problem_set.begin());
        if(first_cnt > 0){
            problem_set.insert({first_cnt * -1, first});
        }
        if(!problem_set.empty()){
            problem_set.erase(it);
            if(second_cnt > 0)
                problem_set.insert({second_cnt * -1, second});
        }
        
        swap(s[first_id], s[second_id]);
    }
    mp.clear();
    for(int i = 0; i < n / 2; i++){
        int first = i, second = n - i - 1;
        for(char c = 'a'; c <= 'z'; c++){
            if(c == s[first] || c == s[second])continue;
            mp[c].insert(i);
        }
    }
    multiset< pair< char, int > > problem_set2;
    for(int i = 0; i < n / 2; i++){
        if(s[i] == s[n - i - 1]){
            problem_set2.insert({s[i], i});
        }
    }
    for(auto it = problem_set2.begin(); it != problem_set2.end(); it++){
        char c = it->first;
        char id = it->second;
        if(mp[c].size() == 0){
            cout << -1 << endl;
            return;
        }
        ans++;
        for(char c = 'a'; c <= 'z'; c++){
            if(mp[c].find(id) != mp[c].end()){
                mp[c].erase(mp[c].find(id));
            }
        }
    }
    cout << ans << endl;
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