class Stream{
public:
    virtual char Read(int number)=0;
    virtual void Seek(int pos)=0;
    virtual void Write(char data)=0;

    virtual void ~Stream(){};
};

class FileStream : public Stream{
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
class CryptoFileStream : public FileStream{
public:
    virtual char Read(int number){
        // addtional crypton operation
        FileStream::Read(number);
        // ...
    }
    virtual void Seek(int pos){
        // addtional operation 
        FileStream::Seek(pos);
        // ...
    }
    virtual void Write(char data){
        // ....
        FileStream::Write(data);
    }
};
class BufferFileStream : public FileStream{
public:
    virtual char Read(int number){
        // addtional crypton operation
        FileStream::Read(number);
        // ...
    }
    virtual void Seek(int pos){
        // addtional operation 
        FileStream::Seek(pos);
        // ...
    }
    virtual void Write(char data){
        // ....
        FileStream::Write(data);
    }
};
class CryptoNetStream : public FileStream{
    //... 
};

void Process(){
    CryptonFileStream *fs1 = new CryptonfileStream();
    //......
    
}