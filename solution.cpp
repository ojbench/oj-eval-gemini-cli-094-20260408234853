#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<int>> val(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> val[i][j];
        }
    }

    vector<vector<int>> ans(3 * m, vector<int>(3 * n));

    for (int r = 0; r < 3 * m; ++r) {
        for (int c = 0; c < 3 * n; ++c) {
            int sumA = 0, countA = 0;
            int sumB = 0, countB = 0;
            bool is_center = false;
            int center_val = 0;

            int base_i = r / 3;
            int base_j = c / 3;

            for (int i = base_i - 1; i <= base_i + 1; ++i) {
                for (int j = base_j - 1; j <= base_j + 1; ++j) {
                    if (i >= 0 && i < m && j >= 0 && j < n) {
                        int dist = abs(r - (3 * i + 1)) + abs(c - (3 * j + 1));
                        if (dist == 0) {
                            is_center = true;
                            center_val = val[i][j];
                        } else if (dist == 1) {
                            sumA += val[i][j];
                            countA++;
                        } else if (dist == 2) {
                            sumB += val[i][j];
                            countB++;
                        }
                    }
                }
            }

            if (is_center) {
                ans[r][c] = center_val;
            } else {
                if (countA == 0 && countB > 0) {
                    ans[r][c] = sumB / countB;
                } else if (countB == 0 && countA > 0) {
                    ans[r][c] = sumA / countA;
                } else if (countA > 0 && countB > 0) {
                    ans[r][c] = ((sumA / countA) * 8 + (sumB / countB) * 2) / 10;
                }
            }
        }
    }

    for (int r = 0; r < 3 * m; ++r) {
        for (int c = 0; c < 3 * n; ++c) {
            cout << ans[r][c] << (c == 3 * n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
