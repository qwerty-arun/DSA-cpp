#include <iostream>
#include <vector>
#include <list>
#include <stack>

int main() {
    std::stack<int> s;
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
