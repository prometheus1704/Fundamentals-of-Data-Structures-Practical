#include <iostream>
#include <string.h>
using namespace std;

#define Max 15 

class Stack
{
    int top;
    char exp[Max];

    public:
        Stack()
        {
            top=-1;
            exp[Max]='\0'	;
        }
        void push(char ch);
        char pop();
        int isEmpty();
        int isfull();
        void display();
        void check_parenthesis();

};

int Stack :: isEmpty()
{
    if (top==-1) { return 1;}
    else { return 0; }
}

int Stack :: isfull ()
{
    if (top==Max-1) { return 1;}
    else { return 0; }
}

void Stack :: display()
{
    if (isEmpty()==1) { cout<<" The Stack is empty"<<endl;}
    else 
    {
        for (int i=0;i<=top;i++)
        cout<<""<<exp[i];
    }
}

void Stack :: push(char ch)
{
    if ( isfull()==0 )
    {
        top++;
        exp[top]=ch;
    }
}
char Stack :: pop()
{
    if (isEmpty()==0)
    {
        char ch = exp[top];
        top--;
        return ch;
    }
    else 
    {
        return '\0';
    }
}

void Stack :: check_parenthesis()
{
    int flag=0;
    cout<<"\nEnter # as dilimiter after expression: \n ";
    cout<<"\nEnter Expression : ";
    cin.getline(exp,Max,'#');
    char ch;

    for (int i=0;exp[i]!='\0';i++)
    {
        if (exp[i]=='(' || exp[i]=='[' || exp[i]=='{') { push(exp[i]);}

        if (exp[i]==')' || exp[i]==']' || exp[i]=='}') 
        {
            ch=pop();
            if ((exp[i]==')'&& ch!='(') || (exp[i]==']' && ch!='[') || (exp[i]=='}' && ch!='{' ) )
            {
                cout<<"\nExp not parethesized at "<<i<<"="<<exp[i];
                flag=1;
                break;
            }
        }
    }
    if(isEmpty()==1 && flag==0)
    {
        cout<<"\nExp well parethesized";
    }
}


int main()
{
    char ch;
    do 
    {
        Stack s;
        s.check_parenthesis();
        cout<<"\n Do you want continue?(y/n):";
        cin>>ch;
    }
    while(ch=='y' || ch=='Y');
    return 0;
}
