#include <iostream>
#include <vector>
#include <list>

class Stack{
    std::list<int> ll;
public:
    void push(int val)
    {
        ll.push_front(val);
    }
    int top()
    {
        return ll.front();
    }
    void pop()
    {
        ll.pop_front();
    }
    bool empty()
    {
        return ll.size() == 0;
    }

};


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty())
    {
        std::cout<<s.top()<<" "; 
        s.pop();
    }
    return 0;
}
