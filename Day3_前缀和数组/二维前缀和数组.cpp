#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
    vector<vector<int>> preSum;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        preSum.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] +
                               matrix[i - 1][j - 1] - preSum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int x1, int x2, int y1, int y2) {
        return preSum[x2 + 1][y2 + 1] - preSum[x1][y2 + 1] -
               preSum[x2 + 1][y1] + preSum[x1][y1];
    }
};

int main() { return 0; }
