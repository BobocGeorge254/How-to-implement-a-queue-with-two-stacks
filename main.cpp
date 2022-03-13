#include <iostream>

using namespace std;

class Stack {

    int st[100] ;
    int Top ;
public :
    Stack(){ Top = -1 ; }
    void push(int x) {
        Top ++ ;
        st[Top] = x ;
    }
    void pop() {
        Top -- ;
    }
    int top(){
        return st[Top] ;
    }
    bool empty() {
        return Top == -1 ;
    }
};


class Queue {

    Stack stack1, stack2;
    int Top;
public:
    Queue() { Top = 0 ; }
    void push(int x) {
        stack1.push(x);
        Top ++ ;
    }
    void pop() {
        while(!stack1.empty()) {
            int x = stack1.top();
            stack1.pop();
            stack2.push(x);
        }
        stack2.pop();
        while(!stack2.empty()) {
            int x = stack2.top();
            stack2.pop();
            stack1.push(x);
        }
    }
    int top(){
        return stack1.top();
    }
    void printq(){
        while(!stack1.empty()) {
            int x = stack1.top();
            stack1.pop();
            stack2.push(x);
        }
        while(!stack2.empty()) {
            int x = stack2.top() ;
            cout << x << " " ;
            stack2.pop();
            stack1.push(x);
        }
    }
};

int main()
{
    Queue q;
    q.push(100);
    q.push(200);
    q.push(250);
    q.pop();
    q.printq();
}
