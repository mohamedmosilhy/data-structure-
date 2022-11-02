#include <iostream>
using namespace std;
struct StackNode
{
    int data;
    StackNode* next;
};

StackNode* newnode(int data){
    StackNode* node = new StackNode;
    node->data =data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode *front){
    return !front;
}

void push(StackNode* *front,int data){
    StackNode* node = newnode(data);
    node->next = *front;
    *front= node;
    cout<<data<<endl;
}

int pop(StackNode**front){
    if (isEmpty(*front))
    {
        return -1;
    }
    StackNode* temp = *front;
    *front = temp->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(StackNode* front){
    if (isEmpty(front))
    {
        return -1;
    }
    return front->data;
}

int main()
{
    StackNode* front = NULL;
    cout<<"Stack Push:"<<endl;
    push(&front,1);
    push(&front,2);
    push(&front,3);
    cout<<"\nTop element is "<<peek(front)<<endl;
    cout<<"\nStack Pop:"<<endl;
    while(!isEmpty(front)){
    cout<<pop(&front)<<endl;
    }
    cout<<"Top element is "<<peek(front)<<endl;
}