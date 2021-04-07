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
vector<vector<int>> readMatrix() {
    vector<vector<int>> matrix;
    for (;;) {
        vector<int> arr = readArrays();
        if (arr.size() == 0) break;
        matrix.push_back(arr);
    }
    return matrix;
}
class Solution {
    struct myvector {
        double x, y;
    };
    double getDistance(const myvector& a, const myvector& b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }
    struct myvector GetCenter(const myvector& a, const myvector& b, int r) {
        if (a.x == b.x && a.y == b.y) return myvector{a.x, a.y};
        myvector middle{(a.x + b.x) / 2, (a.y + b.y) / 2};
        double dist = getDistance(a, b);
        double h = sqrt(r * r - dist * dist / 4);
        myvector ba{(b.x - a.x), (b.y - a.y)};
        myvector verticalBa{-ba.y, ba.x};
        double verticalBaLength = getDistance(verticalBa, {0, 0});
        verticalBa.x *= (h / verticalBaLength);
        verticalBa.y *= (h / verticalBaLength);
        return myvector{middle.x + verticalBa.x, middle.y + verticalBa.y};
    }

   public:
    int numPoints(vector<vector<int>>& points, int r) {
        int len = points.size();
        int ans = 0;
        for (auto&& pointa : points) {
            for (auto&& pointb : points) {
                myvector a{(double)pointa[0], (double)pointa[1]};
                myvector b{(double)pointb[0], (double)pointb[1]};
                if (getDistance(a, b) / 2 > r) continue;
                myvector center = GetCenter(a, b, r);
                // cout << "center " << center.x << " " << center.y << endl;
                int cnt = 0;
                for (auto&& point : points) {
                    myvector c{(double)point[0], (double)point[1]};
                    if (getDistance(c, center) <= r) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
int main(int argc, char** argv) {
    vector<vector<int>> points = readMatrix();
    int r;
    cin >> r;
    Solution mySolution;
    cout << mySolution.numPoints(points, r) << endl;
    return 0;
}