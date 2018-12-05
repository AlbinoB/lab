//circular linklist
#include<iostream>
using namespace std;

	class node
	{
	    public:int data;
	    node *left;
	    node *right;
	};

    node* search1(node *,int);
    node* insert1(node *,node *);
	void infixdisplay(node *);
	void prefixdisplay(node *);
	void postfixdisplay(node *);
    node* delete1(node *,node *);

    node* parent;

int main()
{
    node *root=NULL;
	int n,c;
	do
	{       cout<<"\n*********************************\n";

		cout<<"\n\n\n enter your choice \n 1:insert a number. \n 2.display infix  \n 3.display prefix  \n 4.display postfix  \n 5.search for a number. \n 6.delete a number.\n  0.exit.";
		cin>>c;
		switch(c)
		{
			case 1:{
			    node *a;
                a=new(node);
                cout<<"\n enter the value:";
                cin>>a->data;
                a->left=NULL;
                a->right=NULL;
                if(root==NULL)
                {
                    root=a;//if its the first node make root point to a
                }else
                {
                    insert1(root,a);//else pass the root and the new node pointer
                }

				break;
				}
            case 2:{
                if(root==NULL)
                {
                    cout<<"\n no number inserted!!!!";
                }
                else
                {
				infixdisplay(root);
                break;
				}
            }
            case 3:{
                if(root==NULL)
                {
                    cout<<"\n no number inserted!!!!";
                }
                else
                {
				prefixdisplay(root);
                break;
				}
            }
            case 4:{
                if(root==NULL)
                {
                    cout<<"\n no number inserted!!!!";
                }
                else
                {
				postfixdisplay(root);
                break;
				}
            }
			case 5:{
			    if(root==NULL)
                {
                    cout<<"\n no number inserted!!!!";
                }
                else
                {
                    int val;
                    node *pointer_to_the_node;
                    cout<<"enter the number to be searched:";
                    cin>>val;
                    pointer_to_the_node=search1(root,val);
                    if(pointer_to_the_node)
                    {
                        cout<<"\n returned:"<<pointer_to_the_node->data<<"::its parent is :"<<parent->data;
                    }
                    else
                    {
                        cout<<"\n"<<val<<" is not present!!!";
                    }

                }
				break;
				}
            case 6:{
                    int val;
                    node *pointer_to_the_node;
                    cout<<"enter the number to be deleted:";
                    cin>>val;
                    pointer_to_the_node=search1(root,val);
                    if(pointer_to_the_node)
                    {
                        delete1(root,pointer_to_the_node);
                        if(pointer_to_the_node)
                        cout<<"\n"<<pointer_to_the_node->data<<" is deleted sucessfully!";
                    }
                    else
                    {
                        cout<<"\n"<<val<<" is not present!!!";
                    }
                }
		}
	    cout<<"\n___________________________________________________\n";
	}while(c!=0 && c<7 && c>0);
	return 0;
}

    void infixdisplay(node *root){
            if( root->right==NULL && root->left==NULL)
            {
                cout<<" "<<root->data;
            }else
            {
                if( root->left!=NULL)
                {
                    infixdisplay(root->left);
                }
                cout<<" "<<root->data;
                if( root->right!=NULL)
                {
                    infixdisplay(root->right);
                }
            }

    }

 void prefixdisplay(node *root){
            if( root->right==NULL && root->left==NULL)
            {
                cout<<" "<<root->data;
            }else
            {
                cout<<" "<<root->data;
                if( root->left!=NULL)
                {
                    prefixdisplay(root->left);
                }

                if( root->right!=NULL)
                {
                    prefixdisplay(root->right);
                }
            }

    }


 void postfixdisplay(node *root){
            if( root->right==NULL && root->left==NULL)
            {
                cout<<" "<<root->data;
            }else
            {
                if( root->left!=NULL)
                {
                    postfixdisplay(root->left);
                }

                if( root->right!=NULL)
                {
                    postfixdisplay(root->right);
                }
                cout<<" "<<root->data;
            }

    }

	node* insert1(node *root,node *a)
	{
            if(a->data<root->data && root->left==NULL)//if its less than the root value and if the roots left is null .
			{
                root->left=a;//make the roots left point to the new node
			}
			else
            {
                if(a->data>root->data && root->right==NULL)//if its greater than the root value and if the roots right is null .
                {
                    root->right=a;//make the roots right point to the new node
                }
                else
                {
                    if(a->data<root->data)
                    {
                        root=root->left;
                        insert1(root,a);
                    }
                    else
                    {
                        root=root->right;
                        insert1(root,a);
                    }
                }

            }
            return root;
	}

    node* search1(node *root,int val){
        if(root!=NULL)
        {
                if(root->data==val)
            {
                cout<<"\n value found:";
            }
            else
            {
                if(val<root->data)
                {
                    parent=root;
                    root=search1(root->left,val);
                }
                else
                {
                    if(val>root->data)
                    {
                        parent=root;
                        root=search1(root->right,val);
                    }
                }

            }
        }
        return root;

    }


node* delete1(node *root,node *pointer_to_the_node){
    if(parent==root)
    {
        root=NULL;
    }
    else
    {
        if(pointer_to_the_node->left==NULL&&pointer_to_the_node->right==NULL)
        {
            if(pointer_to_the_node->data<parent->data)
            {
                parent->left=NULL;
            }
            else
            {
                parent->right=NULL;
                     pointer_to_the_node->right->left=pointer_to_the_node->left;
            }
        }
        else
        {
            if(pointer_to_the_node->left!=NULL||pointer_to_the_node->right!=NULL)
            {
                 if(pointer_to_the_node->data>parent->data)
                {
                    parent->right=NULL;
                }
                else
                {
                    parent->left=NULL;
                }
            }
            else
            {
                 if(pointer_to_the_node->left!=NULL&&pointer_to_the_node->right!=NULL)
                 {
                     pointer_to_the_node->right->left=pointer_to_the_node->left;
                     parent->right=pointer_to_the_node->right;
                 }
            }
        }
    }
}
