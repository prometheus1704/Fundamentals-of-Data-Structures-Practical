#include<iostream>
#include<string>
using namespace std;
#define max 20  //Preprocessor directive

class stack
{
    char arr[max];
    int top;

public:
    stack()
    {
        top = -1;
    }
    void push(char x);
    char pop();
    void Checkparanthesis();
    void Display();
};

void stack::push(char x)
{
    if (top == max - 1)
    {
        cout << "Stack Overflow!!" << endl;
    }
    else
    {
        top++;
        arr[top] = x;
    }
}

char stack::pop()
{
    if (top == -1)
    {
        cout << "Stack underflow!!" << endl;
        return '\0'; // Return a default value in case of underflow
    }
    else
    {
        return arr[top--];
    }
}

void stack::Display()
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "The elements in the stack are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void stack::Checkparanthesis()
{
    cout << "Enter the Expression with delimiter # at the end:";
    cin.getline(arr, max, '#');
    char ch;
    int flag = 0;

    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{')
        {
            push(arr[i]);
        }
        if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            ch = pop();
            if ((arr[i] == ')' && ch != '(') || (arr[i] == ']' && ch != '[') || (arr[i] == '}' && ch != '{'))
            {
                cout << "Expression Not parenthesized!!" << endl;
                flag = 1;
                break;
            }
        }
    }

    if (top != -1 && flag == 0)
    {
        cout << "Expression Not parenthesized!!" << endl;
    }
    else if (top == -1 && flag == 0)
    {
        cout << "Expression well parenthesized!!" << endl;
    }
}


int main()
{
    stack s;
    s.Checkparanthesis();
    return 0;
}
