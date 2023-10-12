#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 策略接口：字符串处理策略
class StringProcessStrategy {
public:
    virtual std::string process(const std::string& input) = 0;
};
// 具体策略类1：转换为大写
class ToUpperCaseStrategy : public StringProcessStrategy {
    std::string process(const std::string& input) override {...}
};
// 具体策略类3：反转字符串
class ReverseStringStrategy : public StringProcessStrategy {
    std::string process(const std::string& input) override {...}
};

// 上下文类：字符串处理器
class StringProcessor {
private:
    StringProcessStrategy* strategy;
public:
    void setStrategy(StringProcessStrategy* newStrategy) {
        strategy = newStrategy;
    }
    std::string processString(const std::string& input) {
        return strategy->process(input);
    }
};
int main() {
    // 创建字符串处理器并设置初始策略为转换为大写
    StringProcessor processor(new ToUpperCaseStrategy());
    std::string str = "Hello, World!";
    std::string processed = processor.processString(str);
    std::cin<<processor.processString(str)<<std::endl;

    // 切换策略为反转字符串
    processor.setStrategy(new ReverseStringStrategy());
    std::cin<<processor.processString(str)<<std::endl;

}
