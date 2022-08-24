/*

MSDOC: https://docs.microsoft.com/zh-cn/cpp/cpp/templates-cpp?view=msvc-170

本例还涉及了操作符号+的重载

函数模版: 不需要为每个类型重新定义一个函数, 可以通过参数类型隐式的指定

类模版: 可以在类的内部和外部都定义模版，在外部时类似模版函数；
*/

#include <typeinfo>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

// ------  header  ------------ 
template<typename T, int MAXSIZE>
class class_template {
  private:
    std::queue<T> ele; // 如果想包含不同数据
    int top;
  public:
    class_template(){top=0;}
    void push(T e);
    void operator+(T e){
      push(e);
    }
    bool full(){
      return top > MAXSIZE-1? 1: 0;
    }
    T pop();
    void show(){
      std::queue<T> _cp_data = ele;
      for (int i=0; i<top; i++){
        std::cout << _cp_data.front() << std::endl;
        _cp_data.pop();
      }
    }
    void reset(){
      ele = std::queue<T>();
      top = 0;
    }

};
// -----------------------------

template <typename T>
int function_tempate1(T a) {
  std::cout << typeid(a).name() << std::endl;
  std::cout << sizeof(a) << std::endl;
  return 0;
}


template<typename T, int MAXSIZE>
void class_template<T, MAXSIZE>::push(T e){
  if (full()==1) {
    std::cout << "Pop First elements" << std::endl;
    pop();
  }
  top++;
  ele.push(e);
}

template<typename T, int MAXSIZE>
T class_template<T, MAXSIZE>::pop(){
  // return and pop
  T val = ele.front();
  top--;
  ele.pop();
  return val;
}

void print_line(){
  size_t num = 30;
  std::string _line (" "); _line.resize(num);
  std::fill(_line.begin(), _line.end(), '-' );
  std::cout << _line << std::endl;
}

int main(){
  int a = 0;
  
  std::cout << "test function template" << std::endl;
  print_line();
  int t1 = function_tempate1(a); //  编译器会使用参数来实例化
  int t2 = function_tempate1<double>(a); //  会把a转成double的类型
  std::cout << "\ntest class template" << std::endl;
  print_line();

  class_template<float, 5> classt = class_template<float, 5>();
  classt + 4;
  classt.show();
  classt + 3;
  classt.show();
  classt + 2;
  classt + 1;
  classt + 10;
  classt + 12;
  classt + 13;
  classt + 12;
  print_line();
  classt.show();
  std::cout << classt.full() << std::endl;


}



