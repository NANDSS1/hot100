/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

//主要的解决维护一个滑动窗口，用hashset对这个滑动窗口进行去重
/*                while(hashset.count(s[i])){
                    //一直擦除左边的元素
                    hashset.erase(s[left]);
                    left++;
                }*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //哈希表
        unordered_set<char> hashset;
        int ans = INT_MIN;
        int left = 0;//left负责维护左边窗口
        for(int i = 0;i < s.size();i++){
            if(!hashset.count(s[i])) hashset.insert(s[i]);
            else{
                //如果发现有重复的
                while(hashset.count(s[i])){
                    //一直擦除左边的元素
                    hashset.erase(s[left]);
                    left++;
                }
                //退出循环的时候left就重新在一个没有重复的窗口左边了
                ans = max(ans,i - left + 1);
            }

            //去重了但是i还没有插入呢，现在需要插入
            hashset.insert(s[i]);
        }

        return ans;

    }
};