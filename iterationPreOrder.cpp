/*  
    144:二叉树的前序遍历 使用迭代法遍历二叉树(前中后)
    2020.10.27
    Garker-gan
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int x):data(x),leftChild(NULL),rightChild(NULL){}
};


// 建立二叉排序树
TreeNode* BSTree_insert(TreeNode* root,int x)
{
    if(root == NULL)
        root = new TreeNode(x);
    else if(x < root->data)
        root->leftChild = BSTree_insert(root->leftChild,x);
    else 
        root->rightChild = BSTree_insert(root->rightChild,x);
    return root;
}

//前序遍历
vector<int> PreOrder(TreeNode* root)
{
    vector<int>res;         //存放结点的值
    stack<TreeNode*>Node;   //存放结点
    if(root == nullptr) return res;
    TreeNode* p = root;
    while (p!= nullptr || !Node.empty())
    {
        while (p != nullptr)
        {
            res.emplace_back(p->data);
            Node.emplace(p);
            p = p->leftChild;
        }
        p = Node.top();
        Node.pop();
        p = p->rightChild;
    }
    return res;
    
}

//中序遍历
vector<int> InOrder(TreeNode* root)
{
    vector<int>res;
    stack<TreeNode*>Node;
    if(root == nullptr) return res;
    TreeNode* p = root;
    while (!Node.empty() || p != nullptr)
    {
        while (p != nullptr)
        {
            Node.emplace(p);
            p = p->leftChild;
        }
        p = Node.top();
        Node.pop();
        res.emplace_back(p->data);
        p = p->rightChild;
    }
    
}
//后序遍历
vector<int> PostOrder(TreeNode* root)
{
    vector<int>res;
    stack<TreeNode*>Node;
    if(root == nullptr) return res;
    TreeNode* p = root;
    while (!Node.empty() || p != nullptr)
    {
        while (p != nullptr)
        {
            Node.emplace(p);
            p = p->leftChild;
        }
        p = Node.top();
        Node.pop();
        res.emplace_back(p->data);
        p = p->rightChild;
    }
}

int main()
{
    int n;
    cin>>n;
    TreeNode* root = NULL;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin>>x;
        root = BSTree_insert(root,x);
    }
    vector<int>res;

    res = PostOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    // InOrder(root);
    // cout<<endl;
    // PostOrder(root);
    // cout<<endl;
    return 0;
}