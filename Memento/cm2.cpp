#include <iostream>
#include <string>
#include <vector>
#include <memory>
// 备忘录类
class EditorMemento {
public:
    EditorMemento() =default;
    void addContent(std::string content){
        this->history_.push_back(content);
    }
    std::string popContent(){
        std::string a = this->history_.back();
        this->history_.pop_back();
        return a;
    }
private:
    std::vector<std::string> history_;
};

// 编辑器类
class TextEditor {
public:
    TextEditor(){
        this->content_= "";
        this->memento = std::make_shared<EditorMemento>();
    };
    void type(const std::string& text) {
        memento->addContent(content_);
        content_ += text;
  }
    void undo() {
        content_ = memento->popContent();
  }
    void print() {
        std::cout << "Editor Content: " << content_ << std::endl;
  }
private:
    std::string content_;
    std::shared_ptr<EditorMemento> memento;
};

int main() {
    TextEditor editor;
    editor.type("Hello, ");
    editor.print(); //Hello,

    editor.type("world");
    editor.print();//Hello, world

    editor.undo();
    editor.print();//Hello,

    return 0;
}
