// To print row and column
#include<iostream>
using namespace std;

int main()
{
    int row, col;
    cout<<"Enter the no of rows and columns:";
    cin>>row>>col;

    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}