/*49. 字母异位词分组
中等
1.8K
相关企业
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //给string排序
        unordered_map<string,vector<string>> hashmap;
        for(const auto& str:strs){
            string key = str;
            sort(key.begin(),key.end());
            hashmap[key].push_back(str);
        }

        //返回答案
        vector<vector<string>> ans;
        for(const auto& key:hashmap){
             //在这里，迭代变量key的类型将会是const reference to std::pair<const std::string, std::vector<std::string>>
            ans.push_back(key.second);
        }

        return ans;
    }
};