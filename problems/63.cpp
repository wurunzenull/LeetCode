#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0]) break;
            path[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j]) break;
            path[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) continue;
                if (!obstacleGrid[i - 1][j]) path[i][j] += path[i - 1][j];
                if (!obstacleGrid[i][j - 1]) path[i][j] += path[i][j - 1];
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
    vector<vector<int>> obstacleGrid = readMatrix();
    Solution mySolution;
    cout << mySolution.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}