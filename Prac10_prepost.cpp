/*
Implement C++ program for expression conversion as infix to postfix and its evaluation using
stack based on given conditions:
Operands and operator, both must be single character. Input Postfix expression must be in a desired format. Only '+', '-', '*' and '/ ' operators are expected. */
#include<iostream> 
#include<string.h>
#include<string.h> 
using namespace std;
#define max 20
class Exp_stack
{
    private:
        int top;
        char stack[20];
        char postfix[max];
    public:
        Exp_stack()
            {
            top=-1;
            memset(stack,'\0',sizeof(stack));
            memset(postfix,'\0',sizeof(postfix));
            //postfix[max]='\0';
            }
        int isEmpty()
            {
                if(top==-1)
                return 1;
                else
                return 0;
            }
        int isFull()
            {
                if(top==max-1)
                return 1;
                else
                return 0;
                }
        void push(char ch)
                {
                    if(isFull())
                        {
                            cout<<"stack overflow"<<endl;
                        }
                    else
                        {
                            top++;
                            stack[top]=ch;
                        }
                }
        char pop()
            {
                if(isEmpty())
                    {
                        cout<<"stack underflow"<<endl;
                        return '\0';
                    }
                else
                    {
                        char ch=stack[top];
                        top--;
                        return ch;
                    }
            }
        int precedence(char c)
            {
                if(c=='^')
                {return 3;}
                if(c=='*'|| c=='/')
                {return 2;}
                if(c=='+'|| c=='-')
                {return 1;}
                else
                {return -1;}
            }
        int isOperator(char c)
            {
                if(c=='+'|| c=='-'|| c=='*'||c=='/'||c=='^')
                return 1;
                else
                return 0;
            }
        void infixtoPostfix()
            {
                char infix[max];
                cout<<"Enter infix exp:"<<endl;
                cin>>infix;
                cout<<"Infix Expr is:"<<infix<<endl;
                int n,j=0;
                n=strlen(infix);
                for(int i=0;i<n;i++)
                    {
                        if( ((infix[i] >= 'a') && (infix[i] <= 'z'))|| ((infix[i] >= 'A') && (infix[i] <= 'Z')))
                            {
                                postfix[j]=infix[i];
                                j++;
                            }
                        else if( infix[i]=='(')
                            {
                                push(infix[i]);
                            }
                        else if(infix[i] ==')')
                            {
                                while((stack[top]!='(') && (top!=-1))
                                    {
                                        char temp = pop();
                                        postfix[j]=temp;
                                        j++;
                                    }
                            if(stack[top]=='(')
                                {
                                    pop();
                                }
                            }
                            else if(isOperator(infix[i]))
                                {
                                    if(isEmpty())
                                    {
                                        push(infix[i]);
                                    }
                                else
                                    {
                                        if(precedence(infix[i]) > precedence(stack[top]))
                                            {
                                                push(infix[i]);
                                            }
                                else if( (precedence(infix[i]) == precedence(stack[top])) && (infix[i]=='^'))
                                    {
                                        push(infix[i]);
                                    }
                                else
                                    {
                                        while( (!isEmpty()) && (precedence(infix[i])<=precedence(stack[top])))
                                            {
                                                char temp = stack[top];
                                                postfix[j]=temp;
                                                j++;
                                                pop();
                                            }
                                        push(infix[i]);
                                    }
                                    }           
                                }
                        }
        while(!isEmpty())
            {
                postfix[j]=stack[top];
                j++;
                pop();
            }
        cout<<"\nThe conversion from infix to postfix is:"<<postfix<<endl;
            }
};

int main()
{
clrscr();
Exp_stack s1;
s1.infixtoPostfix();
return 0;
}