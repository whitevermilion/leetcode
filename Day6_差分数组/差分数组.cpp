#include <iostream>
#include <vector>

using namespace std;

class Difference {
   private:
    vector<int> diff;

   public:
    Difference(vector<int>& nums) {
        diff = vector<int>(nums.size());
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - diff[i - 1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
int main() { int diff; }
