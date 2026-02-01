#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    long long sumArray(const vector<int>& nums) {
        long long out = 0;
        for (auto it : nums) {
            out += it;
        }
        return out;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution solution;
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        cout << solution.sumArray(vec) << endl;
    }
}

// 怎么使用迭代器遍历vector数组?
// vector<int>::iterator it = vec.begin()
// 使用auto简化迭代器的使用
// auto it = vec.begin 特别注意it是数组数值而非索引
// 使用范围循环，使得遍历更加简洁
// for (int i : vec) { cout << i << endl;}
// 结合两种方法
// for (auto it : v) {cout << it ;}
