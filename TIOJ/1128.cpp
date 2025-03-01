#include <bits/stdc++.h>
using namespace std;

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const double to[5][5] = {
  { 0, 1, 0, 0, 0 },
  { 0.2, 0.4, 0.2, 0.2, 0 },
  { 0, 0.3, 0.4, 0, 0.3 },
  { 0, 0.8, 0, 0.1, 0.1 },
  { 0, 0, 0.7, 0.3, 0 }
};
const double pr[5][2] = {
  { 0.2, 0.8 },
  { 0.8, 0.2 },
  { 0.6, 0.4 },
  { 0.3, 0.7 },
  { 0.6, 0.4 }
};

void dfs(const string& s, int N, int i, int st, double p, min_heap<double>& pq) {
  if ((int) pq.size() == N and p <= pq.top()) return;
  p *= pr[st][s[i] == 'B'];
  if (i == (int) s.size() - 1) {
    pq.emplace(p);
    if ((int) pq.size() > N) pq.pop();
    return;
  }
  for (int v = 0; v < 5; ++v) if (to[st][v] > 0)
    dfs(s, N, i + 1, v, p * to[st][v], pq);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  int N;

  while (cin >> s >> N) {
    min_heap<double> pq;
    dfs(s, N, 0, 0, 1.0, pq);

    if ((int) pq.size() < N) {
      cout << "No Solution\n";
      continue;
    }

    double ans = 0;
    for (; not pq.empty(); pq.pop()) ans += pq.top();
    
    cout << setprecision(8) << fixed << ans << '\n';
  }

  return 0;
}
