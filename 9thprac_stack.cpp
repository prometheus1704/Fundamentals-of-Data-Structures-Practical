#include<iostream>
#include<string.h>
using namespace std;
#define max 15

class stack
{

int top;
char exp[max];
public:

stack()
{
top =-1;
exp[max]='\0';
}
void push(char ch);
char pop();
int isempty();
int isfull();
void display();
void checkpara();
};
int stack :: isempty()
{
if (top==-1)
return 1;
else return 0;
}
int stack::isfull()
{
if (top==max-1)
return 1;
else return 0;
}
void stack :: display()
{
if(isempty()==1){
cout<<"\nStack is empty";}
else{for (int i=0;i<=top;i++)
{cout<<" "<<exp[i];
}
}
}
void stack::push(char ch)
{
if(!isfull())
{
top++;
exp[top]=ch;
}}
char stack:: pop()
{
if(!isempty())
{
char ch=exp[top];
top--;
return ch;
}
else
{
return '\0';
}}
void stack:: checkpara()
{
int flag=0;
cout<<"\nEnter the # as a dilimiter after the expression ";
cout<<"\nEnter expression : ";
cin.getline(exp,max,'#');
char ch;
 for(int i=0;exp[i]!='\0';i++)
 {
 if(exp[i]=='(' || exp[i]=='[' || exp[i] == '{' )
 {push (exp[i]);}
 
 if(exp[i]==')' || exp[i]==']' || exp[i] == '}' )
 {ch = pop ();}
 if ( (exp[i]==')'&& ch!='(')||(exp[i]==']'&&ch!='[')||(exp[i]=='}'&& ch!='{'))
 {
 cout<<"\nExp not parenthesized at "<<i<<"="<<exp[i];
 flag =1;
 break;
 }
 }
 if(isempty()==1 && flag==0)
 {cout<<"\nExp well parenthesized";}
 else
 {cout<<"\n Exp not parenthesized";}
 }
 int main()
 {
 char ch;
 do{
 stack s;
 s.checkpara();
 cout<<"\nWant to countinue (y/n)";
 cin>>ch;
 }
 while(
 ch=='y'||ch=='Y');
 return 0;
 }

