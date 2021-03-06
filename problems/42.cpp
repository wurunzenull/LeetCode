#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        int length = height.size();
        if (length == 0) return 0;
        vector<int> leftMax(length, 0), rightMax(length, 0);
        leftMax[0] = height[0];
        rightMax[length - 1] = height[length - 1];
        for (int i = 1; i < length; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = length - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < length; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
    int trap2(vector<int>& height) {
        stack<int> monoDecStack;
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!monoDecStack.empty() && height[monoDecStack.top()] <= height[i]) {
                int mid = monoDecStack.top();
                monoDecStack.pop();
                if (monoDecStack.empty()) continue;
                int left = monoDecStack.top();
                int right = i;
                ans += (right - left - 1) * (min(height[right], height[left]) - height[mid]);
            }
            monoDecStack.push(i);
        }
        return ans;
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
    vector<int> height = readArrays();
    Solution mySolution;
    cout << mySolution.trap2(height) << endl;
    return 0;
}