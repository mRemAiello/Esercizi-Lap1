#include <iostream>

using namespace std;

template <class T> class Component {
    string type, name, measure_unit;
    T value;
    
    public:
        Component(string _type, string _name, string _measure_unit, T _value);
        
        string getType() { return type; }
        string getName() { return name; }
        string getMeasureUnit() { return measure_unit; }
        T getValue() { return value; }
        
        void setName(const string& n)			{ name = n; }
        void setType(const string& n)			{ type = n; }
        void setMeasureUnit(const string& n)	{ measure_unit = n; }
        T setValue(const T& n)			        { value = n; }
};

template <class T>
ostream &operator<<(ostream &out, Component<T> &c);

class Resistor : public Component<float> {
    public:
	   Resistor(string n, string m, float v);
};

class Capacitor : public Component<float> {
    public:
	   Capacitor(string n, string m, float v);
};

class Transistor : public Component<string> {
    public:
	   Transistor(string n, string m, string v);
};

/** END DECLARATION CLASSES **/
