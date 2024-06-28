//Hossein Shirani - 4011406134
#include <iostream>
#define MAX 100
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
class queue{
	private:
		Node* q[MAX];
		int front,rear;
	public:
		queue();
		bool isEmpty();
		bool isFull();
		Node* getFront();
		void enqueue(Node*);
		Node* dequeue();
};
queue::queue(){
	front=0,rear=0;
}
bool queue::isEmpty(){
	return rear == front;
}
bool queue::isFull(){
	return rear == MAX;
}
Node* queue::getFront(){
	return q[front];
}
void queue::enqueue(Node* node){
	if (isFull()){ 
		cout<<"Queue is full!";
	}
	else {
		q[rear] = node;
		rear++;
	}
}
Node* queue::dequeue(){
	if (isEmpty()){
		cout<<"Queue is empty!";
		return nullptr;
	}
	else{
		front++;
		return q[front-1];
	}
}
class stack{
	private:
		Node* s[MAX];
		int top;
	public:
		stack();
		bool isEmpty();
		bool isFull();
		Node* getTop();
		void push(Node*);
		void pop();
};
stack::stack(){
	top=-1;
}
bool stack::isEmpty(){
	return top<=-1;
}
bool stack::isFull(){
	return top==MAX;
}
Node* stack::getTop(){
	return s[top];
}
void stack::push(Node* node){
	if (isFull()) cout << "Stack is full";
	else{
		top++;
		s[top]=node;
	}
}
void stack::pop()
{
	if (isEmpty()) cout<<"Stack is empty!";
	else top--;	
}
class b_tree{
	Node *root = nullptr;
	int count = 0;
	public:
		Node *insert(int);
		Node *Insert(Node *,int);
		int size(Node *);
		int height(Node *);
		void BFS(Node *);
		void DFS(Node *);
		void inOrder(Node *);
		void preOrder(Node *);
		void postOrder(Node *);
		
};
Node * b_tree::insert(int value){
	Node *node = new(Node);
	node -> data = value;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}
Node* b_tree::Insert(Node *root,int value)
{
    Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = value;
    if(root == nullptr){
       node -> left = node -> right = nullptr;
       root = node;
       count++;
    }
    else{
       if(count % 2 != 0)	root -> left = Insert(root -> left, value);
       else	root -> right = Insert(root -> right, value);
    }
    return root;
}
int b_tree::size(Node *root){
	if ( root->left== nullptr){
		return ( root->right== nullptr ) ? 1 : 1 + size(root->right);
 	} 
	else{
		return ( root -> right == nullptr ) ?
		1 + size(root -> left) :
 		1 + size(root -> left) + size(root->right);
}
}
int b_tree::height(Node *root){
	if(root == nullptr){
		return -1;
	}
	else{
		int lefth=height(root -> left);
		int righth=height(root -> right);	
		if(lefth>righth){
			return (lefth+1);
		}
		else{
			return (righth+1);		
		}
	}
}

void b_tree::BFS(Node *root){
	if (root == nullptr) cout<<" ";
    queue q;
    q.enqueue(root);
    Node *n;
    while(!q.isEmpty()){
        n = q.getFront();
        cout << n -> data << " ";
        q.dequeue();
        if (n -> left != nullptr){
			q.enqueue(n -> left);
		}
        if (n -> right != nullptr){
			q.enqueue(n -> right);
		}
    }
}
void b_tree::DFS(Node *root){
	if (root==nullptr){ 
		cout << " ";
	}
	stack s;
	s.push(root);
	Node *p;
	while(!s.isEmpty()){
		p=s.getTop();
		cout<<p->data<<" ";
		s.pop();
		if (p->right !=nullptr){
			s.push(p->right);
		}
        if (p->left !=nullptr){
			s.push(p->left);
		}
	}
}
void b_tree::inOrder(Node *root){
    if(root!=nullptr){
        inOrder(root -> left);
        cout << root -> data << " ";
        inOrder(root -> right);
    }
}
void b_tree::preOrder(Node *root){
    if(root != nullptr){
    	cout << root -> data << " ";
        preOrder(root -> left);
        preOrder(root -> right);
    }
}
void b_tree::postOrder(Node *root){
    if(root != nullptr){
        postOrder(root -> left);
        postOrder(root -> right);
		cout << root -> data << " ";
    }
}
int main(){

}	