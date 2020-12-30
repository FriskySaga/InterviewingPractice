// To compile on my WSL:
//   g++ Multithreading.cpp -std=c++11 -pthread
// To run ThreadSantizer (TSan):
//   g++ Multithreading.cpp -std=c++11 -pthread -fsanitize=thread -O2 -g

#include <iostream>
#include <thread>
 
// #1) Using Function Pointer (function to be used in callable)
// Example usage:
//   std::thread th1(myFunction, 2);
void myFunction(int n)
{
  for (int i = 0; i < n; ++i)
  {
    std::cout << "Thread 1 :: callable => function pointer\n";
  }
}
  
// #2) Using The Function Object (a callable object)
// We can use a function object as a callable in the thread object. For using the
// function object, we need to have a class and in that class, we overload the
// operator ().
// Note the way in which the thread object is defined. As the first parameter to the
// constructor of thread object, we provide the overloaded function and then specify
// its arguments (params) as the second argument.
// Example usage:
//   std::thread th2(myClass(), 2);
class myClass
{
public:
  void operator()(int n)
  {
    for (int i = 0; i < n; i++)
    {
      std::cout << "Thread 2 :: callable => function object\n";
    }
  }
};

int main()
{
  // #3) Using A Lambda Expression
  // We can also have a callable as a lambda expression and pass it to the thread
  // object for execution. The code snippet for the same is shown below.
  // In the below code, we have defined a lambda expression f and we then pass it to
  // the thread object constructor as the first argument followed by its parameters
  // (params) as the second argument.
  // Example usage:
  //   std::thread th3(myLambda, 2);
  auto myLambda = [](int n)
  {
    for (int i = 0; i < n; ++i)
    {
      std::cout << "Thread 3 :: callable => lambda expression\n";
    }
  };

  // Launch thread using function pointer as callable
  std::thread th1(myFunction, 2);
  th1.join();

  // Launch thread using function object as callable
  std::thread th2(myClass(), 2);
  th2.join();

  // Launch thread using lambda expression as callable
  std::thread th3(myLambda, 2);
  th3.join();

  return 0;
}
