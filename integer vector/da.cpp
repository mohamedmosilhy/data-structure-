#include "da.h"
#include <iostream>
using namespace std;
// Constructor that makes an array with capacity = 1 when we create a vector with no specialized size  

My_DA :: My_DA()
{

    data = new int[capacity];
}


// Constructor that takes an array and its size and checks if the input size is greater than the capacity
// we double until the capacity is greater than the size of the capacity and after that,
// we copy the elements from the input array to our vector

My_DA :: My_DA(int arr[], int size)
{

    this->size = size;

    while (size > capacity)
    {
      capacity *= 2;  
    }
    
    data = new int[capacity];

    for (int i = 0; i < size; i++)
    {
       data[i] = arr[i];
    }
}


// return the element at given index

int My_DA :: get(int index)
{
    return data[index];
}


// take an element from the user and check if the array is full or not
// if it is not full we can put that element at the end of the array 
// but if it is full we must double the capacity of the array first
// second copying the elements of the array into another array and putting this element at the end of the array
// deleting the old array 

void My_DA :: push(int element)
{
    if(size < capacity)
    {
        data[size] = element;
        size++;
    }
    else
    {
        capacity *= 2;
        int* old_data = data;
        data = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            data[i] = old_data[i];
        }

        data[size] = element;
        size++;
        delete[] old_data;
    }
}


// check if the array is not empty and if this is true 
// store the last element that will be removed and copy the data from the old array to the new array
// decrease the size by one and shrink the capacity of the vector but if the size equals zero sets the capacity to one 
// remove the last element, remove the old array and return the removed element
// if the array is empty return -1

int My_DA ::pop()
{
    if (size > 0)
    {
        int* old_data = data;
        data = new int[capacity];
        int last_element = old_data[size - 1];

        for (int i = 0; i < size; i++)
            {
                data[i] = old_data[i];
            }
        size = size - 1;

        if ((capacity/2) > size)
        {
            capacity /=2;
        }
        
        if(size == 0)
        {
            capacity = 1;
        }
        delete[] old_data;
        return last_element;
    }
    else
    {
       return -1; 
    }
}


// take the index of the element the user wants to put it in and the value of that element
// check if there is no value in that index in our vector put that element in the index
// but if there is a value in that index and the size is lower than the capacity shift the elements from the index to the size by one 
// put the element in the index and increase the size by one 
// if the size is greater than the capacity double first the capacity, copy the element in a new array and
// put the element in the index, increase the size by one and delete the old array  

void My_DA :: insert(int index, int element)
{
    if (!data[index])
    {
        data[index] = element;
        size++;
    }

    else if(size < capacity)
    {
        for (int i = size + 1; i > index; i--)
        {
            data[i] = data[i - 1];
        }

        data[index] = element;
        size++;
    }

    else
    {
        capacity *= 2;
        int* old_data = data;
        data = new int[capacity];

        int j = 0;
        for (int i = 0; i < size +1; i++)
        {
            if (i == index)
            {
                continue;
            }
            
            data[i] = old_data[j];
            j++;
        }

        data[index]= element;
        size++;
        delete[] old_data;
    }
}


// check if the index taken from the user is not beyond the border of the array then 
// save the element we want to remove in a variable and make a new array 
// copy the elements from the old array to the new array except for that element  
// decrease the size by one and shrink the capacity of the vector but if the size equals zero sets the capacity to one 
// delete the old array and return the removed element
// if the index taken from the user is beyond the border of the array then return -1

int My_DA :: remove(int index)
{
    if (index + 1 <= size)
    {
        int* old_data = data;
        data = new int[capacity];
        int element = old_data[index];

        int j = 0;
        for (int i = 0; i < size; i++)
            {
                if (i == index)
                {
                    continue;
                }
                
                data[j] = old_data[i];
                j++;
            }
        size = size - 1;

        if ((capacity/2) > size)
        {
            capacity /=2;
        }

        if(size == 0)
        {
            capacity = 1;
        }
        delete[] old_data;
        return element;
    }
    else
    {
        return -1;
    }
}


// print the elements in the vector 

void My_DA :: print()
{
    cout<<"vector :"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}


// delete the elements in the vector and reset the vector size and capacity
// make an empty new array     

void My_DA :: clear()
{
    delete[] data;
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

// search for an element in the array and if you find it returns the index of this element 
// but if you don't find it returns -1

int My_DA :: find(int element)
{
    for(int i = 0; i < size; i++)
    {
        if(element == data[i])
        {
            return i;
        }
    }
    return -1;
}

// returns the size of the vector

int My_DA :: get_size()
{

    return size;
}

// returns the capacity of the vector 

int My_DA :: get_capacity()
{
    return capacity;
}

// destructor to delete our vector from the heap after the program finished

My_DA :: ~My_DA()
{
    delete[] data;
}

 