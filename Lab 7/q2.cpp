#include<iostream>
#include<cmath>
#include<vector>
#include<string>
float M_PI=22/7;
using namespace std;

class Shape{
protected:
    float xPos,yPos,borderWidth;
    string shapeColor;
public:
    Shape(float x=0,float y=0,string color="black",float border=1.0):xPos(x),yPos(y),shapeColor(color),borderWidth(border){}
    virtual void display()const=0;
    virtual float getArea()const=0;
    virtual float getPerimeter()const=0;
    virtual ~Shape(){}
};

class Circle:public Shape{
private:
    float radius;
public:
    Circle(float r,float centerX=0,float centerY=0,string color="black",float border=1.0):Shape(centerX,centerY,color,border),radius(r){}
    void display()const override{
        cout<<"Calculating Circle at ("<<xPos<<","<<yPos<<") with:\n - Radius: "<<radius<<"\n - Color: "<<shapeColor<<"\n - Border Width: "<<borderWidth<<endl;
    }
    float getArea()const override{
        return M_PI*radius*radius;
    }
    float getPerimeter()const override{
        return 2*M_PI*radius;
    }
};

class Rectangle:public Shape{
private:
    float width,height;
public:
    Rectangle(float w,float h,float xTopLeft=0,float yTopLeft=0,string color="black",float border=1.0):Shape(xTopLeft,yTopLeft,color,border),width(w),height(h){}
    void display()const override{
        cout<<"Calculating Rectangle at ("<<xPos<<","<<yPos<<") with:\n - Width: "<<width<<"\n - Height: "<<height<<"\n - Color: "<<shapeColor<<"\n - Border Width: "<<borderWidth<<endl;
    }
    float getArea()const override{
        return width*height;
    }
    float getPerimeter()const override{
        return 2*(width+height);
    }
};

class Triangle:public Shape{
private:
    float sideA,sideB,sideC;
public:
    Triangle(float a,float b,float c,float posX=0,float posY=0,string color="black",float border=1.0):Shape(posX,posY,color,border),sideA(a),sideB(b),sideC(c){}
    void display()const override{
        cout<<"Calculating Triangle at ("<<xPos<<","<<yPos<<") with sides:\n - Side A: "<<sideA<<"\n - Side B: "<<sideB<<"\n - Side C: "<<sideC<<"\n - Color: "<<shapeColor<<"\n - Border Width: "<<borderWidth<<endl;
    }
    float getArea()const override{
        float s=(sideA+sideB+sideC)/2;
        return sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
    }
    float getPerimeter()const override{
        return sideA+sideB+sideC;
    }
};

class Polygon:public Shape{
private:
    vector<float> edges;
public:
    Polygon(const vector<float>& sides,float x=0,float y=0,string color="black",float border=1.0):Shape(x,y,color,border),edges(sides){}
    void display()const override{
        cout<<"Calculating Polygon at ("<<xPos<<","<<yPos<<") with sides:\n - Sides: ";
        for(float side:edges){
            cout<<side<<" ";
        }
        cout<<"\n - Color: "<<shapeColor<<"\n - Border Width: "<<borderWidth<<endl;
    }
    float getArea()const override{
        float numSides=edges.size(),length=edges[0];
        return (numSides*length*length)/(4*tan(M_PI/numSides));
    }
    float getPerimeter()const override{
        float totalPerimeter=0;
        for(float side:edges){
            totalPerimeter+=side;
        }
        return totalPerimeter;
    }
};

int main(){
    Circle circle(5.0,2.0,3.0,"red");
    Rectangle rectangle(4.0,6.0,1.0,1.0,"blue",2.0);
    Triangle triangle(3.0,4.0,5.0,0.0,0.0,"green");
    Polygon polygon({3.0,3.0,3.0,3.0,3.0},5.0,5.0,"yellow");

    vector<Shape*> shapeCollection={&circle,&rectangle,&triangle,&polygon};

    for(Shape* shape:shapeCollection){
        shape->display();
        cout<<"Area: "<<shape->getArea()<<"\nPerimeter: "<<shape->getPerimeter()<<"\n------------------------"<<endl;
    }
    return 0;
}

