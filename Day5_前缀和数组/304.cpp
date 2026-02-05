
// @leet imports start
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class NumMatrix {
    vector<vector<int>> Presum;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 问，如果m ==
        // 0,也就是说matrix是一个空矩阵的时候，没有matrix[0],这句代码会不会报错？
        if (m == 0 || n == 0) {
            return;
        }
        Presum.resize(matrix.size() + 1, vector<int>(n + 1, 0));

        // 我们希望pre矩阵的1位置对应原先的0位置
        for (int i = 1; i < Presum.size(); i++) {
            for (int j = 1; j < Presum[0].size(); j++) {
                Presum[i][j] = Presum[i][j - 1] + Presum[i - 1][j] +
                               matrix[i - 1][j - 1] - Presum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;

        return Presum[row2][col2] - Presum[row2][col1 - 1] -
               Presum[row1 - 1][col2] + Presum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @leet end
//
// 你的疑惑是对的，这个地方的确会报错，这里只是侥幸通过
