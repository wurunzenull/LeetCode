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
vector<vector<int>> readMatrix() {
    vector<vector<int>> matrix;
    for (;;) {
        vector<int> arr = readArrays();
        if (arr.size() == 0) break;
        matrix.push_back(arr);
    }
    return matrix;
}
class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        if (length == 0) return 0;
        vector<int> layerSum(length);
        for (int i = 0; i < length; i++) {
            layerSum[i] = triangle[length - 1][i];
        }
        for (int i = 1; i < length; i++) {
            int layer = length - i - 1;
            for (int j = 0; j < triangle[layer].size(); j++) {
                layerSum[j] = triangle[layer][j] + min(layerSum[j], layerSum[j + 1]);
            }
        }
        return layerSum[0];
    }
};
int main() {
    vector<vector<int>> triangle = readMatrix();
    Solution solution;
    cout << solution.minimumTotal(triangle) << endl;
}
