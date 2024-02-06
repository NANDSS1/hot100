#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = left + (right - left) / 2;
        while(left <= right){
            if(nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            mid = left + (right - left) / 2;
        }
        return left;
    }
};

int main(){
    vector<int> nums =  {1,3,5,6};
    int target = 2;
    Solution sol;
    int res = sol.searchInsert(nums, target);
    cout << res << endl;
    return 0;
}