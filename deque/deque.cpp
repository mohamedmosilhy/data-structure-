#include <iostream>
using namespace std;
#define MAX_SIZE 10
class Deque
{
private:
    int array[MAX_SIZE];
    int front;
    int rear;
    int array_size;
public:
    Deque(int size){
        rear = 0;
        front = -1;
        array_size = size; 
    }

    void insertFront(int key);
    void insertRear(int key);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();

    bool isEmpty(){
        return(front == -1);
    }

    bool isFull(){
        return((front == 0 && rear == array_size -1) || front == rear +1);
    }
};


void Deque::insertFront(int key){
    if (isFull())
    {
        cout<<"overflow!!"<<endl;
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0)
    {
        front = array_size - 1;
    }
    else{
        front--;
    }
      array[front] = key;
}

void  Deque::insertRear(int key){
    if (isFull())
    {
        cout<<"overflow!!"<<endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if(rear == array_size -1)
    {   
        rear = 0;
    }
    else{
        rear++;
    }
    array[rear] = key;
}

void  Deque::deleteFront(){
    if (isEmpty())
    {
        cout<<"queue underflow"<<endl;
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == array_size - 1){
        front = 0;
    }
    else{
        front++;
    }
}

void  Deque::deleteRear(){
    if (isEmpty())
    {
        cout<<"queue underflow"<<endl;
        return;
    }
    if (rear == front)
    {
        front = -1;
        rear = -1;
    }
    else if(rear == 0)
    {
        rear = array_size -1;
    }
    else{
        rear--;
    }
}

int  Deque::getFront(){
    if (isEmpty())
    {
        cout<<"queue underflow"<<endl;
        return -1;
    }
    return array[front];
}

int Deque::getRear(){
    if (isEmpty())
    {
            cout<<"queue underflow"<<endl;
            return -1;
    }
    return array[rear];
}

int main(){
    Deque dq(5); 
    cout << "Insert element 1 at rear end \n"; 
    dq.insertRear(1); 
    
    cout << "insert element 3 at rear end \n"; 
    dq.insertRear(3); 
    
    cout << "rear element of deque " << " " << dq.getRear() << endl; 
    
    dq.deleteRear(); 
    cout << "After deleterear, rear = " << dq.getRear() << endl; 
    
    cout << "inserting element 5 at front end \n"; 
    dq.insertFront(5); 
    
    cout << "front element of deque " << " " << dq.getFront() << endl; 
    
    dq.deleteFront(); 
    
    cout << "After deletefront, front = " << dq.getFront() << endl; 

    return 0;
}