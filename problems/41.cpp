#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            while (nums[i] > 0 && nums[i] < len && nums[i] != nums[nums[i] - 1]) {
                swap(nums, nums[i] - 1, i);
            }
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return len + 1;
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
    cout << mySolution.firstMissingPositive(nums) << endl;
    return 0;
}