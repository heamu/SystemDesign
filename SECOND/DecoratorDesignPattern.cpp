#include<bits/stdc++.h>
using namespace std;

// hello my self hemanth kumar i am implementing this fo
// i have seen this example from algo master

//listen the decor interface class is is a normal class and also consists of another class right 

class TextRender{
    public:
    string text;
    virtual void render() = 0;
};

class Docs:public TextRender{
    public:
    Docs(string text){
        this->text = text;
    }
    void render()override{
        cout<<text;
    }
};

class TextDecorator : public TextRender{
    public:
    TextRender*Render;
    virtual void render() = 0;
};

class BoldDecor : public TextDecorator{
    public:
    BoldDecor(TextRender*Render){
        this->Render = Render;
    }
    void render() override{
        cout<<"<b>";
        Render->render();
        cout<<"</b>";
    }
};

class UnderDecor : public TextDecorator{
    public:
    UnderDecor(TextRender*Render){
        this->Render = Render;
    }
    void render() override{
        cout<<"<u>";
        Render->render();
        cout<<"</u>";
    }
};

class ItalicDecor : public TextDecorator{
    public:
    ItalicDecor(TextRender*Render){
        this->Render = Render;
    }
    void render() override{
        cout<<"<i>";
        Render->render();
        cout<<"</i>";
    }
};

int main(){
    Docs doc("My first Heading");
    doc.render();cout<<endl;

    ItalicDecor italicdec(&doc);
    italicdec.render();cout<<endl;

    BoldDecor boldItalic(&italicdec);
    boldItalic.render();cout<<endl;

    return 0;
}