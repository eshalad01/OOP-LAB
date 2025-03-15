#include <iostream>
#include <string>

using namespace std;  

class MediaFile {
protected:
    string filePath;
    double fileSize; 

public:
    MediaFile(const string& path,double size):filePath(path),fileSize(size) {}

    virtual void play() {
        cout<<"Playing media file:"<<filePath<<endl;
    }

    virtual void stop() {
        cout<<"Stopping media file:"<<filePath<<endl;
    }

    virtual ~MediaFile() {} 
};

class VisualMedia:virtual public MediaFile {
protected:
    int width,height;

public:
    VisualMedia(const string& path,double size,int w,int h)
        :MediaFile(path,size),width(w),height(h) {}

    void displayResolution() {
        cout<<"Resolution:"<<width<<"x"<<height<<endl;
    }
};

class AudioMedia:virtual public MediaFile {
protected:
    int sampleRate;

public:
    AudioMedia(const string& path,double size,int rate)
        :MediaFile(path,size),sampleRate(rate) {}

    void displaySampleRate() {
        cout<<"Sample Rate:"<<sampleRate<<"Hz"<<endl;
    }
};

class ImageFile:public VisualMedia {
public:
    ImageFile(const string& path,double size,int w,int h)
        :MediaFile(path,size),VisualMedia(path,size,w,h) {}

    void play() {
        cout<<"Displaying image:"<<filePath<<endl;
        displayResolution();
    }
};

class AudioFile:public AudioMedia {
public:
    AudioFile(const string& path,double size,int rate)
        :MediaFile(path,size),AudioMedia(path,size,rate) {}

    void play() {
        cout<<"Playing audio file:"<<filePath<<endl;
        displaySampleRate();
    }
};

class VideoFile:public VisualMedia,public AudioMedia {
public:
    VideoFile(const string& path,double size,int w,int h,int rate)
        :MediaFile(path,size),VisualMedia(path,size,w,h),AudioMedia(path,size,rate) {}

    void play() {
        cout<<"Playing video file:"<<filePath<<endl;
        displayResolution();
        displaySampleRate();
    }

    void stop() {
        cout<<"Stopping video file:"<<filePath<<endl;
    }
};

int main() {
    MediaFile* media1=new VideoFile("video.mp4",150.0,1920,1080,44100);
    MediaFile* media2=new AudioFile("song.mp3",5.0,48000);
    MediaFile* media3=new ImageFile("picture.jpg",2.5,1280,720);

    media1->play();
    media1->stop();
    cout<<endl;

    media2->play();
    media2->stop();
    cout<<endl;

    media3->play();
    media3->stop();
    cout<<endl;

    delete media1;
    delete media2;
    delete media3;

    return 0;
}

