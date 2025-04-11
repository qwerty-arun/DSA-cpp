// 0,1,1,2,3,5,8,13,21...... (Fibonacci series)
// 0,1,2,3,4,5,6,7, 8..... (th element)
#include <iostream>

int fib(int n)
{
  if(n==0)
  {
    return 0;
  }
  if(n==1)
  {
    return 1;
  }
  return fib(n-1)+fib(n-2);
}

int main()
{
  int n = 8;
  std::cout<<n<<"th element of the fibonacci series is: "<<fib(n)<<"\n";
}

