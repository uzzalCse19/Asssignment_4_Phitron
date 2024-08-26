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
void leaf_Node(Node* root,vector<int>&v)
{
    
    if(root==NULL) return;
    int a=root->val;
    if(root->left==NULL && root->right==NULL) v.push_back(a);
    else
    {
        leaf_Node(root->left,v);
        leaf_Node(root->right,v);
    } 
    
}
int main()
{
    vector<int>v;
    Node* root=input();
    leaf_Node(root,v);
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}