/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。

 

示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //前缀和加哈希表优化
        unordered_map<int,int> hashmap;
        int ans = 0;
        int pre = 0;//记录没有元素的前缀和
        hashmap[0] = 1;//前缀和为0出现了一次，主要是为了符合这种情况，nums中某一个元素等于k
        for(const auto& num:nums){
            pre += num;
            //查找hashmap里面有没有k-pre这个前缀和
            //如果有这个前缀和，就加上这个前缀和出现的次数
            if(hashmap.count(pre-k)) ans += hashmap[pre-k];//往前查找有没有符合pre-k的前缀和
            //如果没有这个前缀和，就把当前的前缀和插入hashmap
            hashmap[pre]++;
        }

        return ans;

    }
};