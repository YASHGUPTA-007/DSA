#include <iostream>
using namespace std;

int Power(int a ,int b){
if(b == 0) return 1;
    return a * Power(a ,b-1);
}

int main()
{
  cout<<Power(2,2);

    return 0;
}