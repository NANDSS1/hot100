
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = INT_MIN;
        while(left < right){
            ans = max(min(height[left],height[right])*(right - left),ans);
            //怎么移动,如果左边小了，只有一条路可以走，可以左边++
            if(height[left] < height[right]) left++;
            else right--;
        }

        return ans;

    }
};