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
void rightView(Node* root,int &test2,int level2,vector<int>&rightPart)
{
    if(root==NULL) return;
    if(level2>test2)
    {
        rightPart.push_back(root->val);
        test2=level2;
    }
    rightView(root->right,test2,level2+1,rightPart);

    if(root->right==NULL)  rightView(root->left,test2,level2+1,rightPart);
}
void leftView(Node* root,int &test,int level,vector<int>&leftPart,vector<int>&v)
{
    if(root==NULL) return;
    if(level>test)
    {
        leftPart.push_back(root->val);
         v.push_back(root->val);
        test=level;
    }
    leftView(root->left,test,level+1,leftPart,v);

    if(root->left==NULL)  leftView(root->right,test,level+1,leftPart,v);
}

int main()
{
    int test=-1,level=0,test2=-1,level2=0;
    Node* root=input();
    if(root->left==NULL && root->right==NULL) cout<<root->val<<endl;
    else{
    vector<int>leftPart;
    vector<int>rightPart;
    vector<int>v;
    leftView(root,test,level,leftPart,v);
    rightView(root,test2,level2,rightPart);
    reverse(leftPart.begin(),leftPart.end());
    leftPart.pop_back();
    if(rightPart==v) {

     if(root->left==NULL) {
    for (int i=0;i<rightPart.size();i++) cout<<rightPart[i]<<" ";
     }
     else for(int i=rightPart.size()-1;i>=0;i--) cout<<rightPart[i]<<" ";
    cout<<endl;

    }
    else
    {
        for(int i=0;i<leftPart.size();i++) cout<<leftPart[i]<<" ";
        for(int i=0;i<rightPart.size();i++) cout<<rightPart[i]<<" ";
        cout<<endl;
    }
    }
    return 0;
}