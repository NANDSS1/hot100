class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int bit = 10;
        int up = 0;//进位
        ListNode *dummy = new ListNode(0), *p = dummy;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        //肯定有长有短的，这个循环先保持一致
        while(cur1 != nullptr && cur2 != nullptr){
            ListNode* node = new ListNode((up+cur1->val+cur2->val)%bit);
            p->next = node;
            p = p->next;
            up = (cur1->val+cur2->val+up)/bit;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        //找到不为空的那个链表
        cur1 == nullptr ? cur1 = cur2:cur1 = cur1;//这个时候就把不为空的那个链表给到cur1了
        while(cur1 != nullptr){
            ListNode* node = new ListNode((up+cur1->val)%bit);
            p->next = node;
            p = p->next;
            up = (up+cur1->val)/bit;
            cur1 = cur1->next;
        }

        //最后进位如果不为0
        if(up!=0){
            ListNode* node = new ListNode(up);
            p->next = node;
        }

        return dummy->next;


    }
};