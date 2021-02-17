#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> row(matrix[0]);
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
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
    vector<vector<int>> matrix = readMatrix();
    Solution mySolution;
    mySolution.rotate(matrix);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}