class Mainform:public Form,public IProgress{   //一个是主的继承类，其他的都是接口
    TextBox * txtFilePath;
    TextBox * txtFileNumber;
    
    ProgressBar * m_progressBar; //违背了依赖倒置原则，Mainform依赖progressBar的具体实现
    //但是进度条的展示是多样的 ，容易变化的部分


public:
    void Button_click1(){
        string filePath = txtFilePath -> getText();
        int number = atoi(txtfilepath ->getText().c_str());
        FileSplitter splitter (filePath,number,progressBar);
        splitter.split();
    }

    virtual void Doprogress(float value){
        ProgressBar->setValue(value);
        
    }
}