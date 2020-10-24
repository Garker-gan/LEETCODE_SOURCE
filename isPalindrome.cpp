/* 
    234：回文链表；链表寻中点，逆置
    Garker-gan
    2020-10-24
 */
#include<iostream>
using namespace std;

//链表结构体定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //一定增加该判断，不然力扣OJ过不了
        if(head == NULL) return true;
        ListNode* mid = findMid(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        l2 = reverseList(l2);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        while(p2 != NULL)
        {
            if(p1->val == p2->val)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr&&fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newList = nullptr;
        ListNode* p = head;
        while(p != nullptr)
        {
            ListNode* nextList = p->next;
            p->next = newList;
            newList = p;
            p = nextList;
        }
        return newList;
    }
};


void creatList(ListNode* head,int n)
{
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        if(i == 0)
        {
            head->val = val;
            head->next = nullptr;
        }
        else
        {
            ListNode* newNode =  new ListNode(val);
            head->next = newNode;
            head = newNode;
        }
        
    }
    
}

int main()
{
    int n;
    cin>>n;
    ListNode* head = new ListNode();
    creatList(head,n);
    Solution s;
    cout<<s.isPalindrome(head)<<endl;
    return 0;
}

