#include <iostream>

using namespace std;


void rowCheck(char arr[3][3])
{
    for(int i=0;i<3;i++)
    {
        if((arr[i][0]==arr[i][1]) && (arr[i][0]==arr[i][2]))
        { 
            if(arr[i][0]=='O')
            {
                cout<<"Player 1 wins !!";
                exit(1);
            }
            else if(arr[i][0]=='X')
            {
                cout<<"Player 2 wins !!";
                exit(1);
            }
        }
    }
}

void columnCheck(char arr[3][3])
{
    for(int i=0;i<3;i++)
    {
        if(arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i])
        {
            if(arr[0][i]=='O')
            {
                cout<<"Player 1 wins !!";
                exit(1);
            }
            else if(arr[0][i]=='X')
            {
                cout<<"Player 2 wins !!";
                exit(1);
            }
        }
    }
}

void diagonalCheck(char arr[3][3])
{
    if(((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2]))|| ((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0])))
    {
        if(arr[1][1]=='O')
        {
            cout<<"Player 1 wins !!";
            exit(1);
        }
        else if(arr[1][1]=='X')
        {
            cout<<"Player 2 wins !!";
            exit(1);
        }
    }
}

char drawCheck(char arr[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]=='X' || arr[i][j]=='O' )
            {
                cout<<"Its a draw :("<<endl;
                return 1;
            }
        }
    }
}

void check(char arr[3][3])
{
    rowCheck(arr);
    columnCheck(arr);
    diagonalCheck(arr);
}

void print(char arr[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]=='X' || arr[i][j]=='O')
            {
                cout<<" "<<arr[i][j]<<" |";
            }
            else
            {
                cout<<" -"<<" |";
            }
        }
        cout<<"\n-------------\n";
    }
}


void input(char arr[3][3],int p)
{
    char num;
    input:
    cout<<"Player "<<p<<endl; 
    cout<<"Enter the number to mark: ";
    cin>>num;
    int n=num;
    // if(num>'0' && num<'10')
    // {
    //     n=num;
    // }
    // else
    // {
    //     cout<<"Invalid Input"<<endl;
    //     goto input;
    // }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==n)
            {
                if(p==1)
                {
                    arr[i][j]='O';
                    break;
                }
                else if(p==2)
                {
                    arr[i][j]='X';
                    break;
                }
            }
            // else
            // 
        }
    }
    print(arr);
    check(arr);
}

int main()
{
    cout<<"\nHello and welcome to my Tic-Tac-Toe game :)"<<endl;
    cout<<"Lets Get started !!\n";
    cout<<"Input table is as follows: "<<endl;
    char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<" "<<matrix[i][j]<<" |";
        }
        cout<<"\n-------------\n";
    }
    cout<<"You have to select any one Number in the table to put 'O' or 'X' in it."<<endl;
    cout<<"For Player 1: O"<<endl<<"    Player 2: X\n"<<endl;
    for(int i=0;i<4;i++)
    {
        input(matrix,1);
        input(matrix,2);
    }
    input(matrix,1);
    drawCheck(matrix);
    return 0;
}
