#include <iostream>

// 抽象状态类
class TCPState {
public:
    virtual void handle(TCPConnection& connection) {}
};

// 具体状态类：CLOSED
class ClosedState : public TCPState {
public:
    void handle(TCPConnection& connection) override {
        std::cout << "Connection request sent (SYN_SENT)." << std::endl;
        // 状态转换
        connection.changeState(new SynSentState());
    }
};

// 具体状态类：SYN_SENT
class SynSentState : public TCPState {
public:
    void handle(TCPConnection& connection) override {
        std::cout << "Connection established (ESTABLISHED)." << std::endl;
        // 状态转换
        connection.changeState(new EstablishedState());
    }
};

// 具体状态类：ESTABLISHED
class EstablishedState : public TCPState {
public:
    void handle(TCPConnection& connection) override {
        std::cout << "Connection closing initiated (FIN_WAIT_1)." << std::endl;
        // 状态转换
        connection.changeState(new FinWait1State());
    }
};

// 具体状态类：FIN_WAIT_1
class FinWait1State : public TCPState {
public:
    void handle(TCPConnection& connection) override {
        std::cout << "Received confirmation (FIN_WAIT_2)." << std::endl;
        // 状态转换
        connection.changeState(new FinWait2State());
    }
};

// 具体状态类：FIN_WAIT_2
class FinWait2State : public TCPState {
public:
    void handle(TCPConnection& connection) override {
        std::cout << "Connection closed (CLOSED)." << std::endl;
        // 状态转换
        connection.changeState(new ClosedState());
    }
};

// TCP连接类
class TCPConnection {
public:
    TCPConnection() : currentState(nullptr) {
        currentState = new ClosedState();
    }

    void changeState(TCPState* state) {
        delete currentState;
        currentState = state;
    }

    void establishConnection() {
        currentState->handle(*this);
    }

    void confirmConnection() {
        currentState->handle(*this);
    }

    void closeConnection() {
        currentState->handle(*this);
    }

    void receiveConfirmation() {
        currentState->handle(*this);
    }

    void completeClosing() {
        currentState->handle(*this);
    }

private:
    TCPState* currentState;
};

int main() {
    TCPConnection tcpConnection;

    tcpConnection.establishConnection();
    tcpConnection.confirmConnection();
    tcpConnection.closeConnection();
    tcpConnection.receiveConfirmation();
    tcpConnection.completeClosing();

    return 0;
}
