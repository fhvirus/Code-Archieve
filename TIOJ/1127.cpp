#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vector<bool>> to(8, vector<bool>(8, false));
  for (int i = 0; i < 8; ++i) {
    int j = (0b111 & (~i));
    to[i][j] = true;
    if ((j & 0b110) == 0) to[i][j | 0b110] = true;
    if ((j & 0b011) == 0) to[i][j | 0b011] = true;
  }

  const int kN = 42;
  vector dp(kN, vector<int64_t>(8));
  dp[1][0b100] = dp[1][0b111] = 1;

  for (int i = 1; i + 1 < kN; ++i) {
    for (int j = 0; j < 8; ++j) for (int k = 0; k < 8; ++k)
      if (to[j][k]) dp[i + 1][k] += dp[i][j];
  }

  int n;
  while (cin >> n)
    cout << dp[n][0b111] << '\n';

  return 0;
}
