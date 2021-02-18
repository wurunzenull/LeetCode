#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));
        path[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            path[i][0] = path[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            path[0][j] = path[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
            }
        }
        /*
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }*/
        return path[m - 1][n - 1];
    }
};

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
    vector<vector<int>> grid = readMatrix();
    Solution mySolution;
    cout << mySolution.minPathSum(grid) << endl;
    return 0;
}