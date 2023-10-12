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
public:
    std::string process(const std::string& input) override {
        std::string result = input;
        for (char& c : result) {
            if (std::islower(c)) {
                c = std::toupper(c);
            }
        }
        return result;
    }
};

// 具体策略类2：转换为小写
class ToLowerCaseStrategy : public StringProcessStrategy {
public:
    std::string process(const std::string& input) override {
        std::string result = input;
        for (char& c : result) {
            if (std::isupper(c)) {
                c = std::tolower(c);
            }
        }
        return result;
    }
};

// 具体策略类3：反转字符串
class ReverseStringStrategy : public StringProcessStrategy {
public:
    std::string process(const std::string& input) override {
        std::string result = input;
        std::reverse(result.begin(), result.end());
        return result;
    }
};

// 上下文类：字符串处理器
class StringProcessor {
private:
    StringProcessStrategy* strategy;

public:
    StringProcessor(StringProcessStrategy* strategy) : strategy(strategy) {}

    void setStrategy(StringProcessStrategy* newStrategy) {
        strategy = newStrategy;
    }

    std::string processString(const std::string& input) {
        if (strategy) {
            return strategy->process(input);
        } else {
            return input; // 默认策略，不进行处理
        }
    }
};

int main() {
    // 创建字符串处理器并设置初始策略为转换为大写
    StringProcessor processor(new ToUpperCaseStrategy());

    std::vector<std::string> strings = {"Hello, World!", "C++ Programming", "Strategy Pattern"};

    for (const std::string& str : strings) {
        std::string processed = processor.processString(str);
        std::cout << "Original: " << str << ", Processed: " << processed << std::endl;
    }

    // 切换策略为反转字符串
    processor.setStrategy(new ReverseStringStrategy());

    for (const std::string& str : strings) {
        std::string processed = processor.processString(str);
        std::cout << "Original: " << str << ", Processed: " << processed << std::endl;
    }

    return 0;
}
