class Solution {
public:
    ListNode* reverseList(ListNode* head,int k){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        //while(cur != nullptr){//这里就不能用nullptr这个条件来结束，K个一组分组后，该组最后一个不是nullptr，直接计数就行了
        while(k--){
            ListNode* nextCur = cur->next;//记录一个零时结点
            cur->next = prev;
            prev = cur;
            cur = nextCur;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //先对链表长度计数
        int len = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            len++;
            curr = curr->next;
        }//计算长度

        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* prev = dummyHead;//记录需要反转那组链表的头结点的前一个节点
        ListNode* cur = dummyHead->next;//记录需要反转的那组链表的头结点

        //停止循环的条件
        while(len >= k){
            //这里每k个反转一次
            int tempK = k;
            ListNode* nextCur = cur;
            while(tempK--){
                //迭代k次
                //找到需要断开的地方
                nextCur = nextCur->next;//这是下一组需要反转链表的头节点
            }
            //这里写反转链表的逻辑
            ListNode* head = reverseList(cur,k);//反转后的链表
            prev->next = head;
            //这时候cur是反转链表的尾结点
            cur->next = nextCur;
            prev = cur;
            cur = nextCur;
            len -= k;
        }
        
        if(len != 0) prev->next = cur;

        return dummyHead->next;

    }
};