#include <bits/stdc++.h>
using namespace std;

int N, Q;

long long current_answer;
long long cnt[100];
string s, ss;

long long answers[100500];
int BLOCK_SIZE;
int arr[100500];

pair< pair<int, int>, int> queries[100500];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

// When adding a number, we first nullify it's effect on current
// answer, then update cnt array, then account for it's effect again.
inline void add1(int x)
{
    cout << x << endl;
    if(s[x] == '0') ss = '0' + ss;
    else ss = ss + '1';
    //cout << ss << endl;
}

inline void add2(int x)
{
    cout << x << endl;
    if(s[x] == '0') ss = '0' + ss;
    else ss = ss + '1';
    //cout << ss << endl;
}

// Removing is much like adding.
inline void remove1(int x)
{
    cout << x << " " << s[x] << endl;
    if(s[x] == 0){
        ss.erase(ss.begin());
    }
    else{
        auto it = ss.end();
        it--;
        ss.erase(it);
    }
    //cout << ss << endl;
}

inline void remove2(int x)
{
    cout << x << " " << s[x] << endl;
    if(s[x] == 0){
        ss.erase(ss.begin());
    }
    else{
        auto it = ss.end();
        it--;
        ss.erase(it);
    }
    //cout << ss << endl;
}

void solve()
{   ss = "";
    cin >> N >> Q;
    BLOCK_SIZE = static_cast<int>(sqrt(N));
    cin >> s;
    set< string > st;
    for(int i = 0; i < Q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }

    sort(queries, queries + Q, mo_cmp);
    int mo_left = 0, mo_right = -1;

    for(int i = 0; i < Q; i++) {
        //[left, right] is what query we must answer now.
        int left = queries[i].first.first;
        int right = queries[i].first.second;
        cout << left << " " << right << endl;
        string l = s.substr(0, left - 1);
        string r = s.substr(right, N - right);
        // Usual part of applying Mo's algorithm: moving mo_left
        // and mo_right.
        while(mo_right < right) {
            mo_right++;
            add1(mo_right);
        }
        while(mo_right > right) {
            remove1(mo_right);
            mo_right--;
        }

        while(mo_left < left) {
            remove2(mo_left);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add2(mo_left);
        }
        // sort(mid.begin(), mid.end());
        //cout << l << " " << ss << " " << r << endl;
        string res = l + ss + r;
        st.insert(res);
        cout << res << endl;
        // Store the answer into required position.
        
    }
    cout << st.size() << endl;

    // We output answers *after* we process all queries.
    return ;
}

int main(){
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}