#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int add = 0;
        for (auto num : nums) {
            add += num;
            res = max(res, add);
            if (add <= 0) add = 0;
        }
        return res;
    }
};

vector<int> readArrays() {
    vector<int> nums;
    string input;
    getline(cin, input);
    istringstream in(input);
    int num;
    while (in >> num) {
        nums.push_back(num);
    }
    in.clear();
    return nums;
}

int main() {
    vector<int> nums = readArrays();
    Solution mySolution;
    cout << mySolution.maxSubArray(nums) << endl;
    return 0;
}