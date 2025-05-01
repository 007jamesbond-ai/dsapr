#include<iostream>
using namespace std;
class node
{ 
	public:

	 	node *leftc;
		int data;
		node *rightc;
	
};

class binarytree
{
	private:
		node *temp;
		int op;
		char ch;
	public:
		node *root;
		
	 binarytree()
		{
		root=NULL;
		}
	 
		void create();
		void insert(node*,node*);
		void inorder(node*);
		void preorder(node*);
		void postorder(node*);
};	


void binarytree::create()
{
	int value;
	do
	{
		temp=new node;
		cout<<"Enter the value: "<<endl;
		cin>>value;
		temp->data=value;
		temp->leftc=temp->rightc=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			insert(root , temp);
		}
	cout<<"Enter the option: "<<endl;
	cin>>op;
	}while(op==1);
}

void binarytree::insert(node *root, node *temp)
{
	cout<<"Where to insert new node temp -> data left root->data or right of root->data (press l or r)"<<endl;
	cin>>ch;
	if(ch=='L'||ch=='l')
	{
		if(root->leftc==NULL)
			root->leftc=temp;
		else
			insert(root->leftc ,temp);
	}
	else
	{
		if(root->rightc==NULL)
			root->rightc=temp;
		else
			insert(root->rightc ,temp);
	}
}
	 
void binarytree :: inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->leftc);
		cout<<root->data<<" ";
		inorder(root->rightc);
	}
}

void binarytree :: preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->leftc);
		preorder(root->rightc);
	}
}

void binarytree :: postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->leftc);
		postorder(root->rightc);
		cout<<root->data<<" ";
	}
}

int main()
{
	 binarytree B;
	 int choice;
	 
	 while(1)
	 {
	 	cout<<"\nMENU"<<endl;
	 	cout<<"1. Create a binary tree\n";
	 	cout<<"2. Insert a new_node in the binary tree\n";
	 	cout<<"3. Display Inorder tree\n";
	 	cout<<"4. Display Preorder tree\n";
	 	cout<<"5. Display Postorder tree\n";
	 	cout<<"6.Exit\n";
	 	cout<<"ENTER YOUR CHOICE\n";
	 	cin>>choice;
	 
		 switch(choice)
	 		{
		 		case 1:
	 	 		case 2:
	 				B.create();
	 				break;
				case 3:
	   	  			B.inorder(B.root);
	       				break;
	       			case 4:
	   	  			B.preorder(B.root);
	       				break;
	       			case 5:
	   	  			B.postorder(B.root);
	       				break;
	       			case 6:
	       				cout<<"Exiting....!";
	       				exit(0);
	 			default :
					cout<<"wrong choice...!\n";
					break;
			 }
      }
  return 0;
}	
  


