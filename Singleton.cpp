#include <iostream>

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
    testDemo();
    return 0;
}