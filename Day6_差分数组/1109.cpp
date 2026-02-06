
// @leet imports start
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @leet imports end

// @leet start
class Solution {
   private:
    vector<int> diff;

   public:
    void increment(vector<int>& nums) {
        int first = nums[0] - 1;
        int last = nums[1] - 1;
        int val = nums[2];
        diff[first] += val;
        if (last + 1 < diff.size()) {
            diff[last + 1] -= val;
        }
    }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        diff.resize(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            increment(bookings[i]);
        }
        vector<int> result(n);
        result[0] = diff[0];
        for (int i = 1; i < n; i++) {
            result[i] = diff[i] + result[i - 1];
        }
        return result;
    }
};
// @leet end
