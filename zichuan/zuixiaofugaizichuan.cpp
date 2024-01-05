/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap, smap;
        int count = 0;
        string res = s+ "initialize a max string";//初始化为s
        
        for(const auto& c:t){
            //对t制作一个字典
            tmap[c]++;
        }
        int left = 0;
        for(int right = 0;right < s.size();right++){
            smap[s[right]]++;//往滑动窗口加入一个元素
            //如果加入的这个元素是t里面的，而且数量还没有多余，那么就是一次有效添加
            if(tmap[s[right]] >= smap[s[right]]) count++;//有效添加计数加一
            //判断左边的元素是否多余
             while (left < right && smap[s[left]] > tmap[s[left]]){//如果多余
                --smap[s[left]];
                left++;//剔除多余的元素
            }
            //判断窗口的大小是否是t的大小
            if(count == t.size()){
                //窗口内已经是满足t的字符串，都是有效添加，有效添加的次数到了t的大小就可以收集结果了
                if (right - left + 1 < res.size()) res = s.substr(left, right - left + 1);//只收集有优化的的结果
            }
        }
        return res == s+ "initialize a max string" ? "" : res;
    }
};