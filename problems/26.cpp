#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int length = 1;
        int dupEle = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == dupEle) continue;
            nums[length++] = nums[i];
            dupEle = nums[i];
        }
        return length;
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
    cout << mySolution.removeDuplicates(nums) << endl;
    return 0;
}