#include <iostream>
using namespace std;
class mynode
{
public:
char booking_status;
mynode *next;
mynode *prev;
};
class theater
{
public:
mynode *head,*last;
theater()
{
head=NULL;
}
void create();
void show();
void book_tkt();
void cancel_tkt();
};
void theater::create()
{
mynode *n;
for(int i=0; i<=7; i++)
{
n=new mynode();
n->booking_status='\0';
n->prev = NULL;
if(head==NULL)
{
head=n;
n->next=head;
}
else
{
mynode *t1,*t2;
t1=head;
while(t1->next!=head)
{
t2=t1;
t1=t1->next;
}
t1->next=n;
n->prev=t1;
n->next=head;
t1->prev=t2;
}
}
}
void theater::show()
{
mynode *temp;
temp = head;
while(temp->next!=head)
{
cout<<"("<<temp->booking_status<<")"<<"\t";
temp=temp->next;
}
}
void theater::book_tkt()
{
mynode *temp;
int row1,i;
cout<<"\nEnter seat number you want to book:";
cin>>row1;
temp=head;
for( i=1; i<row1;i++)
{
temp=temp->next;
}
if(temp->booking_status=='B')
{
cout<<"\nSeat is already booked. Please try for another seat";
}
else
{
temp->booking_status='B';
}
}
void theater::cancel_tkt()
{
mynode *temp;
int row1,i;
cout<<"\nEnter Seat Number to cancel: ";
cin>>row1;
temp=head;
for(i=1;i<row1;i++)
{
temp=temp->next;
}
if(temp->booking_status=='\0')
{
cout<<"\nThe selected seat is free\n\n";
}
else
{
temp->booking_status='\0';
}
}
int main()
{
// doublyLL s;
int row,j=1,option,i,k;
theater c[10];
for(int i=1;i<=10;i++)
{
c[i].create();
}
//To display column numbers
for(int a=0;a<7;a++)
{
cout<<"\t"<<j;
++j;
}
cout<<endl;
//To show status of all seats at the beginning
j=1;
for(i=1;i<=10;i++)
{
cout<<j<<"\t";
c[i].show();
cout<<endl;
++j;
}
do
{
cout<<"\nUsing Circular DLL Theate Ticket-Booking Operation:"<<endl;
cout<<"1.Display Ticket status"<<endl;
cout<<"2.Book ticket"<<endl;
cout<<"3.Cancel ticket"<<endl;
cout<<"Enter correct option, 0 to exit"<<endl;
cin>>option;
switch(option)
{
case 0:
break;
case 1:
cout<<"Current Booking Status:"<<endl;
j=1;
for(int i=1;i<=10;i++)
{
cout<<j<<"\t";
c[i].show();
cout<<endl;
++j;
}
break;
case 2:
cout<<"Booking Operation:"<<endl;
cout<<"\nEnter row number to book seat:";
cin>>row;
c[row].book_tkt();
j=1;
for(int k=0;i<7;k++)
{
cout<<"\t"<<j;
++j;
}
cout<<endl;
j=1;
for(i=1;i<=10;i++)
{
cout<<j<<"\t";
c[i].show();
cout<<endl;
++j;
}
break;
case 3:
cout<<"Booking cancel Operation:"<<endl;
cout<<"\nEnter row number to cancel seat:";
cin>>row;
c[row].cancel_tkt();
j=1;
for( k=0;i<7;k++)
{
cout<<"\t"<<j;
++j;
}
cout<<endl;
j=1;
for(i=1;i<=10;i++)
{
cout<<j<<"\t";
c[i].show();
cout<<endl;
++j;
}
break;
default:
cout<<"Enter proper option"<<endl;
}
}while(option!=0);
return 0;
}
