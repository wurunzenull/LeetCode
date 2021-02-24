#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        vector<int> charNum(26, 0);
        int count = 0;
        for (auto c : text) {
            charNum[c - 'a']++;
        }
        return min({charNum['a' - 'a'], charNum['b' - 'a'], charNum['l' - 'a'] / 2, charNum['o' - 'a'] / 2,
                    charNum['n' - 'a']});
    }
};

int main() {
    string text;
    Solution mySolution;
    while (cin >> text) {
        cout << mySolution.maxNumberOfBalloons(text) << endl;
    }
    return 0;
}