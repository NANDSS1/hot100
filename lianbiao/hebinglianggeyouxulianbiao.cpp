#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        while(cur1 != nullptr && cur2!=nullptr){
            if(cur1->val <= cur2->val){
                cur->next = cur1;
                cur1 = cur1->next;
            }else{
                cur->next = cur2;
                cur2 = cur2->next;
            }
        }
        //这个时候有一个为空了，直接接到链表上
        cur1 == nullptr?cur1 = cur2: cur1 = cur1;
        //cur1这个时候是非空链表
        while(cur1 != nullptr){
            cur->next = cur1;
            cur = cur->next;
            cur1 = cur1->next;
        }

        return dummyHead->next;
        
    }
};