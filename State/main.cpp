#include <iostream>
#include <thread>
#include <chrono>

// 前向声明 TrafficLight 类
class TrafficLight;

// 状态接口
class TrafficLightState {
public:
    virtual void changeState(TrafficLight& trafficLight) = 0;
    virtual void handle() = 0;
};

// 具体状态1：红灯
class RedLightState : public TrafficLightState {
public:
    void changeState(TrafficLight& trafficLight) override;
    void handle() override {
        std::cout << "Light is Red... Wait..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
};

// 具体状态2：绿灯
class GreenLightState : public TrafficLightState {
public:
    void changeState(TrafficLight& trafficLight) override;
    void handle() override {
        std::cout << "Light is Green, Just Go!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
};
// 具体状态3：黄灯
class YellowLightState : public TrafficLightState {
public:
    void changeState(TrafficLight& trafficLight) override;
    void handle() override {
        std::cout << "Light is Yellow, Be Careful." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
};
// 上下文类，维护状态
class TrafficLight {
private:
    TrafficLightState* currentState;

public:
    TrafficLight() : currentState(new RedLightState()) {}
    void setState(TrafficLightState* newState) {
        delete currentState; // 释放旧状态
        currentState = newState;
    }
    void start() {
        while (true) {
            currentState->handle();
           currentState->changeState(*this);
        }
    }
};

// 具体状态的状态转换逻辑
void RedLightState::changeState(TrafficLight& trafficLight) {
    trafficLight.setState(new GreenLightState());
}

void GreenLightState::changeState(TrafficLight& trafficLight) {
    trafficLight.setState(new YellowLightState());
}

void YellowLightState::changeState(TrafficLight& trafficLight) {
    trafficLight.setState(new RedLightState());
}

int main() {
    TrafficLight trafficLight;

    // 启动交通信号灯状态机
    trafficLight.start();

    return 0;
}
