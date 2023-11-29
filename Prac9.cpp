#include<iostream>
using namespace std;
const int Max = 15;

class stack
{
private:
	int top ;
	char exp[Max];
public:
     stack()
     {
	   top=-1;
	   exp[Max]='\0';
	}
	void push(char ch);
	char pop();
	int isEmpty();
	int isFull();
	void display();
	void checkParenthesis();
};

int stack::isEmpty()
{
  if(top==-1)
	return 1;
  else return 0;
}

int stack::isFull()
{
  if(top==Max-1)
  	return 1;
  else return 0;
}
 

void stack::display()
{
  if(isEmpty()==1)
  	cout<<"\nStack is Empty";
  else
  {
    for(int i=0;i<=top;i++)
     {
        cout<<" "<<exp[i];

     }
  }
}


void stack::push(char ch)
{
   if(!isFull())
   {
	top++;
	exp[top]=ch;
   }
}


char stack::pop()
{
   if(!isEmpty())
   {
     char ch=exp[top];
	top--;
	return ch;
   }
  else
  {
    return '\0';

  }	
}


void stack::checkParenthesis()
{
	int flag=0;
	cout<<"\n Enter # as a dilimiter after Expression:\n";
	cout<<"\n Enter Expression: ";
	cin.getline(exp,Max,'#');
	char ch;

	for(int i=0;exp[i]!='\0';i++)
	 {
	   if (exp[i] == '(' || exp[i]== '[' || exp[i]== '{')
		push(exp[i]);

	   if (exp[i] == ')' || exp[i]== ']' || exp[i]== '}')
	   {
	  ch=pop();
	  if ((exp[i] == ')' && ch!='(')||(exp[i]== ']' && ch!='[')|| (exp[i]== '}' && ch!='{'))
		{
		cout<<"\nExp not parethesized at"<<i<<"="<<exp[i];
	  flag=1;
	     break;
	      }
	}
	 }//end for
     if(isEmpty()==1 && flag==0)
	cout<<"\nExp well parethesized";
//	else
//cout<<"\nExp not parethesized ";
}



int main()
{
  char ch;
  do
  {
    stack s;
    s.checkParenthesis();
    cout<<"\n Do you want to continue?(y/n):";
    cin>>ch;
  }while(ch=='y'|| ch=='Y');
 return 0;
}
