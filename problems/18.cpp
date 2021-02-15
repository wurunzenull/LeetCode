#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target) continue;
            for (int m = i + 1; m < nums.size() - 2; m++) {
                if (nums[i] + nums[m] + nums[m + 1] + nums[m + 2] > target) break;
                if (m > i + 1 && nums[m] == nums[m - 1]) continue;
                if (nums[i] + nums[m] + nums[nums.size() - 1] + nums[nums.size() - 2] < target) continue;
                for (int j = m + 1, k = nums.size() - 1; j < k;) {
                    int addRes = nums[i] + nums[m] + nums[j] + nums[k];
                    if (addRes == target) {
                        res.push_back({nums[i], nums[m], nums[j], nums[k]});
                        j++;
                        k--;
                        while (j < k && nums[j] == nums[j - 1]) j++;
                        while (j < k && nums[k] == nums[k + 1]) k--;
                    } else if (addRes > target) {
                        k--;
                    } else {
                        j++;
                    }
                }
            }
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
    int target;
    cin >> target;
    Solution mySolution;
    vector<vector<int>> result = mySolution.fourSum(nums, target);
    for (auto tuple : result) {
        for (auto ele : tuple) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}