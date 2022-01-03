class Messager{
    public:
    virtual void Login(string username ,string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;
    
    virtual void Playsound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
     
    virtual void ~Messager(){};

}

class PCMessageBase : public Messager {
    public :
    virtual void Playsound{

    }
    virtual void DrawShape{

    }
    virtual void WriteText(){

    }
    virtual void Connect(){

    }
}



class mobilemessagebase : public messager {
    public :
    virtual void playsound{

    }
    virtual void drawshape{

    }
    virtual void writetext(){

    }
    virtual void connect(){

    }
}

class PCMessageLite : public PCMessagerBase {  // 精简版,拓展的操作
    public :
    virtual void Login(string username,string password){
        PCMessageBase::connect();
    }
    virtual void SendMessage(string message){
        PCMessageBase::WriteText();
    }
    virtual void SendPicture(Image image){
        PCMessageBase::DrawShape();
    }
}

class PCMessagePerfect : public PCMessagerBase {  // 拓展版,拓展的操作
    public :
    virtual void Login(string username,string password){
        PCMessageBase::connect();
    }
    virtual void SendMessage(string message){
        PCMessageBase::WriteText();
    }
    virtual void SendPicture(Image image){
        PCMessageBase::DrawShape();
    }
}
//for mobile platform ,it also has lite and perfect version to select