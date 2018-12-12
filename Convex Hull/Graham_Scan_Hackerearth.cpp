#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x;
  long long y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  for (int i = 1; i < n; i++) {
    if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x)) {
      swap(p[0], p[i]);
    }
  }
  sort(p.begin() + 1, p.end(), [&](const point &a, const point &b) {
    long long vmul = (a.x - p[0].x) * (b.y - p[0].y) - (a.y - p[0].y) * (b.x - p[0].x);
    return (vmul > 0);
  });
  vector<vector<double>> dist(n + 1, vector<double>(n + 1));
  vector<vector<double>> area(n + 1, vector<double>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
      area[i][j] = 0.5 * (double) (p[i].x - p[j].x) * (double) (p[i].y + p[j].y);
    }
  }
  p.resize(n + 1);
  vector<vector<double>> dp(n + 1, vector<double>(k + 1));
  double low = 0.0, high = 4e9;
  for (int it = 0; it < 50; it++) {
    double mid = 0.5 * (low + high);
    bool can = false;
    for (int start = 0; start <= n - k; start++) {
      for (int i = start; i <= n; i++) {
        fill(dp[i].begin() + max(0, k - (n - i)), dp[i].begin() + min(k, i - start) + 1, -1e30);
      }
      p[n] = p[start];
      for (int i = start; i < n; i++) {
        dist[i][n] = dist[i][start];
        area[i][n] = area[i][start];
      }
      dp[start][0] = 0;
      for (int i = start; i < n; i++) {
        for (int t = max(0, k - (n - i)); t <= min(k - 1, i - start); t++) {
          for (int j = i + 1; j <= n - k + t + 1; j++) {
            dp[j][t + 1] = max(dp[j][t + 1], dp[i][t] + area[i][j] - dist[i][j] * mid);
          }
        }
      }
      if (dp[n][k] >= 0) {
        can = true;
      }
      if (can) {
        break;
      }
    }
    if (can) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << fixed << setprecision(4) << 0.5 * (low + high) << '\n';
  return 0;
}
