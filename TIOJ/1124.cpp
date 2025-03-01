#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  const vector<tuple<char, char, double>> es = {
    { 'A', 'B', 0.30 },
    { 'A', 'C', 0.67 },
    { 'A', 'D', 0.50 },
    { 'B', 'F', 0.33 },
    { 'C', 'D', 0.42 },
    { 'C', 'G', 0.10 },
    { 'D', 'F', 0.54 },
    { 'D', 'J', 0.28 },
    { 'E', 'H', 0.50 },
    { 'F', 'E', 0.28 },
    { 'F', 'I', 0.20 },
    { 'G', 'I', 0.23 },
    { 'G', 'J', 0.36 },
    { 'H', 'L', 0.40 },
    { 'I', 'L', 0.41 },
    { 'J', 'L', 0.37 },
    { 'J', 'N', 0.47 },
    { 'L', 'N', 0.50 },
  };
  const string ord = "ABCDFEGHIJLN";
  const int kN = 'N' - 'A' + 1;

  vector can(kN, vector<bool>(kN));
  vector prob(kN, vector<double>(kN));
  for (int i = 0; i < kN; ++i) {
    can[i][i] = true;
    prob[i][i] = 1;
    for (char c : ord) {
      int u = c - 'A';
      if (not can[i][u]) continue;
      for (auto [a, b, w] : es) if (a == c) {
        int v = b - 'A';
        can[i][v] = true;
        prob[i][v] += prob[i][u] * w;
      }
    }
  }

  char s, t;
  int e;
  while (cin >> s >> t >> e) {
    e -= 1;
    int a = s - 'A', b = get<0>(es[e]) - 'A';
    int c = get<1>(es[e]) - 'A', d = t - 'A';

    if (not (can[a][b] and can[c][d])) {
      cout << "No solution\n";
      continue;
    }

    cout << setprecision(8) << fixed;
    cout << (prob[a][b] * get<2>(es[e]) * prob[c][d]) / prob[a][d] << '\n';
  }

  return 0;
}
