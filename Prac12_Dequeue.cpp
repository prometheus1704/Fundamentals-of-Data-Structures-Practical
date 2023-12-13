#include<iostream>
using namespace std;
#define max 20

class deque
{
	int arr[max];
	int front,rear;
	public:
	deque()
	{
		front = -1;
		rear = -1;	
	}	
	void enqueue_front(int x);
	void enqueue_rear(int x);
	void dequeue_front();
	void dequeue_rear();
	void Display();
};
void deque :: enqueue_front(int x)
{
	if(front==0 && rear==max-1)
	{
		cout<<"The queue is Full!!"<<endl;
	}
	else if(front==0 && rear!=max-1)
	{
		front=max-1;
		arr[front]=x;
		cout<<"The Element added : "<<arr[front]<<endl;
	}
	else if(front>rear && rear==front-1 )
	{
		cout<<"Deque is full!!"<<endl;
	}
	else
	{
		front--;
		arr[front]=x;
		cout<<"The Element added : "<<arr[front]<<endl;
	}
    
	if(front==-1)
	{
		front++;
	}
}

void deque :: enqueue_rear(int x)
{
	if (front==0 && rear==max-1)
	{
		cout<<"Queue is Full!!"<<endl;
	}
	else if (rear==-1)
	{
		rear++;
		arr[rear]=x;
		cout<<"The Element added : "<<arr[rear]<<endl;
	}
	else if(front!=0 && rear==max-1)
	{
		rear=0;
		arr[rear]=x;
		cout<<"The Element added : "<<arr[rear]<<endl;
	}
	else
	{
		rear++;
		arr[rear]=x;
		cout<<"The Element added : "<<arr[rear]<<endl;
	}
	if (front==-1)
	{
		front++;
	}
}

void deque :: dequeue_front()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is Empty!!"<<endl;
	}
	else if(front==max-1)
	{
		cout<<"The Element removed : "<<arr[front]<<endl;
		front=0;
	}
	else if(front>rear)
	{
		cout<<"The Element removed : "<<arr[front]<<endl;
		front++;
	}
	else
	{
		cout<<"The Element removed : "<<arr[front]<<endl;
		front++;
	}
}

void deque :: dequeue_rear()
{
	if(front==-1 && rear==-1)
	{
		cout<<"Queue is Empty!!"<<endl;
	}
	else if(front>rear && rear!=0)
	{
		cout<<"The Element removed : "<<arr[rear]<<endl;
		rear--;
	}
	else if(rear==0 && front!=max-1)
	{
		cout<<"The Element removed : "<<arr[rear]<<endl;
		rear=max-1;
	}
	else
	{
		cout<<"The Element removed : "<<arr[rear]<<endl;
		rear--;
	}
}

void deque :: Display()
{
	cout<<"\nElements in the deque:"<<endl;;
	int i=front;
	while(i!=rear+1)
	{
		cout<<arr[i]<<" ";
		i=(i+1)%max;
	}
}
int main()
{
	deque q;
	int choice;
	int a;
	do
	{
		cout << " \n1. Insert From Rear" << endl;
        cout << " 2. Insert From Front" << endl;
        cout << " 3. Remove From Rear" << endl;
        cout << " 4. Remove From Front" << endl;
        cout << " 5. Show all" << endl;
        cout << " 6. Exit" << endl;
        cout << " Enter choice:" ;
        cin >> choice;
        
        switch(choice)
        {
        	case 1:
        		cout<<"Enter the Number to entered at Rear:";
        		cin>>a;
        		q.enqueue_rear(a);
        		break;
        		
        	case 2:
        		cout<<"Enter the Number to entered at Front:";
        		cin>>a;
        		q.enqueue_front(a);
        		break;
        	
        	case 3:
        		q.dequeue_rear();
        		break;
        		
        	case 4:
        		q.dequeue_front();
        		break;
        		
        	case 5:
        		q.Display();
        		break;
        		
        	case 6:
        		cout<<"Thank you!!"<<endl;
        		break;
		}
    }while(choice!=6);
	return 0;
}




