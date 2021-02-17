#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        int largestArea = 0;
        stack<int> monoIncStack;
        heights.insert(heights.begin(), -1);
        heights.push_back(0);
        int length = heights.size();
        for (int i = 0; i < length; i++) {
            while (!monoIncStack.empty() && heights[monoIncStack.top()] >= heights[i]) {
                int height = heights[monoIncStack.top()];
                monoIncStack.pop();
                int left = monoIncStack.top() + 1;
                int right = i - 1;
                largestArea = max(largestArea, (right - left + 1) * height);
            }
            monoIncStack.push(i);
        }
        return largestArea;
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
    vector<int> heights = readArrays();
    Solution mySolution;
    cout << mySolution.largestRectangleArea(heights) << endl;
    return 0;
}