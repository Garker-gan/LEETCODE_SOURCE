/* 
    25:K个一组翻转链表；链表分组逆置
    Garker-gan
    2020-10-20
 */
#include<iostream>
#include<utility>
#include<tuple>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;
    
        while(head)
        {
            ListNode* tail = pre; 
            for(int i = 0;i < k;i++)
            {
                tail = tail->next;
                if(!tail)
                {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next; 
            tie(head,tail) = reverseList(head,tail);
            //逆置后的子串接入原串
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
    pair<ListNode*,ListNode*>reverseList(ListNode* head,ListNode* tail)
    {
        ListNode* newList = tail->next;
        ListNode* current = head;
        while(newList != tail)
        {
            ListNode* nextNode = current -> next;
            current->next = newList;
            newList = current;
            current = nextNode;
        }
        return {tail,head}; 
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
    ListNode* p =  s.reverseKGroup(head,2);
    // cout<<s.middleNode(head)->val<<endl;

    //输出
    // ListNode* p = head;
    while (p != nullptr)
    {
        cout<<p->val<<"->";
        p = p->next;
    }
    
    return 0;
}
