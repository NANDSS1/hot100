class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //计算链表长度的差
        int lenA = 0;
        int lenB = 0;
        ListNode* cur = headA;
        while(cur != nullptr){
            cur = cur->next;
            lenA++;
        }
        cur = headB;
        while(cur != nullptr){
            cur = cur->next;
            lenB++;
        }

        if(lenA < lenB){
            swap(headA,headB);//A要保证是长的的那个链表
            swap(lenA,lenB);       
        }
        
        int len = lenA-lenB;
        //A要先走len这么多步
        ListNode* curA = headA;
        while(len--){
            curA = curA->next;
        }
        ListNode* curB = headB;
        while(lenB--){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;


    }
};