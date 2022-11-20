//Binary Search Tree
#include <iostream>
using namespace std;
struct node
{
        int data;
        node* left,*right;
};
class BST
{
      node* ROOT;
      public:
             BST()
             {    ROOT= NULL;   }
             node* insertBST(node* r,int x)
             {
             	node* t=new node;
                t->data=x; t->left=t->right=NULL;
                if (r==NULL)
                	{   r = t;  return r;   }
                if (x < r->data)
                  	r->left = insertBST(r->left, x);
                else
                  	r->right = insertBST(r->right,x);
                return r;
            }
			void inorder(node* temp)                    
 			{
 				if (temp!=NULL)
 				{
 					inorder(temp->left);
 					cout<<temp->data<<" ";
 					inorder(temp->right);
 				}
 			}
 			node* deleteBST(node* r, int x)
 			{
 				if (!r)
 				{	cout<<"Data not found"; return r;	}
 				if (x < r->data)
 				{
 					r->left = deleteBST(r->left,x);
 					return r;
 				}
 				else if (x > r->data)
 					 {
 					 	r->right = deleteBST(r->right, x);
 					 	return r;
 					 }
 					else if (!r->left)	  // node found; no left subtree
 						 {
 						 	node* tmp=r->right;
							delete r; return tmp; 
						 }
 						else if (!r->right)		// no right subtree
 							 {
 							 	node* tmp=r->left;
 							 	delete r; return tmp;
 							 }
 							else
 							{
 								node* deleteNode = r;
 								node* largest = findLargest(r->left);
 								deleteNode->data = largest->data;
 								r->left = deleteBST(r->left, largest->data);
								return r;
 							}								 		
 			}
 			node* findLargest(node* t)
 			{
 				if (!t->right)
 					return t;
 				t = findLargest(t->right);
 			}
 			bool searchBST(node* r, int key)
 			{
 				if(!r)
				 	return false;
 				node* temp=r;
 				if (r->data==key)
 					return true;
 				else if (r->data > key)
 						searchBST(r->left, key);
 					else
 						searchBST(r->right, key);
 			}
            node *findSmallest(node *t) {
                if (!t->left) return t;
                t = findSmallest(t->left);
            }
            void preOrder(node *t) {
                if (t) {
                    cout<<t->data<<" ";
                    preOrder(t->left);
                    preOrder(t->right);
                }
            }
            void postOrder(node *t) {
                if (t) {
                    postOrder(t->left);
                    postOrder(t->right);
                    cout<<t->data<<" ";
                }
            }
};

int main()
{
    BST tree; int choice, key,target;
	node* Root=NULL;
    do
    {
    	cout<<endl<<"1. Insert data\t2. Display inorder\t3. Delete data\t4. Find Largest\t5. SearchBST\t6. Find Smallest\t7. Pre Order\t8. Post Order"<<endl;
    	cout<<"Enter choice : "; cin>>choice;
    	switch(choice)
    	{
    		case 1: cout<<"Enter key to insert : ";
    				cin>>key; Root = tree.insertBST(Root, key); break;
    		case 2: tree.inorder(Root); break;
    		case 3: cout<<"Delete what ? "; 
					cin>>target; Root=tree.deleteBST(Root,target); break;
			case 4: cout<<"Largest = "<<tree.findLargest(Root)->data; break;
			case 5: cout<<"Search What : ";	cin>>key; 
					if(tree.searchBST(Root,key))	cout<<"Key found";
					else	cout<<"Key not found";
			case 6: cout<<"Smallest = "<<tree.findSmallest(Root)->data; break;
            case 7: cout<<"Preorder: ";tree.preOrder(Root);cout<<endl;break;
            case 8: cout<<"Postorder: ";tree.postOrder(Root);cout<<endl;break;
    	}
    } while (choice <= 9);
    
}