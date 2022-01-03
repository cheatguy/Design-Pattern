class IProgress{
    public:
    virtual void Doprogress(float value) = 0;
    virtual void ~Iprogress(){}
}


class FileSplitter{
    string m_filePath;
    int m_fileNumber;

    ProgressBar * m_progressBar; //这部分是变化的

public:
    FileSplitter(const string& filePath,int fileNumber,ProgressBar * progressBar):
    m_filePath(filePath),m_fileNumber(fileNumber),m_progressBar(progressBar){

    }

    void split(){


        for (int i=0;i<m_fileNumber;i++){
            //.
            float progressValue = m_fileNumber;
            progressValue = (i+1) / m_fileNumber;
            m_progressBar -> setValue(i+1/m_fileNumber);  // update process 
        }
    }
}