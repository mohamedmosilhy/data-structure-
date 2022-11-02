#include <iostream>
using namespace std;
#define MAX 1000
class Stack
    {
    private:
       int top;
       int myStack[MAX];
    public:
        Stack();
        bool push(int);
        int pop();
        bool isEmpty();
    };
    
    Stack::Stack()
    {   
         top = -1;
    }

    bool Stack::push(int element){
        if(top > MAX -1){
            cout<<"the stack is full"<<endl;
            return false;
        }
        else{
            top++;
            myStack[top] = element;
            cout<<myStack[top]<<endl;
            return true;
        }
    }

    int Stack::pop(){
        if (top < 0)
        {   
            cout<<"the stack is empty"<<endl;
            return 0;
        }
        else{
            int element = myStack[top];
            top--;
            return element;
        }
        
    }
    bool Stack::isEmpty(){
        return (top < 0);
    }
    

int main(){
    Stack stack;
    cout<<stack.isEmpty()<<endl;
    cout<<"push stage"<<endl;
    stack.push(3);
    stack.push(5);
    stack.push(6);
    cout<<"pop stage"<<endl;
    while(!stack.isEmpty())
      {
      cout<<stack.pop()<<endl;
      }
    cout<<stack.isEmpty()<<endl;
}