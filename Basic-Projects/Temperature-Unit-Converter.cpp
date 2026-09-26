// A unit converter for temperature.

#include <iostream>
#include <windows.h>        // This is included to successfully print the "°" symbol in the output.
using namespace std;

class temperature
{
    float k, f, c;

    public:
        void k_f(float);
        void f_c(float);
        void c_f(float);
        void f_k(float);
        void k_c(float);
        void c_k(float);
};

void temperature :: k_f(float x)
{
    f = (x - 273.15) * (9.0/5.0) + 32.0;
    cout << "Value of " << x << " K in Farenheit is " << f << " °F" << endl;
}

void temperature :: f_c(float x)
{
    c = (x - 32.0) * 5.0/9.0;
    cout << "Value of " << x << " °F in Celcius is " << c << " °C" << endl;
}

void temperature :: c_f(float x)
{
    f = x * (9.0/5.0) + 32.0;
    cout << "Value of " << x << " °C in Farenheit is " << f << " °F" << endl;
}

void temperature :: f_k(float x)
{
    k = (x - 32.0) * 5.0/9.0 + 273.15;
    cout << "Value of " << x << " °F in Kelvin is " << k << " K" << endl;
}

void temperature :: k_c(float x)
{
    c = x - 273.15;
    cout << "Value of " << x << " K in Celcius is " << c << " °C" << endl;
}

void temperature :: c_k(float x)
{
    k = x + 273.15;
    cout << "Value of " << x << " °C in Kelvin is " << k << " K" << endl;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);        // This uses the <window.h> to successfully print "°" symbol.

    temperature temp;
    float t;
    string s;

    cout << "Enter the magnitude of temperature" << endl;
    cin >> t;

    cout << "Enter the unit of temperature" << endl;
    cin >> s;

    if(s == "K" || s == "kelvins")
    {
        temp.k_c(t);
        temp.k_f(t);
    }
    else if(s == "°F" || s == "Farenheit")
    {
        temp.f_c(t);
        temp.f_k(t);
    }
    else if(s == "°C" || s == "Celcius")
    {
        temp.c_f(t);
        temp.c_k(t);
    }
    else{cout << "Invalid unit entered. Please enter any one of 'K', '°F' or '°C' units";}

    return 0;
}