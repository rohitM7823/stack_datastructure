#include <iostream>
using namespace std;

template <typename dtyp>
struct node{
    dtyp data;
    node* link = nullptr;
};

template <typename typ>
class MyStack{
    node<typ>* exp = nullptr;
    node<typ>* q = nullptr;
    node<typ>* k = nullptr;
    node<typ>* p = nullptr;
    int top;
public:
    int size;
    MyStack(){
        exp = new node<typ>;
        p = exp;
        top = -1;
        size = 0;
    }

    void push(typ input){
        if(top < 0){
            p->data = input;
            top++;
            size++;
        }
        else{
            p->link = new node<typ>;
            p = p->link;
            p->data = input;
            top++;
            size++;
        }
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }

    bool isFull(){
        if(top+1 == size) return true;
        else return false;
    }

     int atTop(){
        k = exp;
        for(int i=0; i<top; ++i)
            k = k->link;

        return k->data;
    }

    int pop(){
        int val;
        if(top == -1)
            return 0;
        else{
            if(top == 0){
                node<typ>* head = exp;
                val = head->data;
                exp = new node<typ>;
                p = exp;
                top--;
                return val;
            }
            else{
                node<typ>* j = nullptr;
                val = p->data;

                for(int i=0; i<top; ++i){
                    if(j == NULL)
                        j = exp;
                    else j = j->link;
                } 

                p = j;
                j->link = nullptr;
                top--;
                return val;
            }
        }
    }

   
    typ peek(int index){
        q = exp;
        if(index-1 > top) return false;
        else{
            for(int i=0; i<index; ++i)
                q = q->link;

            return q->data;
        }
    }

    inline int getTop(){
        return top;
    }

    void print(){
        node<typ>* disp = exp;
        for(int i=0; i<=top; ++i){
            cout << disp->data << " ";
            disp = disp->link;
        }
    }

    ~MyStack(){
        delete exp;
    }

};