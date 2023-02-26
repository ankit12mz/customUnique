#include <iostream>
#include "header.h"
using namespace std;

template <typename T>
class unique{
	T *ptr;
	public:
		unique():ptr(nullptr) {}
		explicit unique(T *p): ptr(p) {}
		~unique(){
			delete ptr;
			ptr = nullptr;
		}
		unique(const unique &obj) = delete;
		unique& operator=(const unique &obj)=delete;
		
		unique(unique &&obj):ptr(obj.release()){
//			ptr = obj.release();
		}
	
		unique& operator = (unique &&obj){
				ptr = obj.release();
				return *this;
		}
	
		T* get(){
			return ptr;	
		}
		
		T* release(){
			T *temp = ptr;
			ptr = nullptr;
			return temp;
		}
	
	
		void reset(T *p=nullptr){
			if(ptr !=p)
				delete ptr;
			ptr = p;
		}
		
		T& operator*(){
			return *ptr;
		}
		T* operator->(){
			return ptr;
		}
		explicit operator bool(){
			return ptr!=nullptr;
		}

	
	
};

unique<int> Print(unique<int> obj1){
//	*obj1 += *obj1;
	*obj1 += *obj1;
	cout<<*obj1<<endl;
//	
	unique<int> temp = move(obj1);
	return temp;
//	return nullptr;
}

int main(){
	unique<int> obj1(new int(8));
	unique<int> obj2 = (move(obj1)) ;
	cout<<*obj2<<endl;
	
	obj1 = Print (move(obj2));
	cout<<"*obj1: "<<*obj1<<endl;
	return 1;
}
