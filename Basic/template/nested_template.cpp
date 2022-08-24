// nested_class_template2.cpp
// compile with: /EHsc
// 使用前套来处理模版

#include <iostream>
using namespace std;

template <class T>
class X
{
	template <class U> class Y
	{
		U* u;
	public:
		Y();
		U& Value();
		void print();
		~Y();
	};

	Y<int> y;
public:
	X(T t) { y.Value() = t; }
	void print() { y.print(); }
};

template <class T>
template <class U>
X<T>::Y<U>::Y()
{ 
	// 构造函数
	cout << "X<T>::Y<U>::Y()" << endl;
	u = new U();
}

template <class T>
template <class U>
U& X<T>::Y<U>::Value()
{
   return *u;
}

template <class T>
template <class U>
void X<T>::Y<U>::print()
{
   cout << this->Value() << endl;
}

template <class T>
template <class U>
X<T>::Y<U>::~Y()
{
   cout << "X<T>::Y<U>::~Y()" << endl;
   delete u;
}

int main()
{
	// new 表示新建一个类， 是c++的用法, xi是指向X对象的指针，执行完后需要 delete
	X<int>* xi = new X<int>(10); 
	X<char>* xc = new X<char>('c'); // 
	xi->print();
	xc->print();
	delete xi;
	delete xc;
}

/* 
Output:
X<T>::Y<U>::Y()
X<T>::Y<U>::Y()
10
*/