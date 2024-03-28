#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::string revers_data{data};
        std::reverse(revers_data.begin(), revers_data.end());
        text_->render(revers_data);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text* text) : DecoratedText(text) {}
    void render(const std::string& href, const std::string& data) const {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};


int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << "\n";

    auto text_block_1 = new Paragraph(new Text());
    text_block_1->render("Hello world");
    std::cout << "\n";

    auto text_block_2 = new Reversed(new Text());
    text_block_2->render("Hello world");
    std::cout << "\n";

    auto text_block_3 = new Link((new Reversed(new Text)));
    text_block_3->render("netology.ru", "Hello world");
}
