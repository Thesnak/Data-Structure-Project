#include <iostream>

using namespace std;
template <class T>
class stack
{
    struct Node
    {
        T item;
        Node* next;
    };
public:
    Node* top;
    Node* cur;
    stack()
    {
        top=NULL;
    }
    void push(T NewElment)
    {
        Node* NewItemPtr=new Node;
        NewItemPtr->item=NewElment;
        NewItemPtr->next=top;
        top=NewItemPtr;
    }
    void pop()
    {
        if(IsEmpty())
            cout<<"Stack is Empty to pop item !"<<endl;
        else
        {
            Node* temp=new Node;
            temp=top;
            top=top->next;
            temp->next=NULL;
            delete temp;
        }
    }
     bool IsEmpty()
    {
        return top==NULL;
    }
};
bool ArePair(char open,char closed)
{
    if(open=='(' && closed==')')
        return true;
    else if(open=='{' && closed=='}')
        return true;
    else if(open=='[' && closed==']')
        return true;
    return false;
}
bool AreBalanced(string expression)
{
    stack<char> s;
    for(int i=0; i<expression.length(); i++)
    {
        if(expression[i]=='(' ||expression[i]=='{' || expression[i]=='[')
            s.push(expression[i]);
        else if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
        {
            if(s.IsEmpty() || !ArePair(s.top->item,expression[i]))
                return false;
            else
                s.pop();
        }
    }
    if(s.IsEmpty())
        return true;
    return false;
}

int main()
{
    string braket;
    getline(cin, braket);
    if(AreBalanced(braket)) cout<<"Balanced";
    else cout<<"Not Balanced"<<endl;
    return 0;
}
