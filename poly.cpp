//Hossein Shirani - 4011406134

#include <iostream>
#include <math.h>
using namespace std;
class node{
	public:
		int zarib;
		int daraje;
		node* next;
		node(int d, int z){
			zarib = z;
			daraje = d;
			next = nullptr;
		}
};
class list{
	private:
		node* list_end = nullptr;
		node* list_head = nullptr;
		int list_size = 0;
	public:
		node* begin();
		node* end();
		bool isempty();
		int size();
		void insert(int pos, int val);
		int del(int deg);
		void print();
		int calculate(int x);
};

node* list::begin(){
	return list_head;
}
node* list::end(){
	return list_end;
}
bool list::isempty(){
	if (list_head == nullptr) {
		return 1;
	}
	else{
		return 0;
	}
}
int list::size(){
	return list_size;
}

void list::insert(int deg, int val){
	node* newnode = new node(deg,val);
	node* ptr = begin();
	if (ptr == nullptr){
		list_head = newnode;
		list_end = newnode;
		list_size++;
	}
	else if (deg <= end()->daraje) {
		ptr = end();
		ptr->next = newnode;
		list_end = list_end->next;
		list_size++;
	}
	else {
		node* pre = nullptr;
		while (ptr->daraje >= deg) {
			pre = ptr;
			ptr = ptr->next;
		}
		newnode -> next = ptr;
		pre -> next = newnode;
		list_size++;
	}
}

int list::del(int deg) {
	node* current = begin();
	node* pre = nullptr;
	if (deg >= 0) {
		while(current -> daraje != deg) {
			pre = current;
			current = current -> next;
		}
		pre -> next = current -> next;
		int val = current -> zarib;
		list_size--;
		delete current;
		return val;
	}
	else {
		return 0;
	}
}

void list::print(){
	node* ptr = begin();
	int c = 0;
	while (ptr != nullptr) {
		if(c > 0){
			cout << '+';
		}
		cout << '(' << ptr -> zarib << "X^" << ptr->daraje << ')';
		c++;
		ptr = ptr->next;
	}
	cout << endl;
}
int list::calculate(int x){
	int answer = 0;
	node* ptr = begin();
	while (ptr != nullptr){
		answer += (ptr->zarib * pow(x, ptr -> daraje));
		ptr = ptr -> next;
	}
	return answer;
}
int main() {
	list l;
	l.insert(3, 2);
	l.insert(5, 1);
	l.insert(0, 4);
	l.print();
	cout << l.calculate(2);
}