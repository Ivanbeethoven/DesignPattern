#include <iostream>
#include <string>
#include <vector>
#include<memory>
// 备忘录类
class EditorMemento {
public:
    EditorMemento() =default;
    std::string getContent() const {
        return this->history_.back();
    }
    void setContent(std::string content){
        this->history_.push_back(content);
      
    }
    void popContent(){
        this->history_.pop_back();
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
        content_ += text;
    }
    void undo() {
            content_ = memento->getContent();
            memento->popContent();
    }
    void save() {
        memento->setContent(content_);
    }

    void print() {
        std::cout << "Editor Content: " << content_ << std::endl;
    }

private:
    std::string content_;
    std::shared_ptr<EditorMemento> memento;
};

// 命令接口
class Command {
public:
    virtual void execute() = 0;
};

// 具体命令 - 输入文本
class TypeCommand : public Command {
public:
    TypeCommand(TextEditor& editor, const std::string& text) : editor_(editor), text_(text) {}

    void execute() override {
        editor_.save();
        editor_.type(text_);
    }

private:
    TextEditor& editor_;
    std::string text_;
};

// 具体命令 - 撤销
class UndoCommand : public Command {
public:
    UndoCommand(TextEditor& editor) : editor_(editor) {}

    void execute() override {
        editor_.undo();
    }

private:
    TextEditor& editor_;
};

int main() {
    TextEditor editor;

    Command* typeCommand1 = new TypeCommand(editor, "Hello, ");
    Command* typeCommand2 = new TypeCommand(editor, "world!");

    typeCommand1->execute();
    editor.print();

    typeCommand2->execute();
    editor.print();

    Command* undoCommand = new UndoCommand(editor);
    undoCommand->execute();
    editor.print();

    delete typeCommand1;
    delete typeCommand2;
    delete undoCommand;

    return 0;
}
