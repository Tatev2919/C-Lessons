#include <iostream>
using namespace std;

class Specialist {
	public:
		string name;
		string surname;
		int age;
		int languages;
		int iq;
	Specialist(){};        

	Specialist (string name, string surname,int age, int languages,int iq) {
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->languages = languages;
		this->iq = iq;
	}
   
	//operator bool(){
	//	if (name !=nullptr || surname !=nullptr || age!=0) {
	//		return true;
	//	} else {
	//		return false;
	//	}
	//}
	friend ostream& operator<<(ostream& pr, Specialist spec){
                cout<<"---operator<< call for Specialist object---"<<endl;
                pr<<spec.name<<endl;
                pr<<spec.surname<<endl;
                pr<<spec.age<<endl;
                pr<<spec.languages<<endl;
                pr<<spec.iq<<endl;
                return pr;
        }	

	void print() {
		cout << name << " : name " << endl;
		cout << surname << " : surname" << endl;
		cout << age << " : age " << endl;
		cout << languages << " : languages " << endl;
		cout << iq << " : iq " << endl; 
	}
};

template <class T> 
class Comparator {
        public:
		virtual int comp(T a, T b) {
			return -77;
		};
};

class SortByAge: public Comparator<Specialist> {
 	public:
		int comp(Specialist a, Specialist b) {
			if(a.age > b.age) {
				return 1;
			} else if (a.age == b.age) {
				return 0;
			} else {
				return -1;
			}
		}
};

template <class K,class V>
class Node {
    public:
	K key;
        V value;
        Node<K,V>* left;
        Node<K,V>* right;
	Node<K,V>* parent;
        Node (K key,V value) {
	    this->key = key;
            this->value = value;
	    parent = nullptr;
            left = nullptr;
            right = nullptr;
        }
};

template <class K,class V>
class Map{ 
    private:
        Node<K,V>* root = nullptr;
        int length = 0;
        Comparator<K>* p;

    public:
		bool is_empty(){
			return (root==nullptr);
		}

		~Map(){
			if (!is_empty()) {
				destroy(root);	
			}				
		}

		Map (Comparator<K>* p) {
			this->p = p;
		}
		
		Map (const Map& t ) {
			cout << "called copy constructor" << endl; 
                        this->p = t->p; 
			cp(t.root);       	
		}
	
		Map& operator=(const Map& t){
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
		bool operator==(const Map& t) {
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
		
		bool operator!=(const Map& t) {
			return !(*this==t);
		}

		void add(V x,K k) {
			add(root,x,k);
		}
		

		void print(){
			if (!is_empty()) {
				print(root);
			}
		}

		bool find(K key){
			if (!is_empty()) {
				return find(root,key);
			} else {
				return false;
			}
		}
		
		Node<K,V>* find_ex(K key){
			if (!is_empty()) {
				return find_ex(root,key);
			}
			return nullptr;
		}

		Node<K,V>* find_min( Node<K,V>* tmp) {
			auto t = tmp;
			while (tmp->left!=nullptr) {
				t = tmp->left;
				tmp->left = tmp->left->left;	
			}
			return t;
		}
		
		bool remove(K key) {
			bool f = 0;
			auto tmp = find_ex(key);
			if (tmp==nullptr){
				return false;	
			}
			//case 1: to be deleted node has no leaves
			if (tmp->left == nullptr && tmp->right == nullptr){
			 	auto t = tmp->parent;	
				if (p->comp(t->key,tmp->key)==1) {
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
				tmp->key = tmp->right->key;
				tmp->value = tmp->right->value;
				auto res = tmp;
				delete tmp->right;
				res->right = nullptr;
				--length;
				return true;
			
			} else if ( tmp -> right == nullptr && tmp->left != nullptr) {
				auto res = tmp;
				tmp->key = tmp->left->key;
				tmp->value = tmp->left->value;
				delete tmp->left;
				res->left = nullptr;
				--length;
				return true;
			}
			//case 3: to be deleted node has 2 leaves
			else { 
				if(tmp->right->left != nullptr) {
					auto res = find_min(tmp->right);	
					tmp->key = res->key;
					tmp->value = res->value;
					if (res->right ==nullptr) {
						auto t = res->parent;
						delete res;
						t->left = nullptr;
						--length;
						return true;
					}
					else {
						auto t = res->parent;
						t->left = res->right;
						delete res;
						--length;
						return true;
					}
				} else {
					tmp->key = tmp->right->key;
					tmp->value = tmp->right->value;
					auto t = tmp->right;
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
		void destroy (Node<K,V>* tmp){
			if (tmp != nullptr) {
				destroy(tmp->left);
				destroy(tmp->right);
				--length;
				delete tmp;
			}
		}

		void cp( Node<K,V>* tmp) {
			if (tmp!= nullptr) {	
				add(tmp->value,tmp->key);
				cp(tmp->right);
				cp(tmp->left);
			}
		} 
		
 
		bool compare (Node<K,V>* tmp1, Node<K,V>* tmp2) {
			if ((tmp1!=nullptr&& tmp2==nullptr) || (tmp1==nullptr && tmp2!=nullptr) ) {
				//cout << "First if" << endl;
				return false;
			}
			if (tmp1!= nullptr && tmp2!=nullptr){
				if((p->comp(tmp1->key,tmp2->key)==-1) || (tmp1->value < tmp2->value)) {
				//	cout << "Second if" << endl;
				//	cout << tmp1->key << " tmp1->key and tmp2->key " <<  tmp2->key  << endl;
				//	cout << tmp1->value << " tmp1->value and tmp2->value " <<  tmp2->value << endl;
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
		void print(Node<K,V>* tmp) {
			if (tmp != nullptr) { 
				print(tmp->left);
				cout << "key: " << tmp->key << "value: " <<  tmp->value << endl;
				print(tmp->right);
			} 
		}

		void add(Node<K,V>* tmp, V value,K key) {
			//Comment special:
			//in this case was working one of the else if statements
			
			if (root == nullptr){
				length++;
				//cout << "root is nullptr" << endl;
				root = new Node<K,V>(key,value);
				return;
			}
			auto t = find_ex(key); 
			if (t != nullptr) {
				t->value = value;
				return;
			}
			if ( (p->comp(key,tmp->key))==1 ) {
				//Comment special:
				//in this case tmp->value is not in managed address
				if (tmp->right == nullptr) {	
					//Comment special:
					// then was working this block
					tmp->right=new Node<K,V>(key,value);
					tmp->right->parent = tmp;
					length++;
				} else {
					add(tmp->right, value, key);
				}
			} else if ( p->comp(key,tmp->key)==-1) {
				if (tmp->left == nullptr) {
					//cout << find_ex(key) << " key " << key << endl;
					tmp->left=new Node<K,V>(key,value);
					tmp->left->parent = tmp;
					length++;
				} else {
					add(tmp->left, value, key);
				}
			}
		}
		
		bool find(Node<K,V>* tmp, K key) {
			if (tmp==nullptr) {
				return false;
			} 
			if (key==tmp->key) {
				return true;
			} else if ((p->comp(key,tmp->key) == 1) ) {
				return find(tmp->right, key);
			} else {
				return find(tmp->left, key);
			}
			return false; 
		}
		
		
		Node<K,V>* find_ex(Node<K,V>* tmp, K key) {
			if (tmp==nullptr) {
				return nullptr;
			}
			if ( p->comp(key,tmp->key)==0) {
				cout << "hello"<<endl;
				return tmp;
			} else if ( p->comp(key,tmp->key)==1 ) {
				return find_ex(tmp->right, key);
			} else {
				return find_ex(tmp->left, key);
			}
			return nullptr; 
			 
		}
		
	
};

int main () {
        SortByAge s;

	Map<Specialist,int> b(&s);
	b.add(1,Specialist("John","Walker",15,2,90));
	b.add(2,Specialist("Jane","Smith",18,2,95));
	b.add(3,Specialist("Kareem","S",35,3,120));
	b.add(4,Specialist("Nahlu","Mohammad",12,1,75));
	b.print();
	Map<Specialist,int> b1(&s);
	b1.add(1,Specialist("John","Walker",15,2,90));
	b1.add(2,Specialist("Jane","Smith",18,2,95));
	b1.add(3,Specialist("Kareem","S",35,3,120));
	b1.add(4,Specialist("Nahlu","Mohammad",12,1,75));
	b1.print();
	//Map<int,int> b1;
	//b1.add(5,1);
        //b1.add(3,2);
	//cout << "------------our check-----------------------"	<<endl;
	//if (b!=b1) {
	//	cout << "Map s are not equal" << endl;
	//} else {
	//	cout << "Map s are equal" << endl;
	//}
	//cout << "----------------Print in asc order---------------" << endl;
	//b.print();
	//cout << "----------------Print in desc order-------------" << endl;
	//b.print(true);
        Map<Specialist,int> b2(&s);
	b2 = b;
	cout << "------------print copy-------------" << endl;
	b2.print();
	cout << "---------------calling copy constructor-----------------" << endl;
	//Map<int,int> b2 = b1;
	//b2.print();
	//cout << "---------------Compare Map s-----------------" << endl;
	if (b==b1) {
		cout << "Map s are equal" << endl;
	} else {
		cout << "Map s aren't equal" << endl;
	}
	cout << "-----------------Removing part---------------" << endl;
	cout << "Removing key 4 : case 1 has no leaves" << endl;
	b.print();
	b.remove(Specialist("John","Walker",15,2,90));
//	cout << "After removing key 4 value 65 " << endl;
//	b.print();
//	cout << "-----------------Removing part---------------" << endl;
//	cout << "Removing key 0 : case 2 has one leaf" << endl;
//	b.print();
//	b.remove(0);
//	cout << "After removing key 0 value 42 " << endl;
//	b.print();
//	cout << "-----------------Removing part---------------" << endl;
//	cout << "Removing key 6 : case 3 has 2 leaves" << endl;
//	b.print();
//	b.remove(6);
	//cout << "After removing key 6 value 100 " << endl;
	//b.print();
 
	//if (b==b) {
	//	cout << " true" << endl;
	//}
	//b = b;

	
	return 0;
}
