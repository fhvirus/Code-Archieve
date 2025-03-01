#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while (T --> 0) {
    int C;
    cin >> C;

    int64_t sum = 0;
    for (int i = 0; i < C; ++i) {
      int P;
      cin >> P;

      int64_t ans = P;
      for (int j = 2; j * j <= P; ++j) {
        if (P % j != 0) continue;
        ans = ans * (j - 1) / j;
        while (P % j == 0) P /= j;
      }
      if (P > 1) ans = ans * (P - 1) / P;
      sum += ans;
    }

    cout << setprecision(2) << fixed;
    cout << (double) sum / C << '\n';
  }

  return 0;
}
