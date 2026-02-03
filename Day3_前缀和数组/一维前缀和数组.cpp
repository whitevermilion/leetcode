#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    // 前缀和数组
    vector<int> preSum;

   public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1);
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

int main() { return 0; }
