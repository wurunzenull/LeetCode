#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            // mid在左段
            if (nums[mid] > nums[right]) {
                // target在左段
                if (target > nums[right]) {
                    if (nums[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                // target在右段
                else {
                    left = mid + 1;
                }
            }
            // mid在右段
            else {
                // target在左段
                if (target > nums[right]) {
                    right = mid - 1;

                }
                // target在右段
                else {
                    if (nums[mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
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
    cout << mySolution.search(nums, target) << endl;
    return 0;
}