//print Hllo in different language using swtich statement
#include<iostream>
using namespace std;

int main()
{
   char button;
   cout<<"Enter a character:";
   cin>>button;

   switch (button)
   {
    case 'a':
       cout<<"Hello"<<endl;
       break;

    case 'b':
       cout<<"Namaste"<<endl;
       break;
    default:
       cout<<"I am still learnig!"<<endl;
       break;

   }
   return 0; 
}