//
//  graph.cpp
//  imgCompression
//
//  Created by Liyu Zerihun on 3/28/22.
//
#include <sstream>  // defines the type std::ostringstream

#include "graph.hpp"

graph:: ComplexNumber graph:: returnSquare(ComplexNumber aC){
    
    ComplexNumber c(0, 0);
    
    double aSquared= pow(aC.a,2);
    double bSquared= -1*pow(aC.b,2);
    double aAndB= 2*(aC.a*aC.b);
    
    c.a=aSquared+bSquared;
    c.b=aAndB;
    
    return c;

}
graph:: ComplexNumber graph:: multiply (ComplexNumber aC, ComplexNumber bC){
    ComplexNumber c(0, 0);
    
    
    
    c.a=aC.a*bC.a + -1*aC.b*bC.b;
    c.b=aC.b*bC.a +aC.a*bC.b;
    
    return c;

    
    
}

graph:: ComplexNumber graph:: recursivePowersvalue(ComplexNumber left, ComplexNumber right, int height, ComplexNumber f){
   
    
    if(height==0){
        
        return left;
        
    }
    if(height==1){
        return   left=extendedRaisedTo(left, f);
    }
    
    
    return extendedRaisedTo(left, recursivePowersvalue(left, left, height-1, f));
    
}

double graph:: bifrication(double a, double b, int count, double r, int x, int y){
    
    a= abs(a);
    if(count==100){
        return a;
        
    }
    else if(count>50){

        matrix.at(x).at(y).b=count;

   
        matrix.at(x).at(y).r=0;


        matrix.at(x).at(y).g=0;
        
        
    }
    a=r*a*((double)1-a);
    return bifrication(a, a, count+1, r, x, y);
    
    
}

graph:: ComplexNumber graph:: extendedRaisedTo(ComplexNumber a, ComplexNumber b){
// exp{𝑧(ln𝑟+𝑖𝜃)}⋅exp{2𝑖𝑘𝜋⋅𝑧}(⋆)
    
    ComplexNumber c(log(a.r()),0);
    
    c=multiply(b, c);
    
    ComplexNumber d(0,a.theta());
    
    d=multiply(b, d);
    
    c=add(c, d);
    
    ComplexNumber e(0,0*M_PI);
    
    e=multiply(b, e);
    
   
    c=eTo(c);
    e=eTo(e);
    
    c=multiply(c, e);
    
    return c;
    
    

    
}



graph:: ComplexNumber graph:: eTo(ComplexNumber a){
    ComplexNumber c(pow(exp(1), a.a)*cos(a.b),pow(exp(1), a.a)*sin(a.b) );
    return c;
    
}



graph:: ComplexNumber graph:: raisedTo(ComplexNumber a, double n){
    double angle= 0;
    double r= 0;

    if(a.b==0 || a.a==0){

        if(a.a==0){
            if(a.b<0){
                double num=(3/(double)2);
                double PI=M_PI;
;
                angle=PI*(num);
            }
           
            else{
                double num=(1/(double)2);
                double PI=M_PI;
                angle=M_PI*(num);

            }
        }
        
        else{
            if(a.a<0){
                angle=M_PI;
                
            }
            else{
                angle=2*M_PI;

            }
            
        }

        if(a.a==0 && a.b==0){
            r=0;

        }
        else{
            r= sqrt(pow(a.a,2)+pow(a.b,2));

        }
        
    }
    else{
         angle= atan(a.b/a.a);
         r= sqrt(pow(a.a,2)+pow(a.b,2));
    }
    
    ComplexNumber c(cos(angle*n)*pow(r,n), sin(angle*n)*pow(r,n));

    return c;
    
}

graph:: ComplexNumber graph:: add(ComplexNumber aC, ComplexNumber bC){
    
    ComplexNumber c(aC.a+bC.a, aC.b+bC.b);
    return c;
    
}
double graph:: teteration(ComplexNumber left, ComplexNumber right){
    
        right=recursivePowersvalue(left, right, 100, left);
        
        ComplexNumber f(-1,0);
        ComplexNumber rNeg=multiply(right, f);

    left.a=abs(left.a);
    left.b=abs(left.b);
    
    right.a=abs(right.a);
    right.b=abs(right.b);

    ComplexNumber zero(0,0);

        ComplexNumber difference= add(right, left);
        
//    cout<<"These are you complex numbers: " << left.a <<" "<<left.b<<endl;
//    cout<< "These are the results: "<<right.a<<right.b<<endl;
//    cout<< "This is teh difference: "<<difference.a + difference.b<<endl;

    
    double re=sqrt(pow(abs(right.a),2)+pow(abs(right.b),2));
            if(re<255)
                return re;
        
        
        
    return 0;
    
}

double graph:: value(ComplexNumber left, ComplexNumber right, int count){
   
//    double d=pow(x,2)+pow(y,2);
   // return 3*sin(x)+3*cos(y)+x;
    
//    ComplexNumber c(4,5);
//    c=returnSquare(c);
   // cout<<c.a<<" "<<c.b<<endl;
    
    
    if(count==1000){
        return 0;
    }
    else if(left.a>=1000 || left.b>=1000){
//        cout<<left.b<<endl;
//        cout<<count<<endl;


        return count;
    }
    
    
//    ComplexNumber leftNegative(0,0);
//    leftNegative.a=-1*left.a;
//    leftNegative.b=-1*left.b;
//    ComplexNumber d((1/(double)2),0);
    ComplexNumber square=raisedTo(left, 2);
   // square=multiply(square, left);
    square= add(square, right);
    count= count+1;

    
    return value(square, right, count);
    
    
    
        
    
    
}


double graph:: valueWithAngle(double x, double y, double val){
    double xdotx=4;
    double ydoty=5;
    double zdotz=-1*(((5*xNormal+4*yNormal)+dNormal)/zNormal);
    return 5;
    
}

double graph:: chaoticExponentiation(ComplexNumber a, ComplexNumber b, int count){
    
    
    if(count==300){
        cout<<a.r()<<endl;

        return a.r();
    }
   
    
    ComplexNumber e= extendedRaisedTo(a, a);
    return chaoticExponentiation(e, e, count+1);
    
     
    
}
void graph:: recursiveUpdate(double x, double y, double scaling, double c){
    
   
            double val;
            double x_m=(((m_width/2))/scaling)-(x/scaling);
            double y_m=(((m_height/2))/scaling)-(y/scaling);
   

    
    ComplexNumber right(x_m, y_m);
    ComplexNumber left(0.5,0);
    val=teteration(right, right);
            //val=chaoticExponentiation(right, right, 0);
           //val=sqrt(pow(val,2)+pow(x_m,2)+pow(y_m,2));
    vr.push_back(val);
    //cout<<x_m<<" "<<y_m<<endl;

    if(val==0){
     
        
        matrix.at(x).at(y).b=0;
        matrix.at(x).at(y).r=0;
        xC.push_back(x_m);

        matrix.at(x).at(y).g=0;
        yC.push_back(y_m);
        
       

    }
    else{
//        if(pow(abs(val),2)>255){
//            matrix.at(x).at(y).b=255;
//
//        }
//        else{
            matrix.at(x).at(y).b=abs(log(abs(val)))*255;

        //}

//        if(pow(abs(val),2)>255){
//            matrix.at(x).at(y).r=255;
//
//        }
//        else{
            matrix.at(x).at(y).r=(pow(val,val))*255;

       // }

//        if(pow(abs(val),2)>255){
//            matrix.at(x).at(y).g=255;
//
//        }
        //else{
            matrix.at(x).at(y).g=val*255;
        //cout<<x_m<<endl;

//        if(abs(x_m-1)<0.001){
//            matrix.at(x).at(y).b=255;
//
//        //}
//
////        if(pow(abs(val),2)>255){
////            matrix.at(x).at(y).r=255;
////
////        }
////        else{
//            matrix.at(x).at(y).r=255;
//
//       // }
//
////        if(pow(abs(val),2)>255){
////            matrix.at(x).at(y).g=255;
////
////        }
//        //else{
//            matrix.at(x).at(y).g=255;
//        }
//

        }
        yC.push_back(y_m);
    
            

    
            
        
}

void graph:: updateGraph(int count, string path){
  
   
    
    double countLoop=50    ;
    
    int co=0;
    double part=0;
    //while(part<=1.5){
//        countLoop=countLoop+250000;

        ofstream file(path);
        ostringstream number;
        number<<co;
        path=number.str();
        path=path+".ppm";
        
      if(!file.is_open() ){
          cout<<"the file is closed"<<endl;
          return;
      }
     

      string line;
      file<<"P3"<<endl;
      file<<"#WORD"<<endl;
      file<<m_width<<" "<<m_height<<endl;
      file<<255<<endl;
    
    int cm=0;
    for(int i=0; i<m_height; i++){
        for(int w=0; w<m_width ; w++){
            recursiveUpdate(i, w, countLoop, part);
          
        }
    }
        
        
//    double f= *max_element(vr.begin(), vr.end());
//    double min=*min_element(vr.begin(), vr.end());
//
//    double fX= *max_element(xC.begin(), xC.end());
//    double minX=*min_element(xC.begin(), xC.end());
//
//    double fY= *max_element(yC.begin(), yC.end());
//    double minY=*min_element(yC.begin(), yC.end());
    
//    double range=f-min;
//    double rangeX=fX-minX;
//    double rangeY=fY-minY;
    


  
    
    int c=0;
      for(int i=0; i<(m_height); i++){
          for(int w=0; w<m_width; w++ ){
//
//              if( matrix.at(i).at(w).r==0 &&  matrix.at(i).at(w).g==0 &&matrix.at(i).at(w).b==0)
//              {
//
//              }
//              else{
//                  matrix.at(i).at(w).r= ((matrix.at(i).at(w).r-minX)/rangeX)*255;
//                  matrix.at(i).at(w).g= ((matrix.at(i).at(w).r-minY)/rangeY)*255;
//                  matrix.at(i).at(w).b= ((matrix.at(i).at(w).b-min)/range)*255;
//              }
//

              if(c==2){
                  file<<" "<<endl;
                  c=0;
              }
                  file<<" "<<(int)matrix.at(i).at(w).r;
             // cout<<matrix.at(i).at(w).r<<endl;

                 file<<" "<<(int)matrix.at(i).at(w).g;
              
              
                file<<" "<<(int)matrix.at(i).at(w).b;
                  //file<<endl;


              
              c++;
             
//              if(w==m_width-1){
//                  file<< matrix.at(i).at(w).b;
//              }
//              else{
//                  file<<matrix.at(i).at(w).b<<" ";
//              }
//

          }
          
         if(i==m_width-1 ){
             file<<" "<<endl;
          }
          
//          if(i==m_width-1){
//
//          }
//          else{
//              file<<endl;
//          }
         
      }
    
      file.close();
        
        co++;
        part=part+0.1;
    //}
//    }
}
