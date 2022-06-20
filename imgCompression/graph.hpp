//
//  graph.hpp
//  imgCompression
//
//  Created by Liyu Zerihun on 3/28/22.
//

#ifndef graph_hpp
#define graph_hpp
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

class graph{
  
public:
    graph(){
        m_width=1000;
        m_height=1000;
        z_max=10;
        zNormal=1;
        yNormal=1;
        xNormal=2;
        dNormal=10;
        point=4*xNormal +5*yNormal+ -1*(((xNormal+yNormal)+dNormal)/zNormal);
        magnitude=sqrt(pow(zNormal,2)+pow(xNormal,2)+pow(yNormal,2));
        for(int i=0; i<m_height; i=i+1){
            vector<RGB> x;
            for(int m=0; m<m_width; m++){
                
                RGB mx;
                mx.b=255;
                mx.r=255;
                mx.g=255;
                mx.isEmpty=false;
                x.push_back(mx);
            
        }
            matrix.push_back(x);
            
    }
    }
    void updateGraph(int count, string path);
    double valueWithAngle(double x, double y, double val);
    

private:

    struct RGB{
        double b;
        double r;
        double g;
        bool isEmpty;
    };
    
    
    struct ComplexNumber{
        double a;
        double b;
        ComplexNumber(double A, double B):
        a(A), b(B)
        {
            
        }
        
        ComplexNumber& operator=( const ComplexNumber& bC){
            a=bC.a;
            b=bC.b;
            return *this;
        }
        
        double r(){
            
            return sqrt(pow(a,2)+ pow(b,2));
        }
        
        double theta(){
            
            return atan(b/a);
        }
        
    };
    
    ComplexNumber returnSquare(ComplexNumber c);
    ComplexNumber add (ComplexNumber a, ComplexNumber b);
    ComplexNumber multiply (ComplexNumber a, ComplexNumber b);
    ComplexNumber raisedTo(ComplexNumber a, double n);
    ComplexNumber eTo(ComplexNumber a);
    ComplexNumber extendedRaisedTo(ComplexNumber a, ComplexNumber b);
    

    ComplexNumber recursivePowersvalue(ComplexNumber left, ComplexNumber right, int value, ComplexNumber f);
    
    double chaoticExponentiation(ComplexNumber a, ComplexNumber b, int count);
    double bifrication(double a, double b, int count, double r, int x, int y);
    double value(ComplexNumber left, ComplexNumber right, int value);
    double teteration(ComplexNumber left, ComplexNumber right);
    double xNormal;
    double yNormal;
    double zNormal;
    double dNormal;
    double magnitude;
    double point;
    
    double m_width;
    double m_height;
    double z_max;
    vector<vector<RGB>> matrix;
    vector<double> vr;
    vector<double> xC;
    vector<double> yC;

    void recursiveUpdate(double x, double y, double s, double c);

    
};
#endif /* graph_hpp */
