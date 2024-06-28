//Hossein Shirani - 4011406134
#include <iostream>
using namespace std;
class stack {
	private:
		int cap;
		int index;
		char* a;
	public:
		stack(int n){
			cap = n;
			a = new char[n];
			index = -1;
		}
		bool isfull(){
			if (index == cap - 1){
				return 1;
			}
			else {
				return 0;
			}
		}
		bool isempty(){
			if (index == -1){
				return 1;
			}
			else{
				return 0;
			}
		}
		void push(int inp){
			if (!isfull()){
				a[++index] = inp;
			}
		}
		char pop(){
			if (isempty()){
				return -1;
			}
			else {
				return a[index--];
			}
		}
	};
	//check if the char'c' is operator
	bool isop(char c) {
		char op[5] = { '+', '*', '-', '^', '/'};
		for (int i = 0; i < 5; i++) {
			if (op[i] == c) {
				return 1;
			}
		}
		return 0;
}
int main(){
	char* a;
	char op[5] = { '+' ,'*','-','^','/' };
	int n;
	cin >> n;
	// cpaacity of the stack
	stack s(n);
	a = new char[n];
	cin >> a;
	for (int i = 0; i < n; i++){
		if (isop(a[i])){
			s.push(a[i]);
		}
		else if (a[i] == '('){
			continue;
		}
		else if (a[i] == ')'){
			cout << s.pop();
		}
		else{
			cout << a[i];
		}
	}
}