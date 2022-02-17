#include <iostream>
#include "myStack.hpp"
using namespace std;

/* bool checkBalence(myStack<char>* st){
    myStack<char>* fstb = new myStack<char>();
    myStack<char>* secb = new myStack<char>();
    myStack<char>* trdb = new myStack<char>();


    

} */

int main(){
    myStack<char>* create = new myStack<char>();
    char input;
    int iter = 10;

    while(iter--){
        cin >> input;     
        create->push(input, 0);
    }
    
    create->printStack();

    cout << endl;
    system("pause");
    return 0;
}