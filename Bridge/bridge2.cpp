

class MessageImp{ //桥模式的特点, 把两个不同方向的拓展分发到两个模式中,
// 业务方面的实现
public:
    virtual void Playsound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
        
    virtual void ~MessageImp(){};    
};

class Messager{
    MessageImp * messagerImp ; //通过ptr连接桥的两部分 
//平台方面的实现 
public:
    virtual void Login(string username ,string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;

    virtual void ~Messager(){};

};

class PCMessageImp: public MessageImp { // 和装饰者模式的区别是,这些不能组合 ,lite or perfect
    public :
    virtual void Playsound{  //对imp的不同实现方法

    }
    virtual void DrawShape{

    }
    virtual void WriteText(){

    }
    virtual void Connect(){

    }
};



class MobileMessageImp: public MessageImp{
public :
    virtual void Playsound{

    }
    virtual void Drawshape{

    }
    virtual void Writetext(){

    }
    virtual void Connect(){

    }
};

//short for pc/mobile MessageLite 
class MessageLite :public Messager{
    virtual void Login(string username,string password){
        messagerImp->connect();
    }
    virtual void SendMessage(string message){
        messagerImp->WriteText();
    }
    virtual void SendPicture(Image image){
        messagerImp->DrawShape();
    }
};
class MessagePerfect:public Messager{ //Perfect 和Lite 两个版本,都有messager的ptr ,提到父类 
    virtual void Login(string username,string password){
        messagerImp->connect();
    }
    virtual void SendMessage(string message){
        messagerImp->WriteText();
    }
    virtual void SendPicture(Image image){
        messagerImp->DrawShape();
    }
};
void Process(){
   //编译时装配
   Messager *m = new MobileMessagePerfect();
   //运行时装配 
   MessageImp * mImp = new PCMessageImp()  
   Messager *m = new Messager(mImp);
   
}