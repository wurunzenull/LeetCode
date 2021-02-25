#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        deque<int> myqueue;
        for (int i = 0; i < k; i++) {
            while (!myqueue.empty() && nums[myqueue.back()] <= nums[i]) myqueue.pop_back();
            myqueue.push_back(i);
        }
        vector<int> res = {nums[myqueue.front()]};
        for (int i = k; i < n; i++) {
            while (!myqueue.empty() && nums[myqueue.back()] <= nums[i]) myqueue.pop_back();
            myqueue.push_back(i);
            while (myqueue.front() <= i - k) myqueue.pop_front();
            res.push_back(nums[myqueue.front()]);
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
    vector<int> nums;
    int k;
    Solution mySolution;
    while (true) {
        nums = readArrays();
        cin >> k;
        vector<int> res = mySolution.maxSlidingWindow(nums, k);
        for (auto num : res) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}