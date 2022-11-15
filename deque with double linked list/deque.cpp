#include "deque.h"

Node* new_node (int data){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

My_Deque::My_Deque(){
    front = NULL;
    rear = NULL;
    size = 0;
}

// return the last element
int My_Deque::end(){
    if(is_empty()){
        return -1;
    }
    return rear->data;
}

// return the first element
int My_Deque::begin(){
    if(is_empty()){
        return -1;
    }
    return front->data;
}

// add the element to the end of the deque
void My_Deque::push_back(int element){
    if (is_empty())
    {   
        Node* node = new_node(element);
        size++;
        front = node;
        rear = node;
    }
    else
    {
        Node* node = new_node(element);
        node->prev = rear;
        rear->next = node;
        rear = node;
        node->next = NULL;
        size++;
    }

}

// add the element to the beginning of the deque
void My_Deque::push_front(int element){
    if (is_empty())
    {   
        Node* node = new_node(element);
        size++;
        front = node;
        rear = node;
    }
    else
    {
        Node* node = new_node(element);
        node->next = front;
        node->prev = NULL;
        front->prev = node;
        front = node;
        size++;
    }
}

// remove the last element, return the removed element
int My_Deque::pop_back(){
    int data;
    if (is_empty())
    {   
        return -1;
    }
    else if(front == rear){
        data = rear->data;
        Node* temp = rear;
        delete temp;
        front = NULL;
        rear = NULL;
    }
    else{
        data = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        delete temp;
    }
    size--;
    return data;
}

// remove the first element, return the removed element
int My_Deque::pop_front(){
    int data;
    if (is_empty())
    {   
        return -1;
    }
    else if(front == rear){
        data = front->data;
        Node* temp = front;
        delete temp;
        front = NULL;
        rear = NULL;
    }
    else{
        data = front->data;
        Node* temp = front;
        front = front->next;
        front->prev = NULL;
        delete temp; 
    }
    size--;
    return data;
}

// convert the deque to vector and return that vector
std::vector<int> My_Deque::toVector(){
    Node* temp = front;
    vector<int> vector;
    while (temp->next != NULL)
    {
        vector.push_back(temp->data);
        temp = temp->next;
    }
    vector.push_back(rear->data);
    return vector;
}

// print the whole deque from head to tail
void My_Deque::print(){
    Node* temp = front;
    while (temp->next != NULL)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// clear the whole array
void My_Deque::clear(){
    Node* current = front;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    front = NULL;
    rear =NULL;
    size = 0;
}

// return the deque size
int My_Deque::get_size(){
    return size;
}

bool My_Deque::is_empty(){
    if (front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

My_Deque::~My_Deque(){
    Node* current = front;
    while(current != NULL){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}