/* 
    206：反转链表；借用一个新的链表使得指针反转(reverse拼错了)
    p  q
    1->2->3
    new
    reverse拼错了！！！！
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
    ListNode* reverseList(ListNode* head) {
        ListNode* newList = NULL;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ListNode* nextNode = cur->next;
            cur->next = newList;
            newList = cur;
            cur = nextNode;
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
    // cout<<s.middleNode(head)->val<<endl;

    //输出
    // ListNode* p = head;
    // while (p != nullptr)
    // {
    //     cout<<p->val<<"->";
    //     p = p->next;
    // }
    
    return 0;
}
