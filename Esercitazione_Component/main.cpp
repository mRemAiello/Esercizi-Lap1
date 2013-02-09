#include <cstdlib>
#include <iostream>
#include "Component.cpp"

using namespace std;

template <class T>
Component<T>::Component(string _type, string _name, string _measure_unit, T _value)
{
	type = _type;
	name = _name;
	measure_unit = _measure_unit;
	value = _value;
}

template <class T>
ostream &operator<<(ostream &out, Component<T> &c)
{
	out << "Name: " << c.getName() << "; Type: " << c.getType() << "; Measure Unit: " << c.getMeasureUnit() << "; Value: " << c.getValue() << ";" << endl;
	
	return out;
}

Resistor::Resistor(string n, string m, float v) : Component<float>("Resistor", n, m, v)	{}
Capacitor::Capacitor(string n, string m, float v) : Component<float>("Capacitor", n, m, v)	{}
Transistor::Transistor(string n, string m, string v) : Component<string>("Transistor", n, m, v)	{}

int main()
{
    Resistor *r = new Resistor("myResistor", "myMeasureUnit", 20);
	Capacitor *c = new Capacitor("myCapacitor", "myMeasureUnit", 40);
	Transistor *t = new Transistor("myTransistor", "myMeasureUnit", "myValue");
	
	cout << *r << endl;
	cout << *c << endl;
	cout << *t << endl;
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
