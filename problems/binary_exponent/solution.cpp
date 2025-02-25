// We have to compute x^n
#include <iostream>
int main()
{
  float x =2,n=-2;
  float binform=n,ans=1;
  if(x==0 && n==0)
  {
    std::cout<<"0^0 is Indeterminant!";
    return 0;
  }
  if(x==0 && n==-1)
  {
    std::cout<<"1/0 is Indeterminant!";
    return 0;
  }
  if(x==1)
  {
    ans =1;
  std::cout<<ans;
    return 0;
  }
  if(x==-1)
  {
    if(int(n)%2==1)
      ans=-1;
    else
      ans=1;
  std::cout<<ans;
    return 0;
  }
  if(n==0)
  {
    ans =1;
  std::cout<<ans;
    return 0;
  }
  if(x==0)
  {
    ans=0;
  std::cout<<ans;
    return 0;
  }

  if(n<0)
  {
    x = 1/x;
    binform = -binform;
  }
  while(binform > 0)
  {
    if(int(binform)%2==1)
    {
      ans*=x;
    }
    x*=x;
    binform/=2;
  }
  std::cout<<ans;
  return 0;
}
