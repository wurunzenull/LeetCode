#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxJump = 0;
        for (int i = 0; i < n - 1 && i <= maxJump; i++) {
            maxJump = max(maxJump, i + nums[i]);
            if (maxJump >= n - 1) return true;
        }
        return false;
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
    cout << mySolution.canJump(nums) << endl;
    return 0;
}