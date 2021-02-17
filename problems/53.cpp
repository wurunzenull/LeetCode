#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status){lSum, rSum, mSum, iSum};
    }

    Status get(vector<int>& nums, int l, int r) {
        if (l == r) {
            return (Status){nums[l], nums[l], nums[l], nums[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(nums, l, m);
        Status rSub = get(nums, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
        /*
         //贪心算法
        int res = INT32_MIN;
        int add = 0;
        for (auto num : nums) {
            add += num;
            res = max(res, add);
            if (add <= 0) add = 0;
        }
        return res;
        */
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