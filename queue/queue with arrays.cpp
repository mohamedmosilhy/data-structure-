#include<iostream>
using namespace std;
#define MAX_SIZE 5

class Queue{
    private:
    int my_queue[MAX_SIZE];
    int front, rear;

    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if ((rear == MAX_SIZE - 1) && (front == 0))
        {
            return true;
        }
        else
        return false;
    }

    bool isEmpty(){
        if(front == -1)
        {
            return true;
        }
        else
        return false;
    }

    void enQueue(int value){
        if(isFull()){
            cout << endl<< "Queue is full!!";
        }
        else{
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            my_queue[rear] = value;
            cout << value << " ";
        }
    }

    int deQueue(){
        int value;
        if (isEmpty())
        {
            cout << "Queue is empty!!" << endl;
            return -1;
        }
        else
        {
            value = my_queue[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else{
                front++;
            }
            cout << endl << "Deleted => " << value << " from myqueue";
            return value;
        }
    }

    void displayQueue(){
        if (isEmpty())
        {
            cout << endl << "Queue is Empty!!" << endl;
        }
        else
        {
            cout << endl << "Front = " << front;
            cout << endl << "Queue elements : ";

            for(int i=front; i<=rear; i++)
            cout << my_queue[i] << "\t";

            cout << endl << "Rear = " << rear << endl; 
        }

    }
};


int main(){
    Queue myq;
        
    myq.deQueue();      //deQueue 
        
    cout<<"Queue created:"<<endl;
    myq.enQueue(10); 
    myq.enQueue(20); 
    myq.enQueue(30);
    myq.enQueue(40);
    myq.enQueue(50); //enqueue 60 => queue is full 
    myq.enQueue(60);
        
    myq.displayQueue();
        
        //deQueue =>removes 10
    myq.deQueue();
        
        //queue after dequeue
    myq.displayQueue();
        
    return 0;

}