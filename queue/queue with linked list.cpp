#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

node* front = NULL;
node* rear = NULL;
node* temp = NULL;

void Insert(int data){
    if (rear == NULL)
    {
        rear = new node;
        rear->data = data;
        rear->next = NULL;
        front = rear;
    }
    else
    {
        temp = new node;
        rear->next = temp;
        temp->data = data;
        temp->next = NULL;
        rear = temp;
    } 
}

void Delete(){
    temp = front;
    if (front == NULL)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else if(temp->next != NULL) {
        temp = temp->next;
        cout<<"Element deleted from queue is : "<<front->data<<endl;
        free (front);
        front = temp;
    }
    else
    {
        cout<<"Element deleted from queue is : "<<front->data<<endl;
        free(front);
        front = NULL;
        rear = NULL;    
    }  
}

void Display(){
    temp = front;
    if (front == NULL && rear == NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main() {
    
cout<<"Queue Created:"<<endl;
Insert(10);
Insert(20);
Insert(30);
Insert(40);
Insert(50);
Display();
Delete();
cout<<"Queue after one deletion: "<<endl;
Display();
       
return 0;
}
