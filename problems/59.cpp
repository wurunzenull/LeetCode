#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int direction = 0x1;
        int i = 0, j = 0, loop = 0, num = 0;
        while (num < n * n) {
            matrix[i][j] = ++num;
            if (direction & 0x1) {
                if (loop + j == n - 1) {
                    direction = 0x2;
                    i++;
                } else
                    j++;
            } else if (direction & 0x2) {
                if (loop + i == n - 1) {
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
        return matrix;
    }
};

int main() {
    int n;
    cin >> n;
    Solution mySolution;
    vector<vector<int>> matrix = mySolution.generateMatrix(n);
    for (auto row : matrix) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}