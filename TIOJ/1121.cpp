#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int N;
  while (cin >> N) {
    string s;
    cin >> s;
    s = s + s;

    vector<int> ord(N);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int u, int v) {
        return s.substr(u, N) < s.substr(v, N); });

    for (int i : ord) cout << s[i + N - 1];
    cout << '\n' << (int) (find(begin(ord), end(ord), 1) - begin(ord)) + 1 << '\n';
  }

  return 0;
}
