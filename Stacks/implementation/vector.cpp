#include <iostream>
#include <vector>

class Stack{
    std::vector<int> V;
public:
    void push(int val)
    {
        V.push_back(val);
    }
    int top()
    {
        return V[V.size()-1];
    }
    void pop()
    {
        V.pop_back();
    }
    void display()
    {
        std::cout<<"The stack: \n";
        for(int i = V.size()-1;i>=0;i--)
        {
            std::cout<<"| " << V[i]<<" |\n";
            std::cout<<"-----\n";

        }
        std::cout<<"|null|\n\n";
    }
    bool empty()
    {
        return V.size() == 0;
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
