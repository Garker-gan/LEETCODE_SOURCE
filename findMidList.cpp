/* 
    876：链表的中心结点；快慢指针
    Garker-gan
    2020-10-20
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
    ListNode* middleNode(ListNode* head) {
        return findMidList(head);
    }
    ListNode* findMidList(ListNode* head)
    {
        ListNode*  fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr&&fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next)  return slow = slow->next;
        return slow;
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
    cout<<s.middleNode(head)->val<<endl;

    //输出
    // ListNode* p = head;
    // while (p != nullptr)
    // {
    //     cout<<p->val<<"->";
    //     p = p->next;
    // }
    
    return 0;
}
