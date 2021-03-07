
#include <iostream>

class B {
public:
    virtual void work() = 0;

};

class A : public B {

public:
    void work() {
        std::cout << " this is A..." << std::endl;
    }


};

void App(){
    std::shared_ptr<B> b = std::make_shared<A>();
    b->work();
}

int main(void)
{
    App();
    return 0;
}