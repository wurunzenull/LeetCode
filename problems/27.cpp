#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int length = 0;
        int dupEle = val;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == dupEle) continue;
            nums[length++] = nums[i];
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
    int val;
    cin >> val;
    Solution mySolution;
    cout << mySolution.removeElement(nums, val) << endl;
    return 0;
}