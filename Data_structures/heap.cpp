#include <iostream>
using namespace std;
class Node {
    public:
        int value;
        Node* left;
        Node* right;
	Node* parent;
        Node (int x) {
            value = x;
	    parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
};
class heap{ 
    private:
        Node* root = nullptr;
        int length = 0;
    public:
		bool is_empty(){
			return (root==nullptr);
		}

		~heap(){
			if (!is_empty()) {
				destroy(root);	
			}				
		}
		heap () {

		}
		
		heap (heap&& t ) {
			cout << " hellooooooo" << endl;
			this->root = t.root;
			t.root = nullptr;
			t.length = 0;
		}

		heap (const heap& t ) {
			cout << "called copy constructor" << endl; 
			cp(t.root);       	
		}
	
		heap& operator=(const heap& t){
			if (this == &t) {
				cout << "The same object." << endl;
				return* this;
			}
			if (!is_empty()){
				destroy(root);
			}
			root = nullptr;
			cp(t.root);
			return* this;       	
		}
	

		//operator for comparison 2 bts	
		bool operator==(const heap& t) {
			cout << "called == operator" << endl;
			if (this == &t) {
				cout << "The same object." << endl;
				return true;
			}
            		if (length != t.length) {
                		return false;
            		}
			return compare(root,t.root);
        	}
		
		bool operator!=(const heap& t) {
			return !(*this==t);
		}

		void add(int x) {
			add(root,x);
		}
		

		void print(){
			if (!is_empty()) {
				print(root);
			}
		}
		void print(bool desc) {
			if (!is_empty()) {
				print(root,desc);
			}
		}

		bool find(int value){
			if (!is_empty()) {
				return find(root,value);
			} else {
				return false;
			}
		}
		
		Node* find_ex(int value){
			if (!is_empty()) {
				return find_ex(root,value);
			}
			return nullptr;
		}

		Node* find_min(Node* tmp) {
			Node* t = tmp;
			while (tmp->left!=nullptr) {
				t = tmp->left;
				tmp->left = tmp->left->left;	
			}
			return t;
		}
		
		bool remove(int value) {
			bool f = 0;
			Node* tmp = find_ex(value);
			if (tmp==nullptr){
				return false;	
			}
			//case 1: to be deleted node has no leaves
			if (tmp->left == nullptr && tmp->right == nullptr){
			 	Node* t = tmp->parent;	
				if (t->value > tmp->value) {
					f = 1;
				} 
				delete tmp;
				if (f) {
					t->left = nullptr;
				} else {
					t->right = nullptr;
				}
				--length;
				return true;
			} 
			//case 2: to be deleted node has only one leaf
			else if ( tmp->left == nullptr && tmp->right != nullptr ) {	
				tmp->value = tmp->right->value;
				Node* res = tmp;
				delete tmp->right;
				res->right = nullptr;
				--length;
				return true;
			
			} else if ( tmp -> right == nullptr && tmp->left != nullptr) {
				Node* res = tmp;
				tmp->value = tmp->left->value;
				delete tmp->left;
				res->left = nullptr;
				--length;
				return true;
			}
			//case 3: to be deleted node has 2 leaves
			else { 
				if(tmp->right->left != nullptr) {
					Node* res = find_min(tmp->right);	
					tmp->value = res->value;
					if (res->right ==nullptr) {
						Node* t = res->parent;
						delete res;
						t->left = nullptr;
						--length;
						return true;
					}
					else {
						Node* t = res->parent;
						t->left = res->right;
						delete res;
						--length;
						return true;
					}
				} else {
					tmp->value = tmp->right->value;
					Node* t = tmp->right;
					if (tmp->right->right!= nullptr){
						tmp->right = tmp->right->right;
						delete t;
						t = nullptr;
						--length;
						return true;
					} else { 
						delete tmp->right;
						tmp->right = nullptr;
						--length;
						return true;
					}
				}  
			}
			return false;
		}  

	private:
		void destroy (Node* tmp){
			if (tmp != nullptr) {
				destroy(tmp->left);
				destroy(tmp->right);
				--length;
				delete tmp;
			}
		}

		void cp( Node* tmp) {
			if (tmp!= nullptr) {	
				add(tmp->value);
				cp(tmp->right);
				cp(tmp->left);
			}
		} 
		
 
		bool compare (Node* tmp1, Node* tmp2) {
			if ((tmp1!=nullptr&& tmp2==nullptr) || (tmp1==nullptr && tmp2!=nullptr) ) {
				cout << "First if" << endl;
				return false;
			}
			if (tmp1!= nullptr && tmp2!=nullptr){
				if(tmp1->value != tmp2->value) {
					cout << "Second if" << endl;
					cout << tmp1->value << " tmp1 and tmp2 " <<  tmp2->value  << endl;
					return false;
				} else { 
					bool r  = compare(tmp1->left,tmp2->left);
					bool r1 = compare(tmp1->right,tmp2->right);
					return r && r1;
				}
			} 
			return true;
			
		}		


		//Display binary search tree with ascending order
		void print(Node* tmp) {
			if (tmp != nullptr) { 
				print(tmp->left);
				cout << tmp->value << endl;
				print(tmp->right);
			} 
		}
		//Display binary search tree with descending order	
	
		void print(Node* tmp, bool desc) {
			if (tmp != nullptr) { 
				print(tmp->right,true);
				cout << tmp->value << endl;
				print(tmp->left,true);
			} 
		}

		void balance(Node* tmp) {
			while (tmp!=nullptr){
				cout << "while" << tmp->value << endl;
				if (tmp->right!= nullptr && tmp->value < tmp->right->value) {
					tmp->value = tmp->right->value;
					tmp->right->value = tmp->value;
					tmp = tmp->right;
					continue;
				} 
				if (tmp->left!=nullptr && tmp->value < tmp->left->value) {
					tmp->value = tmp->left->value;
					tmp->left->value = tmp->value;
					tmp = tmp->left;
					continue;
				}
				tmp = tmp->left;
				
			}	
		}
		
		void add(Node* tmp, int value) {
			//Comment special:
			//in this case was working one of the else if statements
			
			if (root == nullptr){
				length++;
				cout << "root is nullptr" << endl;
				root = new Node(value);
				return;
			}
                        if (tmp->right == nullptr) {
				if (tmp->left!=nullptr) {
					cout << "hello" << endl;
					length++;
					tmp->left=new Node(value);
					tmp->left->parent = tmp;
					balance(root);
                                	return;
				} else {
					cout << "hello" << endl;
					length++;
					tmp->right= new Node(value);
					tmp->right->parent = tmp;
					balance(root);
                                	return;
				}
			} else {
				cout << "hello" << endl;
				add(tmp->right, value);
			}
		}

		bool find(Node* tmp, int value) {
			if (tmp==nullptr) {
				return false;
			} 
			if (value==tmp->value) {
				return true;
			} else if ( value > tmp->value ) {
				return find(tmp->right, value);
			} else {
				return find(tmp->left, value);
			}
			return false; 
		}
		
		Node* find_ex(Node* tmp, int value) {
			if (tmp==nullptr) {
				return nullptr;
			} 
			if (value==tmp->value) {
				return tmp;
			} else if ( value > tmp->value ) {
				return find_ex(tmp->right, value);
			} else {
				return find_ex(tmp->left, value);
			}
			return nullptr; 
			 
		}
		
	
};

int main () {
	heap b;
	b.add(50);
	b.print();
	b.add(30);
	b.print();
	b.add(100);
	b.print();
	b.add(10);
	b.print();
//	heap b1;
//	b1.add(5);
//        b1.add(3);
//	cout << "------------our check-----------------------"	<<endl;
//	if (b!=b1) {
//		cout << "heap s are not equal" << endl;
//	} else {
//		cout << "heap s are equal" << endl;
//	}
//	cout << "----------------Print in asc order---------------" << endl;
//	b.print();
//	cout << "----------------Print in desc order-------------" << endl;
//	b.print(true);
//	b1 = b;
//	cout << "------------print copy-------------" << endl;
//	b1.print();
//	cout << "---------------calling copy constructor-----------------" << endl;
//	heap b2 = b1;
//	b2.print();
//	cout << "---------------Compare heap s-----------------" << endl;
//	if (b2==b1) {
//		cout << "heap s are equal" << endl;
//	} else {
//		cout << "heap s aren't equal" << endl;
//	}
//	cout << "-----------------Removing part---------------" << endl;
//	cout << "Removing 65 : case 1 has no leaves" << endl;
//	b.print();
//	b.remove(65);
//	cout << "After removing 65" << endl;
//	b.print();
//	cout << "Removing 10 : case 2 has one leaf" << endl;
//	b.print();
//	b.remove(10);
//	cout << "After removing 10" << endl;
//	b.print();
//	
//	cout << "Removing 30 : case 3 has 2 leaves and right leaf doesn't have left leaf" << endl;
//	b.print();
//	b.remove(30);
//	cout << "After removing 30" << endl;
//	b.print();
//        cout << "Removing 100 : case 3 has 2 leaves and right leaf has left leaf" << endl;	
//        b.print();
//        b.remove(100);
//        cout << "After removing 100" << endl;
//        b.print();
//	cout << "Removing 200 : case 3 has 2 leaves and right leaf doesn't have leaves" << endl;
//	b.print();
//	b.remove(200);
//	cout << "After removing 200" << endl;
//	b.print();
// 
//	if (b==b) {
//		cout << " true" << endl;
//	}
//	b = b;
	//cout << "move constructor" << endl;
	//b.print();	
	//heap tree = move(b);
	//cout << "after calling move constructor" << endl;
	//b.print();	
	return 0;
}
