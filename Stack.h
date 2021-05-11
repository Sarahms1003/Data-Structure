#pragma once
#ifndef STACK_ADT_
#define STACK_ADT_

template<typename T>
class Stack
{
    
private:
        int top;
        int a[MAX]; // Maximum size of Stack
public:
        Stack() { top = -1; }
        bool push(T& newEntry);
        bool pop();
        int peek();
        bool isEmpty() const;
        //toArray function to be used ONLY when drawing the queue items
        const T* toArray(int& count);	//returns array of T (array of items)
        ~Stack();
};


template <typename T>
 bool Stack<T>::isEmpty() const 
{
     return (top < 0);

}

template<typename T>
 bool Stack<T>::push(T& newEntry)
{
     if (top >= (MAX - 1)) 
     {
         return false;
     }
     else {
         a[++top] = newEntry;
         return true;
     }
}

template<typename T>
bool Stack<T>::pop() 
{
    if (top < 0) //The Stack is empty
    {
        return 0;
    }
    else {
        int TopEntry = a[top--];
        return TopEntry;
    }
}

template<typename T>
int Stack<T>:: peek() 
{
    if (top < 0) 
    {
        return 0;
    }
    else {
        int topEntry = a[top];
        return topEntry;
    }
}
template<typename T>
Stack<T>::~Stack() 
{
}
template <typename T>
const T* Stack<T>::toArray(int& count)
{
    Stack<T> newStack = new Stack<T>();
    count = 0;
    if (isEmpty())
        return false;
    //counting the no. of items in the stack
    else
    {
        while (!isEmpty())
        {
            newStack.push(this.pop());
            count++;
        }
        for (int i = 0; i < count; i++)
        {
            this.push(newStack.pop());
        }

        T* Arr = new T[count];
        for (int i = 0; i < count; i++)
        {
            Arr[i] = Stack::pop();
        }
        return Arr;
    }
}
#endif
