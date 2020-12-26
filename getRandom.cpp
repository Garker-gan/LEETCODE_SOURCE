/* 
    382. 链表随机节点   蓄水池抽样
    Garker-gan
    2020-12-26
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this -> head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* pHead = this->head;
        int val;
        int count = 0;
        while(pHead)
        {
            count++;
            if(rand()%count == 0)  val = pHead->val;
            pHead = pHead ->next;
        }
        return val;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */