#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        if (n <= 0) return res;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0)
                res.push_back("FizzBuzz");
            else if (i % 3 == 0)
                res.push_back("Fizz");
            else if (i % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};

int main() {
    int n;
    Solution mySolution;
    while (cin >> n) {
        vector<string> res = mySolution.fizzBuzz(n);
        for (auto s : res) {
            cout << s << endl;
        }
    }
    return 0;
}