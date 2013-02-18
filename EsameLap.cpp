#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Ellipse {
      protected:
             float a,b;
      public:
             Ellipse(float _a, float _b);
             friend ostream& operator<<(ostream& std, Ellipse& e);
             friend Ellipse& operator*=(Ellipse& e, float c);
             friend Ellipse& operator*=(Ellipse& e, double c);      
             virtual double area();
};

Ellipse::Ellipse(float _a, float _b) {
      a = _a;
      b = _b;               
}

double Ellipse::area() {
      return 3.14f*a*b;          
}

Ellipse& operator*=(Ellipse& e, float c) {
      e.a *= c;
      e.b *= c;  
      return e;
}

Ellipse& operator*=(Ellipse& e, double c) {
      e.a *= c;
      e.b *= c;  
      return e;
}

ostream& operator<<(ostream& std, Ellipse& e) {
      std << "asse maggiore " << e.a << " asse minore " << e.b << endl;  
      return std;        
}


class Circle : public Ellipse {
      protected:
             float raggio;
      public:  
             Circle(float _a);
             friend ostream& operator<<(ostream& std, Circle& e);
             friend Circle& operator*=(Circle& e, float c);
             friend Circle& operator*=(Circle& e, double c);      
             double area();                
};

Circle::Circle(float _a) : Ellipse(_a,_a) {
      raggio = _a;
}

double Circle::area() {
      return 3.14f*pow(raggio,2);    
}

Circle& operator*=(Circle& e, float c) {
      e.raggio *= c;
      return e;
}

Circle& operator*=(Circle& e, double c) {
      e.raggio *= c;
      return e;
}

ostream& operator<<(ostream& std, Circle& e) {
      std << "Raggio " << e.a << endl;  
      return std;        
}

class Arc : public Circle {
      protected:
             float angolo;
      public:       
             Arc(float _raggio, float _angolo);
             friend ostream& operator<<(ostream& std, Arc& e);
             friend Arc& operator*=(Arc& e, float c);
             friend Arc& operator*=(Arc& e, double c);      
             double area();                
};

Arc::Arc(float _raggio, float _angolo) : Circle(_raggio) {
    angolo = _angolo;           
}

double Arc::area() {
      return 3.14f*pow(raggio,2)*(angolo/360);      
}

Arc& operator*=(Arc& e, float c) {
      e.angolo *= c;
      return e;
}

Arc& operator*=(Arc& e, double c) {
      e.angolo *= c;
      return e;
}

ostream& operator<<(ostream& std, Arc& e) {
      std << "Settore circolare: " << e.angolo << endl << endl;  
      return std;        
}

void print(Ellipse* c) {
     cout << *c << "Area " << c->area() << endl;     
}

int main()
{
     Arc * a = new Arc(20.0f, 1.5f);
     Ellipse * e = new Ellipse(2.1f, 3.5f);
     Circle * c = new Circle(3.0f);
     
     print(e);
     print(c);
     print(a);
     
     *a *= 1.5f;
     *c *= 2.0f;
     *e *= 2.5f;
     
     print(e);
     print(c);
     print(a);
     
     *a *= 0.5;
     *c *= 0.5;
     *e *= 0.5;
     
     print(e);
     print(c);
     print(a);
     
     system("pause");
     
     return 0;     
}
