/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

 

示例 1:

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
 
*/
/*
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //循环
        k = k%(nums.size());

        vector<int> ans;
        for(int i = nums.size() - k;i < nums.size();i++){
            ans.emplace_back(nums[i]);
        }
        for(int i = 0;i < nums.size()-k;i++){
            ans.emplace_back(nums[i]);
        }

        nums = ans;

        


    }
};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //先反转然后再两边各自反转
        int n = nums.size();
        k = k%n;
        //先全部反转
        int left = 0;
        int right = n-1;
        while(left < right){
            swap(nums[left++],nums[right--]);
        }
        //再反转前k个
        left = 0;
        right = k-1;
        while(left < right){
            swap(nums[left++],nums[right--]);
        }

        //再反转后面n-k个
        left = k;
        right = n-1;
        while(left < right){
            swap(nums[left++],nums[right--]);
        }

        

        

    }
};