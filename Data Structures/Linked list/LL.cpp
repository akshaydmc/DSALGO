#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};

void insertb(int d,node **h)
{
	node* temp= new node();
	temp->data=d;
	temp->next=(*h);
	*h=temp;
}
void display(node* h)
{
	node* temp= (h);
	while(temp!=NULL)
	{
		
		
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void append(int d, node** h)
{
		if((*h)==NULL)
		{
		*h= new node();
		(*h)->data=d;
		(*h)->next=NULL;
		return;
		}
		
	node* temp = (*h);
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	node* temp2 = new node();
	temp2->data=d;
	temp2->next=NULL;
	temp->next=temp2;

}
void reverse(node** h)
{
	node * curr=(*h);
	node *prev=NULL, *next=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	(*h)=prev;
}
void insertbefore(int d,int dd,node** h)
{
	node *temp = new node();
	temp->data=d;
	node *curr=(*h);
	node *prev=NULL;
	while(curr->data!=dd)
	{
		prev=curr;
		curr=curr->next;
	}
	temp->next=curr;
	prev->next=temp;
}
void Deletewithdata(int d,node** h)
{
	if((*h)==NULL) // if no element in l.l
	{
		return;
	}
	if((*h)->next==NULL) // if there is only one node
	{
		if((*h)->data==d) //  and that node is to be deleted
		{
		(*h)=(*h)->next;
			return;
		}
		// one node is not matched
//		cout<<" data is not in l.l"<<endl;
		return;
		
	}
	
	node * prev=NULL;
	node *curr=(*h);
	while(curr!=NULL && curr->data!=d)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL)
	{
	//cout<<" data is not in l.l"<<endl;
		return;
	}
	prev->next=curr->next;
	curr->next=NULL;
	
	return;
	
}
void insertafter(int d,int dd,node** h)
{
	node *temp= new node();
	temp->data=d;
	node *curr=(*h);
	node *next=NULL;
	while(curr->data!=dd)
	{
		
		curr=curr->next;
		next=curr->next;
	 } 
	 temp->next=next;
	 curr->next=temp;
}
void reverseList(node *head)
{
	if(head==NULL)
	{
	return;
	}
	reverseList(head->next); // reverse l.l of next link first
	cout<<head->data<<" ";
	
}
void findmiddle(node *head)
{
	node *s=head;
	node *f=head;
	node *prevs=head;
	while(f&&f->next&&s)
	{
	
		f=f->next->next;
		prevs=s; // 2nd middle if even (i.e the first middle from left)
		s=s->next;
	}
	cout<<s->data<<endl;
	
}
bool checkpalindrome(node *head)
{
	// Algo go to middle and reverse either first half or second half and compare if ele are equal simple
	//if we dont want to change the order  we will reverse again the ll  again 
	// we can also check this by using a vector or a stack but if they say to do it without using extra space this is approach
	
	// let's reverse the later part of middle
	
	// go to middle
	node *f=head;
	node *s=head;
	node *prevs=head;
	node * hh=head;
	while(f&&f->next)
	{
		f=f->next->next;
		prevs=s;
		s=s->next;
	}
	if(f==NULL)//  if even then reverse from middle
	{ node *prev=NULL;
	node* next=s;
		while(s!=NULL)
		{
			next=s->next;
			s->next=prev;
			prev=s;
			s=next;
		}
	prevs->next=prev;
	while(prev!=NULL)
	{
		if(prev->data!=hh->data)
		return false;
	}
	return true;
	}
	else //odd if odd then reverse without involving middle
	{node * ss= s->next;
	node* next=ss;
	node* prev=NULL;
	while(ss!=NULL)
	{
		next=ss->next;
		ss->next=prev;
		prev=ss;
		ss=next;
	}
	prevs->next->next=prev;
	while(prev!=NULL)
	{
		if(prev->data!=hh->data)
		return false;
	}
	return true;	
}
}
int main()
{
cout<<" 1. Insert node at begining"<<endl;
cout<<" 2. Append a node"<<endl;
cout<<" 3. display the l.l"<<endl;
cout<<" 4. Insert before a selected node"<<endl;
cout<<" 5. Insert after a selected node "<<endl;
cout<<" 6.Delete a particular node"<<endl;
cout<<" 7.Reverse A L.L "<<endl;
cout<<" 8. Do bot reverse the l.l but display the reversed order (using recursion)"<<endl;
cout<<"9. find middle element in a list using slow and fast pointer"<<endl;
cout<<"10. check if linked list is palindrome or not (we know if even f=NULL odd f->next=NULL)"<<endl;
cout<<" 11. exit"<<endl;
//
//after a selected node   

	int n,d,dd;
	
	node* head=NULL;
	
	while(1)
	{
 cin>>n;
	switch(n)
	{
		case 1:
		
			
			cin>>d;
			insertb(d,&head);
			
			 // see we are not returning any node since we are modifing by adderss in fun we use**
			// itll be modified in list 
			// we'll modify the head as new inserted element
			break;
		case 2:
			//append
			cin>>d;
			append(d,&head);
			break;
		case 3:
		display(head);
		break;
		case 4:
			cout<<" enter the data to enter \n";
			cin>>d;
			cout<<" enter the data before which "<<d<<"should be added"<<endl;
			cin>>dd;
			insertbefore(d,dd,&head);
			break;
		case 5:
			cout<<" enter the data to enter \n";
			cin>>d;
			cout<<" enter the data after which "<<d<<"should be added"<<endl;
			cin>>dd;
			insertafter(d,dd,&head);
			break;
		case 6:
			cout<<" enter the data to be deleted \n";
			cin>>d;
			Deletewithdata(d,&head);
			break;
		case 7:
			reverse(&head);
			break;
		case 8:
			reverseList(head); // not sending & as we just have to print
			break;
		case 9:
			findmiddle(head); // not sending & as we just have to print
			break;
		case 10:
			cout<<checkpalindrome(head)<<endl; // not sending & as we just have to print
			break;	
		default:
			break;
	}
}

}
