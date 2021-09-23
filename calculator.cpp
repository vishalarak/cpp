// a simple calculator


#include<iostream>
using namespace std;

int main()
{
    int num1,num2;
    char op;

    cout<<"Enter the two numbers:";
    cin>>num1>>num2;

    cout<<"Enter the operand:";
    cin>>op;

    switch (op)
    {
        case '+':
        cout<<num1+num2<<endl;
        break;

        case '-':
        cout<<num1-num2<<endl;
        break;

        case '*':
        cout<<num1*num2<<endl;
        break;

        case '/':
        cout<<num1/num2<<endl;
        break;

        case '%':
        cout<<num1%num2<<endl;
        break;

        default:
        cout<<"Operator not found!";
        break;
    }
    return 0;
}