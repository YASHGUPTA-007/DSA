#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    int n;
    int count = 0;

   cin>>str;

   for(int i =0; i<str.length();i++){
    if(str.length() == 1){
        break;
    }
    if(i==2 && str[0]!=str[1]){
        
        count++;
    }
    if(i==0){
        if(str[i]!=str[i+1]);
        count++;
    }
    else if(i==str.length()-1){
        if(str[i]!=str[i-1]);
        count++;
    }
    
    else if(str[i]!=str[i+1] && str[i]!=str[i-1]){
        count++;
    }
   }

   cout<<"number of Neighbours character different matching to its are:"<<count;
}