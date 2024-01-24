/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 
*/
/*先回溯找到所有情况，然后每个情况的逐一判断是否合理
判断合理->只要出现右边括号比左边多，就不合理，返回false，否则合理，一直遍历完一种情况
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string path;
    vector<string> ans;
public:
    bool isValid(string & s){
        int left=0,right=0;//记录左右括号的
        for(int i=0;i<s.size();++i){
            if(s[i] == '(') left++;
            else if(s[i] == ')') right++;
            if(left < right) return false;
        }
        if(right == left)return true;
        else return false;//排除右括号比左括号多的情况
    }
    void backtracking(int n){
        if(path.size() == n){
            if(isValid(path))
            ans.push_back(path);
            return;
        }


        path.push_back('(');
        backtracking(n);
        path.pop_back();
        path.push_back(')');
        backtracking(n);
        path.pop_back();
        

    }
    vector<string> generateParenthesis(int n) {
        backtracking(n*2);
        return ans;
    }
};