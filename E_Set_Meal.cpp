#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int N, M, L;
  cin >> N >> M >> L;
  vector<int> a(N), b(M);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;
  set<pair<int, int>> bad;
  for (int i = 0; i < L; i++) {
    int c, d;
    cin >> c >> d;
    bad.emplace(c - 1, d - 1);
  }

  vector<int> ord_b(M);
  for (int i = 0; i < M; i++) ord_b[i] = i;
  sort(begin(ord_b), end(ord_b), [&](int i, int j) { return b[i] > b[j]; });
//   for(auto x: ord_b){
//     cout << x << endl;
//   }
  vector<int> cur(N);
  priority_queue<pair<int, int>> Q;
  for (int i = 0; i < N; i++) Q.emplace(a[i] + b[ord_b[cur[i]]], i);
  while (true) {
    auto [cost, i] = Q.top();
    int j = cur[i];
    Q.pop();
    if (bad.count({i, ord_b[j]}) == 0) {
      cout << cost << "\n";
      break;
    }
    cur[i]++;
    if (cur[i] != M) Q.emplace(a[i] + b[ord_b[cur[i]]], i);
  }
}
