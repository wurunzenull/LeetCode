#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int add = (flag + digits[i]);
            flag = add / 10;
            digits[i] = add % 10;
        }
        if (flag) {
            digits.insert(digits.begin(), flag);
        }
        return digits;
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
    vector<int> digits = readArrays();
    Solution mySolution;
    vector<int> res = mySolution.plusOne(digits);
    for (auto num : res) {
        cout << num << " ";
    }
    return 0;
}