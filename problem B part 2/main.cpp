#include <iostream>
#include <queue>
using namespace std;
template<class T >
class BSTNode
{
public:
    T key;
    BSTNode* left;
    BSTNode* right;
    BSTNode()
    {
        left=right=0;
    }
    BSTNode(T& el,BSTNode*l=0,BSTNode* r=0)
    {
        key=el;
        left=l;
        right=r;
    }
    friend BSTNode* NewNode(int data);
    BSTNode getleft()
    {
        return left;
    }
    BSTNode getRight()
    {
        return right;
    }
    T getKey()
    {
        return key;
    }
};
template<class T>
BSTNode<T>* NewNode(int data)
{
    BSTNode<T>* Node = new BSTNode<T>();
    Node->key = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}
template <class T>
class BSTFCI
{
public:
    BSTNode<T>* root;
    BSTFCI()
    {
        root=0;
    }
    void clear()
    {
        root=0;
    }
    bool IsEmpty()
    {
        return root==0;
    }
    void InOrder(BSTNode<T>* Node)
    {
        if(Node==NULL)
            return;
        InOrder(Node->left);
        cout<<Node->key<<" ";
        InOrder(Node->right);
    }
    void PreOrder(BSTNode<T>* Node)
    {
        if(Node==NULL)
            return;
        cout<<Node->key<<" ";
        PreOrder(Node->left);
        PreOrder(Node->right);
    }
    void PostOrder(BSTNode<T>* Node)
    {
        if(Node==NULL)
            return;
        PostOrder(Node->left);
        PostOrder(Node->right);
        cout<<Node->key<<" ";
    }
    void Print(BSTNode<T>* Node)
    {
        cout<<"InOrder :"<<endl;
        InOrder(Node);
        cout<<endl;
        cout<<"PreOrder :"<<endl;
        PreOrder(Node);
        cout<<endl;
        cout<<"PostOrder :"<<endl;
        PostOrder(Node);
        cout<<endl;
    }
    void Flip(BSTNode<T>* Node)
    {
        if(Node==NULL) return;
        else
        {
            BSTNode<T>* Temp;
            Flip(Node->left);
            Flip(Node->right);

            Temp=Node->left;
            Node->left=Node->right;
            Node->right=Temp;
        }
    }
    void LargestValue(BSTNode<T>* root)
    {
        if(root==NULL) return;
        int LevelSize,Max;
        queue<BSTNode<T>*> Queue;
        Queue.push(root);
        while(true)
        {
            LevelSize=Queue.size();
            if(LevelSize==0) break;
            Max=INT_MIN;
            while(LevelSize)
            {
                LevelSize--;
                BSTNode<T>* Front=Queue.front();
                Queue.pop();

                if(Max<Front->key) Max=Front->key;
                if(Front->left) Queue.push(Front->left);
                if(Front->right)  Queue.push(Front->right);
            }
            cout<<Max<<" ";
        }
    }
    int SumBranches(BSTNode<T>* Node,int sum=0)
    {
        if(Node==NULL) return 0;
        sum=(sum*10 + Node->key);

        if(Node->left==NULL && Node->right==NULL)
            return sum;

        return SumBranches(Node->left,sum) + SumBranches(Node->right,sum);
    }
    void PrintforTest(BSTNode<T>* Node)
    {
        if(Node==NULL) return;
        PrintforTest(Node->left);
        cout<<Node->key<<" ";
        PrintforTest(Node->right);
    }

};
int main()
{
    //Test of Print
        cout<<"============ Test of Print ==============="<<endl;

    BSTNode<int>* root;

    root=NewNode<int>(1);
    root->right=NewNode<int>(3);
    root->left=NewNode<int>(2);
    root->left->left=NewNode<int>(4);
    root->left->right=NewNode<int>(5);

    BSTFCI<int>* Tree;
    Tree->root=root;
    Tree->Print(root);

cout<<endl;
    cout<<"============ Test of Flip ==============="<<endl;

     BSTNode<int>* root1;

     root1=NewNode<int>(1);
     root1->right=NewNode<int>(3);
     root1->left=NewNode<int>(2);
     root1->left->left=NewNode<int>(4);
     root1->left->right=NewNode<int>(5);

     BSTFCI<int>* Tree1;
     Tree1->root=root1;
     Tree1->Flip(Tree->root);
     Tree1->PrintforTest(root1);

cout<<endl;

    //Test of Largest Value
    cout<<"============ Test of Largest Value ==============="<<endl;

    BSTNode<int>* root2;
    root2=NewNode<int>(1);
    root2->right=NewNode<int>(3);
    root2->left=NewNode<int>(2);
    root2->right->right=NewNode<int>(5);
    root2->right->left=NewNode<int>(4);

    BSTFCI<int>* Tree2;
    Tree2->LargestValue(root2);

cout<<endl;
    // Test of SumBranches
    cout<<"============ Test of SumBranches ==============="<<endl;

    BSTNode<int>* root3;
    root3=NewNode<int>(1);
    root3->right=NewNode<int>(3);
    root3->left=NewNode<int>(2);
    root3->left->right=NewNode<int>(5);
    root3->left->left=NewNode<int>(4);
    BSTFCI<int>* Tree3;
    int x=Tree3->SumBranches(root3);
    cout<<x;

    return 0;
}
