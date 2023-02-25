#include <iostream>

using namespace std;

template <typename T>
class unique{
	T *ptr;
	public:
		unique(): ptr(nullptr){			
		}
		
		explicit unique(T *t):ptr(t){
		}
		
		unique(const unique &obj) = delete;
		unique& operator=(const unique &obj) = delete;
		
		unique(unique &&obj){
			ptr = obj.release();
		}
		unique& operator=(unique &&obj){
			ptr = obj.release();
			return ptr;
		}
		
		T& operator *(){
			return *ptr;	
		}
		
		T operator->(){
			return ptr;
		}
		
		explicit operator bool() const{
			return ptr;
		}
		
		~unique(){
			delete ptr;	
		}
		
		T* release(){
			T *temp= ptr;
			ptr= nullptr;
			return temp;
		}
		
		void reset(T *t){
			if(t!=ptr)
				release();
			ptr = t;
		}
	
};

class Integer{
	public:
		int val;
		Integer(int n):val(n){
		}
		int get(){
			return val;
		}
};

int main(){
	
	unique<Integer> ob1(new Integer(3));

	cout<< """"<<endl;
	
	
	if(!ob1){
		cout<<"unique pointer empty"<<endl;
	}
	
	return 1;
}
