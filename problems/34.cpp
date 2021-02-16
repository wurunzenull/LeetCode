#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchExtreme(vector<int>& nums, int target, bool Min) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (Min) {
                    if (mid == 0)
                        return 0;
                    else if (nums[mid] != nums[mid - 1])
                        return mid;
                    else {
                        right = mid - 1;
                    }
                } else {
                    if (mid == nums.size() - 1)
                        return nums.size() - 1;
                    else if (nums[mid] != nums[mid + 1])
                        return mid;
                    else {
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{searchExtreme(nums, target, true), searchExtreme(nums, target, false)};
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
    vector<int> posRange = mySolution.searchRange(nums, target);
    for (auto pos : posRange) {
        cout << pos << " ";
    }
    return 0;
}