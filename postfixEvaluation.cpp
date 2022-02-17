#include <iostream>
#include "stack_using_LinkList.hpp"

bool isOperand(char rand){
    if(rand >= '0' && rand <= '9')
        return true;
    else return false;
}

int getOperand(char rand){
    return rand - '0';
}

int postfixEvaluation(string express){
    MyStack<int>* st = new MyStack<int>();
    int lOperand, rOperand, result;

    for(int i=0, e; i<express.length(); i++){
        if(isOperand(express[i]))
            st->push(getOperand(express[i]));
        else{
            lOperand = st->pop();
            rOperand = st->pop();
            switch(express[i]){
                case '*':    
                    e = lOperand * rOperand;
                    st->push(e);
                    break;
                case '/':
                    e = rOperand / lOperand;
                    st->push(e);
                    break;
                case '+':
                    e = lOperand + rOperand;
                    st->push(e);
                    break;
                case '-':
                    e = rOperand - lOperand;
                    st->push(e);
                    break;
                default:
                    break;
            }
        }
    }
    result = st->pop();

    return result;
}

int main(){
    string exp("234*+82/-");
    
    int output = postfixEvaluation(exp);
    
    cout << exp << endl <<endl <<"Evaluated: " << output << endl;

    system("pause");
    return 0;
}