#include<iostream>

/* 使用全局静态变量实现 饿汉式 线程安全 */
class Signleton{
private:
    Signleton() {
        std::cout<<"调用构造函数"<<std::endl;
    }
    static Signleton ins;
public:
    ~Signleton() {
        std::cout<<"调用析构函数"<<std::endl;
    }
    Signleton(const Signleton&) = delete;
    Signleton&  operator =(const Signleton&) = delete;
    static Signleton& instance() {
        return ins;
    }
};
Signleton Signleton::ins;
void testDemo() 
{
    auto &s1 = Signleton::instance();
    auto &s2 = Signleton::instance();
}
int main()
{
    testDemo(); //打印一次构造 一次析构
    return 0;
}