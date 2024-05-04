#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int value;
	node* left;
	node* right;
	node(int data)
	{
		value=data;
		left=NULL;
		right=NULL;
	}
}*root;
class BST
{
	public:
		BST()
		{
			root=NULL;
		}

		node* insert(node* root, int data)
		{
			if(root==NULL)
			{
				node* new_node=new node(data);
				return new_node;
			}
			else if(data<root->value)
			{
				root->left=insert(root->left,data);
			}
			else
			{
				root->right=insert(root->right,data);
			}
			return root;
		}
		void display(node* root,int indent=0)
		{
			if(root==NULL)
			{
				return;
			}
			else
			{
				display(root->right,indent+4);
				for(int i=0;i<indent;i++)
				{
					cout<<" ";
				}
				cout<<root->value<<endl;
				display(root->left,indent+4);
			}
		}
		void min(node* root)
		{
			if(root==NULL)
			{
				cout<<"\n\tTree is empty!";
			}
			else
			{
				while(root->left!=NULL)
				{
					root=root->left;
				}
				cout<<"\n\tMinimum value is:"<<root->value;
			}
		}

		int longest(node* root)
		{
			if(root==NULL)
			{
				return 0;
			}
			int leftp=longest(root->left);
			int rightp=longest(root->right);
			int m=max(leftp,rightp)+1;
			return m;
		}
		int search(node* root,int data)
		{
			if(root==NULL)
			{
				cout<<"\n\tTree is empty!";
			}
			else
			{
				if(data==root->value)
				{
					cout<<"\n\t"<<data<<" is found";
				}
				else if(data<root->value)
				{
					search(root->left,data);
				}
				else
				{
					search(root->right,data);
				}
			}
		}
		node* swap(node* root)
		{
			if(root==NULL)
			{
				return NULL;
			}
			node* t=root->left;
			root->left=root->right;
			root->right=t;
			swap(root->left);
			swap(root->right);
			return root;
		}
};
int main()
{
	int ch,data,a;
	char c;
	BST t;
	system("cls");
	do
	{
		cout<<"\n\t1.Insert\n\t2.Display\n\t3.Minimum Value\n\t4.Longest Path\n\t5.Search\n\t6.Swap pointers\n\t7.Exit";
		cout<<"\n\tEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n\tInsert data:";
				cin>>data;
				root=t.insert(root,data);
				break;
			case 2:
				t.display(root);
				break;
			case 3:
				t.min(root);
				break;
			case 4:
				a=t.longest(root);
				cout<<"\n\tNumber of nodes in the longest path are: "<<a;
				break;
			case 5:
				cout<<"\n\tEnter the element you want to search:";
				cin>>data;
				t.search(root,data);
				break;
			case 6:
				root=t.swap(root);
				cout<<"\n\tPointers are swapped!";
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<<"\n\tInvalic choice!";
		}
		cout<<"\n\tDo you want to continue?:";
		cin>>c;
	}while(c=='y');
	return 0;
}
