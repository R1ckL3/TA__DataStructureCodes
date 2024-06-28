//Hossein Shirani - 4011406134
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
class AVL{
	private:
		Node* node;
	public:
		int height(Node*);
		int difference(Node*);
		Node* newNode(int);
		Node* rightRotate(Node*);
		Node* leftRotate(Node *);
		Node* doubleLeftRotate(Node*);
		Node* doubleRightRotate(Node*);
		Node* balance(Node*);
		Node* insert(Node* , int);
		Node* Delete(Node* , int);
		Node* min(Node*);
		void preorder(Node*);
		
};
int AVL::height(Node *node){
	if(node == nullptr){
		return -1;
	}
	else{
		int lefth = height(node -> left);
		int righth = height(node -> right);	
		if(lefth > righth){ 
            return (lefth + 1);
        }
		else{
            return (righth + 1);		
        }
		}
}
int AVL::difference(Node* node){
	if(node == nullptr){
        return 0;
    }    
	return height(node -> left) - height(node->right);
}
Node* AVL::newNode(int value){
    struct  Node *node;
	node = new Node;
    node->data = value;
    node->left = node->right = nullptr;
    return node;
}
Node* AVL::rightRotate(Node *f){
    Node *b,*t;
	b = f->left;
    t = b->right;
    b->right = f;
    f->left = t;
    return b;
}
Node* AVL::leftRotate(Node *b){
    Node *f,*t;
	f = b->right;
    t = f->left;
    f->left = b;
    b->right = t;
    return f;
}
Node* AVL::doubleLeftRotate(Node* b)
{
    b->right = rightRotate(b->right);
    return leftRotate(b);
}
Node* AVL::doubleRightRotate(Node* f)
{
	f->left =  leftRotate(f->left);
    return rightRotate(f);
}
Node* AVL::balance(Node* node)
{
	  
    int b = difference(node);
 
    if (b > 1 && difference(node->left) >= 0) return rightRotate(node);
 
    if (b < -1 && difference(node->right) <= 0) return leftRotate(node);
    
    if (b > 1 && difference(node->left) < 0) return doubleRightRotate(node);
        
    if (b < -1 && difference(node->right) > 0) return doubleLeftRotate(node);
    
    return node;
}
Node* AVL::insert(Node* node, int value)
{
    if (node == nullptr)
    {
    	Node* p=newNode(value);
        return p;
	}
    if (value < node->data) node->left = insert(node->left, value);

    else if (value > node->data) node->right = insert(node->right, value);
    
	node=balance(node);
    return node;
}
Node* AVL::min(Node* node)
{
    Node* p = node;
 
    while (p->left != nullptr)
        p= p->left;
 
    return p;
}
Node* AVL::Delete(Node* node, int value)
{
    Node* p;
	if (node == nullptr) return node;
	
    if ( value < node->data ) node->left = Delete(node->left, value);
   
    else if( value > node->data ) node->right = Delete(node->right, value);

    else{
    	if(node->left == nullptr && node->right == nullptr){
            free(node);
            return nullptr;
        }
        else if (node->left == nullptr){
            p = node->right;
            free(node);
            return p;
        }
        else if (node->right == nullptr){
            p = node->left;
            free(node);
            return p;
        }
        	p = min(node->right);
        	node->data = p->data;
        	node->right = Delete(node->right, p->data);
    }
    node=balance(node);
    return node;
}
void AVL::preorder(Node *r)
{
    if(r!=nullptr)
    {
        cout<< r->data <<" ";
        preorder(r->left);
        preorder(r->right);
    }
}

int main(){
    Node *r = nullptr;
    AVL avl;
    cout<<"**AVL Tree**\n1-height\n2-insert\n3-delete\n4-exit\n";
    int choice , value;
    while(true){
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice==1) cout<<avl.height(r);
        else if(choice==2){
            cout<<"Enter value: ";
            cin>>value;
            r=avl.insert(r,value);
            avl.preorder(r);
            
        }
        else if(choice==3){
            cout << "Enter value: ";
            cin >> value;
            r = avl.Delete(r, value);
            avl.preorder(r); 
        }
        else if(choice == 4) break;
        else cout<<"The value entered is not correct!";
        cout<<"\n";    
    }
        return 0;
}