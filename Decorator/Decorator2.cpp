class Stream{
    //Stream * stream; // new FileStream 
    //将stream提到这里不合适,因为FileStream,Netstream ,中不需要这些指针,使用
    // 中间件来添加这个ptr
public:
    virtual char Read(int number)=0;
    virtual void Seek(int pos)=0;
    virtual void Write(char data)=0;

    virtual void ~Stream(){};
};
class DecoratorStream :public Stream{
protected:
    Stream * stream;
    DecoratorStream(Stream *stm):stream(stm) {}
};
class FileStream : public Stream{  //可以单独进行的操作 
public:
    virtual char Read(int number){
        // ...
    }
    virtual void Seek(int pos){
        // ...
    }
    virtual void Write(char data){
        // ....
    }
};
class NetStream: public Stream{
public:
    virtual char Read(int number){
        // ...
    }
    virtual void Seek(int pos){
        // ...
    }
    virtual void Write(char data){
        // ....
    }
};
class MemoryStream : public Stream{
public:
    virtual char Read(int number){
        // ...
    }
    virtual void Seek(int pos){
        // ...
    }
    virtual void Write(char data){
        // ....
    }
};

class CryptonStream : public DecoratorStream{  // 拓展操作,附着在基本操作上的操作
public:
    CryptonStream(Stream * stream):DecoratorStream(stream){

    };
    virtual char Read(int number){

    }
    //ect...
};
class BufferStream : public DecoratorStream{  // 附着在其他类上的操作
public:
    BufferStream(Stream * stream):DecoratorStream(stream){

    };
    virtual char Read(int number){

    }
    //ect...
};
void Process(){
    FileStream *s1 = new FileStream();
    CryptonStream *s2 = new CryptonStream();


    BufferedStream * s3 = new BufferedStream(s1);
    BufferedStream * s4 = new BufferedStream(s2);

    FileStream * s1 = new FileStream();
    CryptonStream * s2 = new CryptonStream(s1);  // use virtual func 

    BufferedStream * s3 = new BufferedStream(s1);


}