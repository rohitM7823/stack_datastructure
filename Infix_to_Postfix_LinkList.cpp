#include <iostream>
#include <string>
#include "stack_using_LinkList.hpp"
using namespace std;

int outPrecedence(char oper){
    if(oper == '+' || oper == '-')
        return 1;
    else if(oper == '*' || oper == '/')
        return 3;
    else if(oper == '^')
        return 6;
    else if(oper == '(')
        return 7;
    else return 0;
}

int inPrecedence(char oper){
    if(oper == '+' || oper == '-')
        return 2;
    else if(oper == '*' || oper == '/')
        return 4;
    else if(oper == '^')
        return 5;
    else if(oper == '(')
        return 0;
    else return 0;
}

string* convertPostfix(string* infix){
    MyStack<char>* stack = new MyStack<char>();
    string* postfix = new string();
    int i = 0;

    while(i < infix->size()){

        if(infix->at(i) >= 40 && infix->at(i) <= 43 || infix->at(i) == 45 || infix->at(i) == 47 || infix->at(i) =='^'){

            if(stack->isEmpty()) stack->push(infix->at(i++));

            else if(outPrecedence(infix->at(i)) < inPrecedence(stack->atTop())){
                while(stack->getTop()>=0){
                    if(stack->atTop() != 40)
                        postfix->push_back(stack->pop());
                    else stack->pop();
                }
                if(infix->at(i) != 41)
                    stack->push(infix->at(i++));
                else i++;
            }

            else stack->push(infix->at(i++));
        }
        else postfix->push_back(infix->at(i++));
    }

    if(!stack->isEmpty()){
        while(stack->getTop()>=0)
            postfix->push_back(stack->pop());
    }

    postfix->push_back('\0');


    return postfix;
}

int main(){
    string* exp = new string();
    string* result = nullptr;

    getline(cin, *exp);

    result = convertPostfix(exp);

    cout << *result << endl; 

    /* for(int i=0; i<exp->length(); ++i)
    stack.push(exp->at(i));

    stack.pop();
    stack.pop();
    stack.pop();

    stack.print(); */
    cout<< endl;
    system("pause");
    return 0;
}