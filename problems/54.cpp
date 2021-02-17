#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        if (matrix.size() == 0) return {};
        int m = matrix.size(), n = matrix[0].size();
        int direction = 0x1;
        int i = 0, j = 0, loop = 0, num = 0;
        while (num < n * m) {
            num++;
            order.push_back(matrix[i][j]);
            if (direction & 0x1) {
                if (loop + j == n - 1) {
                    direction = 0x2;
                    i++;
                } else
                    j++;
            } else if (direction & 0x2) {
                if (loop + i == m - 1) {
                    direction = 0x4;
                    j--;
                } else
                    i++;

            } else if (direction & 0x4) {
                if (j - loop == 0) {
                    loop++;
                    direction = 0x8;
                    i--;
                } else
                    j--;
            } else if (direction & 0x8) {
                if (i - loop == 0) {
                    direction = 0x1;
                    j++;
                } else
                    i--;
            }
        }
        return order;
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
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }
    return matrix;
}

int main() {
    vector<vector<int>> matrix = readMatrix();
    Solution mySolution;
    vector<int> order = mySolution.spiralOrder(matrix);
    for (auto num : order) {
        cout << num << " ";
    }
    return 0;
}