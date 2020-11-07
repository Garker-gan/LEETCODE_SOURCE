/* 
    1290. 二进制链表转整数 逆置
    Garker-gan
    2020-11-07
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newList = nullptr;
        ListNode* p = head;
        while(p != nullptr)
        {
            ListNode* nextNode = p->next;
            p->next = newList;
            newList = p;
            p = nextNode;
        }
        return newList;
    }

    int getDecimalValue(ListNode* head) {
        ListNode* newList = reverseList(head);
        ListNode* p = newList;
        int sum = 0;
        int count = 0;
        while(p != nullptr)
        {
            sum += pow(2,count++)*p->val;
            p = p->next;
        }
        return sum;
    }
};