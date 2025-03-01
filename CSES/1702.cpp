#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vi pre(n), in(n);
  for (int &i : pre) cin >> i;
  for (int &i : in) cin >> i;

  vi stk, in_stack(n + 1);
  reverse(all(pre));
  for (int i : in) {
    while (not in_stack[i]) {
      stk.push_back(pre.back());
      in_stack[pre.back()] = true;
      pre.pop_back();
    }
    while (stk.back() != i) {
      cout << stk.back() << ' ';
      stk.pop_back();
    }
  }
  while (not stk.empty()) {
    cout << stk.back() << ' ';
    stk.pop_back();
  }
  cout << '\n';

  return 0;
}
