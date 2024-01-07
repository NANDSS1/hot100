/*给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。*/

/*
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isVaild(string str1,string str2){
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        if(str1 == str2) return true;
        else return false;
    }

    vector<int> findAnagrams(string s, string p) {
        //首先确定方法
        //子串应该是连续的
        //用一个for + 一个快排应该可以
        if(s.size() < p.size()) return {};
        int n = p.size();
        vector<int> ans;
        for(int i = 0;i <= s.size()-n;i++){
            if(isVaild(s.substr(i,n), p)) ans.push_back(i);
        }
        return ans;


    }
};//这种做法要超时
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>sCount(26);
        vector<int>pCount(26);
        int sLen = s.size();
        int pLen = p.size();
        vector<int> result;
        if (sLen < pLen) {
            return vector<int>();
        }

        for(int i = 0;i < pLen;i++){
            sCount[s[i]-'a']++;
            pCount[p[i]-'a']++;
        }
        if (sCount == pCount) {
            result.push_back(0);
        }

        for(int i = 0;i < sLen-pLen;i++){
            sCount[s[i]-'a']--;//退出队列头新的元素
            sCount[s[i+pLen]-'a']++;//加入一个新的元素到队列尾

            //判断当前滑动窗口的数值是否和p相同
            if(sCount == pCount) result.push_back(i+1); 
        }

        return result;
        

    }
};