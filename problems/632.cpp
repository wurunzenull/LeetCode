#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> next(k, 0);
        int left = 0, right = INT32_MAX;
        auto cmp = [&](const int& a, const int& b) { return nums[a][next[a]] > nums[b][next[b]]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minVal = 0, maxVal = INT32_MIN;
        for (int i = 0; i < k; i++) {
            pq.emplace(i);
            maxVal = max(maxVal, nums[i][next[i]]);
        }
        while (true) {
            int cur = pq.top();
            pq.pop();
            minVal = nums[cur][next[cur]];
            if (maxVal - minVal < right - left) {
                right = maxVal;
                left = minVal;
            }
            if (next[cur] == nums[cur].size() - 1) break;
            next[cur]++;
            pq.emplace(cur);
            maxVal = max(maxVal, nums[cur][next[cur]]);
        }
        return (vector<int>){left, right};
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

vector<vector<int>> readMatrix() {
    vector<vector<int>> matrix;
    matrix.push_back(readArrays());
    int n = matrix[0].size();
    for (int i = 1; i < n; i++) {
        matrix.push_back(readArrays());
    }
    return matrix;
}

int main() {
    vector<vector<int>> nums;
    Solution mySolution;
    while (true) {
        nums = readMatrix();
        vector<int> res = mySolution.smallestRange(nums);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}