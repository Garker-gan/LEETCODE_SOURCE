/* 
    143：重排链表。寻找链表中点后，逆置合并
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


//首先使用快慢指针寻找链表中点，然后将后半段链表逆置，最后将两段链表合并
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        ListNode* midNode = findMidLinKlist(head);
        ListNode* l1 = head;
        ListNode* l2 = midNode->next;
        midNode->next = nullptr;
        l2 = reverseList(l2);
        emergeList(l1,l2);
    }
    //使用快慢指针：快指针一次一步，慢指针一次两步
    ListNode* findMidLinKlist(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    } 

    //链表逆置，通过创建新的链表将链表的指向翻转
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* newNode = nullptr;
        while (cur != nullptr)
        {
            ListNode* nextNode = cur->next;
            cur->next = newNode;
            newNode = cur;
            cur = nextNode;
        }
        cout<<"reserve done!"<<endl;
        return newNode;
    }

    //归并数组
    void emergeList(ListNode* l1,ListNode* l2)
    {
        while (l1 != nullptr&&l2 != nullptr)
        {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;

            l1->next = l2;
            l1 = p1;

            l2->next = l1;
            l2 = p2;
        }
        cout<<"done"<<endl;
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
    s.reorderList(head);
    ListNode* p = head;
    while (p != nullptr)
    {
        cout<<p->val<<"->";
        p = p->next;
    }
    
    return 0;
}
