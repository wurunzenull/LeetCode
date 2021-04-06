#include <bits/stdc++.h>
using namespace std;
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
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (auto&& i : nums) {
            numSet.insert(i);
        }
        int result = 0;
        for (auto&& i : nums) {
            if (numSet.find(i - 1) == numSet.end()) {
                int cur = i;
                int curResult = 1;
                while (numSet.find(cur + 1) != numSet.end()) {
                    cur = cur + 1;
                    curResult++;
                }
                result = max(result, curResult);
            }
        }
        return result;
    }
};
int main(int argc, char** argv) {
    vector<int> nums = readArrays();
    Solution mySolution;
    cout << mySolution.longestConsecutive(nums) << endl;
    return 0;
}