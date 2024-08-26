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
Node *input()
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
int count_node(Node* root)
{
    int l,r;
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    if(root->left==NULL || root->right==NULL) return 2;
    if(root->left)  l=count_node(root->left);
     if(root->right)  r=count_node(root->right);
     return l+r+1;
}
int maxHeight(Node* root)
{
    int l,r;
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    if(root->left) l=maxHeight(root->left);
    if(root->right) r=maxHeight(root->right);
    return max(l,r)+1;
}
int main()
{
Node* root=input();
int s=count_node(root);
int depth=maxHeight(root)+1;
if(pow(2,depth)-1==s) cout<<"YES"<<endl;
else cout<<"NO"<<endl;

}