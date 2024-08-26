#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
};
Node *input_tree()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1) root=NULL;
    else root=new Node(val);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        Node* pr=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myRight;
        if(l==-1) myLeft=NULL;
        else myLeft=new Node(l);
        if(r==-1) myRight=NULL;
        else myRight=new Node(r);
         pr->left=myLeft;
         pr->right=myRight;
        if(pr->left) q.push(pr->left);
        if(pr->right) q.push(pr->right);
    }
    return root;
}
int s=0;
int sum(Node* root)
{
    
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
     int s=root->val;
        if(root->left) s+=sum(root->left);
        if(root->right) s+=sum(root->right);
        return s;
        
}
int main()
{
    // Write your code here
Node* root=input_tree();
int s=sum(root);
//level_print(root);
cout<<s<<endl;
    return 0;
}
