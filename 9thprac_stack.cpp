#include<iostream>
#include<string>
using namespace std;
#define max 15

class Stack
{
    public:
    int top;
    char gof[max];
    
    public:
    Stack()
    {
       top=-1;
       gof[max]='\0';
    }
    void push(char ch);
    char pop();
    int isempty();
    int isfull();
    void display();
    void checkparanthesis();
};

void Stack::push(char ch)
{
    if(!isfull())
    {
       top++;
       gof[top]=ch;
    }
}

char Stack:: pop()
{
    if(!isempty())
    {
        char ch=gof[top];
        top--;
        return ch;
    }
    else
    {
        return '\0';
    }
}

int Stack :: isempty()
{ 
    if(top==max-1)
      return 1;
    else
      return 0;
}

int Stack:: isfull()
{
     if(top==max-1)
      return 1;
    else
      return 0;
}
void Stack :: display()
{
    if(!isempty()==1)
       cout<<"The stack is empty";
    else
    {
       for(int i=0; i<=top ; i++)
       {
          cout<<" "<<gof[i];
       }
    }
}

void Stack :: checkparanthesis()
{
    int flag=0;
    cout<<"Enter # as a dilimiter after expression"<<endl;
    cout<<"Enter the Expression:"<<endl;
    cin.getline(gof,max,'#');
    char ch;
    
    for(int i=0 ; gof[i]!='\0' ; i++)
    {
       if(gof[i]=='(' || gof[i]=='{' || gof[i]=='[')
          push(gof[i]);
       if(gof[i]==')' || gof[i]=='}' || gof[i]==']')
       {
          ch=pop();
          if(gof[i]==')' && ch!='(' || gof[i]=='}' && ch!='{' || gof[i]==']' && ch!='[')
          {
             cout<<"Expression is not paranthesis at "<<i<<"="<<gof[i];
             flag=1;
             break;
          }
       }   
    }
    if(isempty()==1 && flag==0)
    {
       cout<<"Expression well paranthesized"<<endl;
    }
    else
    {
       cout<<"Expression not paranthesized"<<endl; 
    }
}

int main()
{
char ch;
do
{
  Stack s;
  s.checkparanthesis();
  cout<<"Do you want to continue ? (y/n)";
  cin>>ch;
  cin.get(ch);
}while(ch=='y' || ch=='Y') ;

return 0;
 
}
