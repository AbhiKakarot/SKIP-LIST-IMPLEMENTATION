#include<iostream>
using namespace std;




/* 
	structure definition
*/
struct skiplist
{
int data;

skiplist *left;
skiplist *right;
skiplist *up;
skiplist *down;
}*head,*tail,*ptr,*curr;

/* 
	insertion
*/

void insertion()
{
int data,i;
ptr = head;
char ch;
skiplist *x,*temp,*h1,*t1;
int r=0,count=-1;
do
{
ptr = head;
count = 0;
cout<<"Enter an item to insert"<<endl;
cin>>data;
while(data > ptr->data)
{
ptr = ptr->right;
if(ptr->data > data)
{ptr = ptr->left;
if(ptr->down!=NULL)
{ptr = ptr->down;
head = head->down;
tail = tail->down;
}
else{break;}
}
}
if((data == ptr->data)||(data == ptr->right->data))
{
cout<<"Value already exists"<<endl;
while(head->up !=NULL)
{
head = head->up;
tail = tail->up;
}
break;
}
srand(time(0));
do
{
r = rand()%2;
count = count + 1;
}while(r==1);

x = new skiplist();
x->data = data;
x->right = ptr->right;
x->left = ptr;
x->down = NULL;
ptr->right = x;
x->right->left = x;

i=0;

while(i<count)
{

temp = new skiplist();
temp->data = x->data;

if (head->up == NULL)
{
h1 = new skiplist();
h1->data = head->data;
head->up = h1;
h1->down = head;
t1 = new skiplist();
t1->data =  tail->data;
tail->up = t1;
t1->down = tail;
head = head->up;
tail = tail->up;
head->right = temp;
tail->left = temp;
temp->left = head;
temp->right = tail;
head->left = NULL;
tail->right = NULL;
head->up = NULL;
tail->up = NULL;
temp->down = x;
x->up = temp;
x = temp;
}
else
{
head = head->up;
tail = tail->up;
ptr = head;
while(temp->data > ptr->data)
{
ptr = ptr->right;
if(ptr->data > data)
{ptr = ptr->left;
break;}
}
temp->right = ptr->right;
temp->left = ptr;
ptr->right = temp;
temp->right->left = temp;
temp->down = x;
x->up = temp;
x = temp;
}

i++;
}

while(head->up !=NULL)
{
head = head->up;
tail = tail->up;
}


cout<<"want to insert more"<<endl;
cin>>ch;
}while(ch=='y');


}


/* 
	display
*/

void display()
{
skiplist *temp,*h1,*t1;

while(true)
{
if(head->right == tail)
{
h1 = head;
t1 = tail;
head = head->down;
tail = tail->down;
head->up = NULL;
tail->up = NULL;
delete(h1);
delete(t1);
}
else{break;}
}
temp = head;
h1 = head;
t1 = tail;
while(temp->down!=NULL)
{
temp = h1;
temp = temp->right;
	cout<<"h-->";
	while(temp != t1)
	{
		cout<<temp->data<<"-->";
		temp = temp->right;
	}
	cout<<"t";
cout<<endl;
h1 = h1->down;
t1 = t1->down;
}


}


/* 
	deletion
*/

void deletion()
{
skiplist *temp,*ptr,*h1,*t1;
ptr = head;
h1 = head;
t1 = tail;
int data;
char ch;
do
{
ptr = head;
cout<<"Enter the element you want to delete"<<endl;
cin>>data;

while(data > ptr->data)
{
ptr = ptr->right;

while(ptr->data == data)
{
ptr->left->right = ptr->right;
ptr->right->left = ptr->left;
temp = ptr;
ptr = ptr->down;
delete(temp);
if(ptr == NULL)
break;
}
if(ptr == NULL)
break;
if(ptr->data > data)
{ptr = ptr->left;
if(ptr->down!=NULL)
{ptr = ptr->down;
}
}

if((ptr->right->data > data)&&(ptr->right->data != data)&&(ptr->down == NULL))
{
cout<<"Doesn't exist"<<endl;
break;
}
}


cout<<"Delete more?"<<endl;
cin>>ch;
}while(ch == 'y');

}


/* 
	main function
*/

int main()
{

head = new skiplist();
tail = new skiplist();
head->data = -2147483648;
tail->data = 2147483647;
head->right = tail;
tail->left = head;
head->left = NULL;
head->down = NULL;
head->up = NULL;
tail->right = NULL;
tail->down = NULL;
tail->up = NULL;

char ch;
cout<<"Program to implement skip list"<<endl;

do
{
cout<<"Perform"<<endl<<"press i . Insertion"<<endl<<"press d . Deletion"<<endl<<"press D . display"<<endl;
cin>>ch;
switch(ch)
{
case 'i':insertion();
break;
case 'd':deletion();
break;
case 'D':display();
break;
default:
cout<<"Invalid choice"<<endl;
break;
}
cout<<"Want to perform more operations"<<endl;
cin>>ch;
}while(ch == 'y');

return 0;
}
