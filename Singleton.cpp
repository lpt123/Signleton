#include <iostream>
/*  使用静态局部变量实现 懒汉式 线程安全由c++11的特性做出保证   */
class Signleton{
private:
    Signleton() {
        std::cout<<"调用构造函数"<<std::endl;
    }
public:
    ~Signleton() {
        std::cout<<"调用析构函数"<<std::endl;
    }
    Signleton(const Signleton&) = delete;
    Signleton& operator = (const Signleton&) = delete;
    static Signleton& instance() {
        static Signleton instance;
        return instance;
    }
};
void testDemo() 
{
    auto& s1 = Signleton::instance();
    auto& s2 = Signleton::instance();
}
int main() 
{
    testDemo();  // 可以发现只会打印 一次构造函数和析构函数
    return 0;
}