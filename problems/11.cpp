#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxRes=0;
        int l=0,r=height.size()-1;
        while (l<r)
        {
            int area=(r-l)*min(height[l],height[r]);
            maxRes=max(area,maxRes);
            if(height[l]<height[r]){
                l++;
            }
            else {
                r--;
            }
        }
        return maxRes;
    }
};

vector<int> readArrays()
{
    vector<int> nums;
    string input;
    getline(cin, input);
    istringstream in(input);
    int num;
    while (in >> num)
    {
        nums.push_back(num);
    }
    in.clear();
    return nums;
}

int main()
{
    vector<int> height=readArrays();
    Solution mySolution;
    cout<<mySolution.maxArea(height)<<endl;
    return 0;
}