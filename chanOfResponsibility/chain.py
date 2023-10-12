# 定义一个处理器基类
class Handler:
    def __init__(self, successor=None):
        self.successor = successor

    def handle_request(self, request):
        if self.successor:
            self.successor.handle_request(request)
            
# 具体处理器类
class ConcreteHandler1(Handler):
    def handle_request(self, request):
        if request == "Request1":
            print("ConcreteHandler1 处理请求")
        else:
            super().handle_request(request)

class ConcreteHandler2(Handler):
    def handle_request(self, request):
        if request == "Request2":
            print("ConcreteHandler2 处理请求")
        else:
            super().handle_request(request)

class ConcreteHandler3(Handler):
    def handle_request(self, request):
        if request == "Request3":
            print("ConcreteHandler3 处理请求")
        else:
            print("无法处理请求")


class HandlerChain:
    def __init__(self):
        self.handlers = []

    def addHandler(self,handler:Handler):
        if len(self.handlers)>0:
            self.handlers[len(self.handlers)-1].successor = handler
        self.handlers.append(handler)
    

    def handle_request(self,request):
        self.handlers[0].handle_request(request)

    # def change_handler(self,handler:Handler , postion:int , mode:int):    

# 客户端代码
if __name__ == "__main__":
    chain = HandlerChain()
    chain.addHandler(ConcreteHandler1())
    chain.addHandler(ConcreteHandler2())
    chain.addHandler(ConcreteHandler3())
    
    requests = ["Request1", "Request2", "Request3", "Request4"]

    for request in requests:
        chain.handle_request(request)
    
