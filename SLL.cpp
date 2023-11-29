#include <iostream>
#include <stdio.h>
using namespace std;
class node
{
public:
int key, data;
node *next;
node()
{
key = 0;
data = 0;
next = NULL;
}
node(int k, int d)
{
key = k;
data = d;
next = NULL;
}
};
class singlyLL
{
public:
node *head;
singlyLL()
{
head = NULL;
}
singlyLL(node *n1)
{
head = n1;
}
node *NodeExist(int k)
{
node *temp = NULL;
node *ptr = head;
while (ptr != NULL)
{
if (ptr->key == k)
{
temp = ptr;
}
ptr = ptr->next;
}
return temp;
}
void appendnode(node *n)
{
if (NodeExist(n->key) != NULL)
{
cout << "Node already exists with key value" << n->key << endl;
}
else
{
if (head == NULL)
{
head = n;
cout << "node appended" << endl;
}
else
{
node *ptr = head;
while (ptr->next != NULL)
{
ptr = ptr->next;
}
ptr->next = n;
cout << "Node appended" << endl;
}
}
}
void prependnode(node *n)
{
if (NodeExist(n->key) != NULL)
{
cout << "Node Already exists with key value:" << n->key << endl;
}
else
{
n->next = head;
head = n;
cout << "Node Appended" << endl;
}
}
void insertnode(int k, node *n)
{
node *ptr = NodeExist(k);
if (ptr == NULL)
{
cout << "Node already exists with key value:" << k << endl;
}
else
{
n->next = ptr->next;
ptr->next = n;
}
}
void deletenode(int k)
{
node *p, *q;
p = head;
if (p == NULL)
{
cout << "SLL is empty" << endl;
}
else
{
if (p->key == k)
{
head = head->next;
free(p);
}
else
{
while (p != NULL && p->key != k)
{
q = p;
p = p->next;
}
if (p == NULL)
{
cout << "Nomatch Found" << endl;
}
else
{
if (p->key == k)
{
q->next = p->next;
free(p);
}
}
}
}
}
void print()
{
node *ptr = head;
while (ptr != NULL)
{
cout << ptr->key << " " << ptr->data << endl;
ptr = ptr->next;
}
}
};
int main()
{
singlyLL s;
int key1, data1, option, k;
do
{
cout << "\nSLL operations:" << endl;
cout << "1.Append node()" << endl;
cout << "2.Prepend Node node()" << endl;
cout << "3.Insert Node()" << endl;
cout << "4.Delete Node()" << endl;
cout << "5.print list()" << endl;
cout << "Enter the correct option, 0 to exit" << endl;
cin >> option;
node *n1 = new node();
switch (option)
{
case 0:
break;
case 1:
cout << "append node " << endl;
cin >> key1;
cin >> data1;
n1->key = key1;
n1->data = data1;
s.appendnode(n1);
break;
case 2:
cout << "Prepend node Operation:" << endl;
cin >> key1;
cin >> data1;
n1->key = key1;
n1->data = data1;
s.prependnode(n1);
break;
case 3:
cout << "Insert the key after which you want to insert:" << endl;
cin >> k;
cout << "Enter the Key and data value for the node to be inserted:" << endl;
cin >> key1;
cin >> data1;
n1->key = key1;
n1->data = data1;
s.insertnode(k, n1);
break;
case 4:
cout << "Delete Node Operatin:" << endl;
cout << "Enter the key for the node to be deleted:" << endl;
cin >> key1;
s.deletenode(key1);
break;
case 5:
cout << "SLL is " << endl;
s.print();
break;
default:
cout << "enter proper option" << endl;
}
} while (option != 0);
}

/*
SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
1
append node 
1 10
node appended

SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
2
Prepend node Operation:
2 20
Node Appended

SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
3
Insert the key after which you want to insert:
2
Enter the Key and data value for the node to be inserted:
3 30

SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
5
SLL is 
2 20
3 30
1 10

SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
4
Delete Node Operatin:
Enter the key for the node to be deleted:
2

SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
5
SLL is 
3 30
1 10

SLL operations:
1.Append node()
2.Prepend Node node()
3.Insert Node()
4.Delete Node()
5.print list()
Enter the correct option, 0 to exit
0
*/
