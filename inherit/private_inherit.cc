
#include <iostream>

class Mouse {
public:
    void Click(){
        std::cout << "Hello, I'm Mouse, please click me..." << std::endl;
    }

};

class Computer : private Mouse {

public:
    void PowerOn() {
        std::cout << "Welcomt to compute world." << std::endl;
        Click();
    }

};

void App(){
    std::shared_ptr<Mouse> mouse = std::make_shared<Mouse>();
    mouse->Click();

    // 下面的这行代码无法通过编译，使用私有继承的类已经不再是is-a的关系，也就是两个不一样的类实体
    //std::shared_ptr<Computer> computer = std::make_shared<Mouse>();

    std::shared_ptr<Computer> computer = std::make_shared<Computer>();

    // 下面的这行代码也无法通过编译，因为使用私有继承的方法仅能在内部使用，无法对外呈现
    //computer->Click();

    computer->PowerOn();

}

int main(void)
{
    App();
    return 0;
}