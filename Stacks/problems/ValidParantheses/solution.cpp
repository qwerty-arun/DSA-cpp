#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string str)
{
    std::stack<char> s;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == '{' || str[i]=='(' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else
        {
            if(s.empty())
                return false;
            if(str[i] == '}' && s.top()=='{')
                s.pop();
            if(str[i] == ')' && s.top()=='(')
                s.pop();
            if(str[i] == ']' && s.top()=='[')
                s.pop();
        }
    }
    return s.empty();
}
int main() {
    std::string str = "[{}()]";
    if(isValid(str))
    {
        std::cout<<"Valid\n";
    }
    else
        std::cout<<"Nooooo!\n";
    return 0;
}
