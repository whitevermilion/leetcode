// @leet imports start
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class NumArray {
    vector<int> Presum;

   public:
    NumArray(vector<int>& nums) {
        if (nums.size() == 0) return;
        // nums有n位数据 0 1 2 3 4 5 6
        // presum 的     0 1 2 3 4 5 6
        Presum.resize(nums.size());
        Presum[0] = nums[0];
        for (int i = 1; i < Presum.size(); i++) {
            Presum[i] = Presum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // 返回left到right的数值之和
        if (left == 0) {
            return Presum[right];
        }

        return Presum[right] - Presum[left - 1];
    }
};

// 关键是别忘了数组数量为0的情况
