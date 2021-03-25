#include "common.h"
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
void printArray(vector<int> arr) {
    cout << "[";
    for (auto num : arr) {
        cout << num << " ";
    }
    cout << "]" << endl;
}
void printMatrix(vector<vector<int>> matrix) {
    cout << "{" << endl;
    for (auto arr : matrix) {
        printArray(arr);
    }
    cout << "}" << endl;
}