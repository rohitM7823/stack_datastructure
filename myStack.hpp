#include<iostream>
#define null 0;
using namespace std;

struct stack{
    int top;
    int size;
    int* storage = nullptr;
};


template <typename typ>
class myStack{
    stack* stck;

public:
    myStack(int stackSize){
        stck = new stack;
        stck->top = -1;
        stck->size = stackSize;
        stck->storage = new typ[stck->size];
    }

    void push(typ data){
        if(stck->top == stck->size-1)
            cout << "Stack Overflow!!";
        else{
            stck->top++;
            stck->storage[stck->top] = data;
        }
    }

    int pop(){
        int value;
        if(stck->top < 0)
           return 0;
        else{
            value = stck->storage[stck->top];
            stck->storage[stck->top] = 0;
            stck->top--;
            stck->size--;
            return value;
        }
    }
    void isFull(){
        if(stck->top == stck->size-1)
            cout << "Stack is Full!!" << endl;
        else
            cout << "Stack is Not Full!!" << endl;
    }

    bool isEmpty(){
        if(stck->top < 0)
            return true;
        else 
            return false;
    }

    int atTop(){
        return stck->storage[stck->top];
    }

    int size(){
        return stck->top;
    }

    typ peek(int index){
        if(stck->top < 0)
            return false;
        else{
            typ d = stck->storage[(stck->top-index)+1];
            stck->top--;
            return d;
        }
    }

    void printStack(){
        for(int i=stck->top; i>=0; --i){
            cout << stck->storage[i] << " ";
        }
    }

    ~myStack(){
        delete stck;
    }

};




