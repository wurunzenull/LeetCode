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
void printArray(vector<int> arr) {
    cout << "[";
    for (auto num : arr) {
        cout << num << " ";
    }
    cout << "]" << endl;
}
class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result(prices);
        stack<int> monoIncStack;
        for (int i = 0; i < prices.size(); i++) {
            int price = prices[i];
            while (!monoIncStack.empty() && prices[monoIncStack.top()] >= price) {
                int cur = monoIncStack.top();
                result[cur] -= price;
                monoIncStack.pop();
            }
            monoIncStack.push(i);
        }
        return result;
    }
};
int main(int argc, char* argv[]) {
    vector<int> prices = readArrays();
    Solution mySolution;
    printArray(mySolution.finalPrices(prices));
    return 0;
}