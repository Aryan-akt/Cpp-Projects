// A fully furnished Calculator.

/*
This calculator has the following features:
-> All operations from both simple and scientific calculator.
-> Full proof error management
-> Tons of versatility
-> Domain check for every trigonometric and inverse trigonometric functions.
-> Calculator keeps running and taking input from user until "end" is entered in place of first number.
-> Good code reusability.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class simpleCalculator          // Class for mathematical operations of a simple calculator.
{
    public:                                     // Includes sum, difference, multiplication, division and remainder operations.
        double calc_sum(double, double);
        double calc_diff(double, double);
        double calc_prod(double, double);
        double calc_div(double, double);
};

double simpleCalculator :: calc_sum(double x, double y)
{
    return x + y;
}

double simpleCalculator :: calc_diff(double x, double y)
{
    return x - y;
}

double simpleCalculator :: calc_prod(double x, double y)
{
    return x * y;
}

double simpleCalculator :: calc_div(double x, double y)
{
    if(y == 0.0)
    {
        cout << "\nA number cannot be divided by zero." << endl;       // Non divisibility by zero management.
        return NAN;
    }
    else {return x / y;}
}

class scientificCalculator              // Class for mathematical operations of a scientific calculator.
{
    private:                            // Includes trigonometric and inverse trigonometric operations, logarithmic operations, square,
        double b;                       // square root, cube, x^y operations, factorial and inverse operations.
    public:

        void convert(int);
        void arc_convert(double);

        double calc_sin(double);
        double calc_cos(double);
        double calc_cosec(double);
        double calc_sec(double);
        double calc_tan(double);
        double calc_cot(double);

        double calc_arc_sin(double);
        double calc_arc_cos(double);
        double calc_arc_cosec(double);
        double calc_arc_sec(double);
        double calc_arc_tan(double);
        double calc_arc_cot(double);

        double calc_remainder(double , double);

        double calc_ln(double);
        double calc_log(double);

        double calc_sqr(double);
        double calc_sqrt(double);
        double calc_cube(double);
        double calc_cbrt(double);
        double calc_x_power_y(double, double);
        double calc_nth_root(double, int);
        long long calc_factorial(double);

        double calc_inverse(double);

        double calc_absolute_value(double);
        double calc_inv_sign(double);
};

void scientificCalculator :: convert(int d)
{
    b = d * M_PI / 180;
}

void scientificCalculator :: arc_convert(double d)
{
    b = d * 180 / M_PI;
}

double scientificCalculator :: calc_sin(double x)       // Every trigonometric function has a domain
{                                                       // check, so that to avoid any confusions.
    if(!isfinite(x))
    {
        cout << "\nSine is defined only for real numbers." << endl;
        return NAN;
    }
    convert(x);
    return sin(b);
}

double scientificCalculator :: calc_cos(double x)
{
    if(!isfinite(x))
    {
        cout << "\nCosine is defined only for real numbers." << endl;
        return NAN;
    }
    convert(x);
    return cos(b);
}

double scientificCalculator :: calc_cosec(double x)
{
    double sine = calc_sin(x);
    if(!isfinite(sine) || abs(sine) < 1e-12)
    {
        cout << "\nCo-secant is undefined when sine is zero." << endl;
        return NAN;
    }
    return 1 / sine;
}

double scientificCalculator :: calc_sec(double x)
{
    double cosine = calc_cos(x);
    if(!isfinite(cosine) || abs(cosine) < 1e-12)
    {
        cout << "\nSecant is undefined when cosine is zero." << endl;
        return NAN;
    }
    return 1 / cosine;
}

double scientificCalculator :: calc_tan(double x)
{
    double cosine = calc_cos(x);
    if(!isfinite(cosine) || abs(cosine) < 1e-12)
    {
        cout << "\nTangent is undefined when cosine is zero." << endl;
        return NAN;
    }
    convert(x);
    return tan(b);
}

double scientificCalculator :: calc_cot(double x)
{
    double sine = calc_sin(x);
    if(!isfinite(sine) || abs(sine) < 1e-12)
    {
        cout << "\nCo-tangent is undefined when sine is zero." << endl;
        return NAN;
    }
    return calc_cos(x) / sine;
}

double scientificCalculator :: calc_arc_sin(double x)           // Every inverse trigonometric function also has a
{                                                               // domain check, so that to avoid any confusions.
    if(!isfinite(x) || x < -1 || x > 1)
    {
        cout << "\nInverse sine requires a value from -1 to 1." << endl;
        return NAN;
    }
    double a = asin(x);
    arc_convert(a);
    return b;
}

double scientificCalculator :: calc_arc_cos(double x)
{
    if(!isfinite(x) || x < -1 || x > 1)
    {
        cout << "\nInverse cosine requires a value from -1 to 1." << endl;
        return NAN;
    }
    double a = acos(x);
    arc_convert(a);
    return b;
}

double scientificCalculator :: calc_arc_cosec(double x)
{
    if(!isfinite(x) || (x > -1 && x < 1) || x == 0)
    {
        cout << "\nInverse cosecant requires a value less than or equal to -1 OR greater than or equal to 1." << endl;
        return NAN;
    }
    return arc_convert(asin(1 / x)), 1 / b;
}

double scientificCalculator :: calc_arc_sec(double x)
{
    if(!isfinite(x) || (x > -1 && x < 1))
    {
        cout << "\nInverse secant requires a value less than or equal to -1 OR greater than or equal to 1." << endl;
        return NAN;
    }
    return arc_convert(acos(1 / x)), 1 / b;
}

double scientificCalculator :: calc_arc_tan(double x)
{
    if(!isfinite(x))
    {
        cout << "\nInverse tangent is defined only for real numbers." << endl;
        return NAN;
    }
    double a = atan(x);
    arc_convert(a);
    return b;
}

double scientificCalculator :: calc_arc_cot(double x)
{
    if(!isfinite(x))
    {
        cout << "\nInverse co-tangent is defined only for real numbers." << endl;
        return NAN;
    }
    arc_convert(atan2(1.0, x));
    return b;
}


double scientificCalculator :: calc_remainder(double x, double y)
{
    if(y == 0.0)
    {
        cout << "\nA number cannot be divided by zero." << endl;       // Non divisibility by zero management.
        return NAN;
    }
    else {return fmod(x, y);}
}

double scientificCalculator :: calc_ln(double x)
{
    if(x < 0)
    {
        cout << "\nLogarithm of negative numbers is not possible. " << endl;       // Prevents error for ln of negative numbers.
        return 0;
    }
    else{
        return log(x);
    }
}

double scientificCalculator :: calc_log(double x)
{
    if(x < 0)
    {
        cout << "\nLogarithm of negative numbers is not possible. " << endl;       // Prevents error for log of negative numbers.
        return 0;
    }
    else
    {
        return log10(x);
    }
}

double scientificCalculator :: calc_sqr(double x)
{
    return x * x;
}

double scientificCalculator :: calc_sqrt(double x)
{
    return sqrt(x);
}

double scientificCalculator :: calc_x_power_y(double x, double y)
{
    return pow(x, y);
}

double scientificCalculator :: calc_nth_root(double x, int y)
{
    if(y % 2 == 0 && x < 0)
    {
        cout << "Even root of a negative number is an imaginary number, please enter a valid combination of numbers." << endl;
        return NAN;
    }
    if(x < 0)
    {
        return -pow(abs(x), 1.0 / y);
    }
    return pow(x, 1.0 / y);
}

double scientificCalculator :: calc_cube(double x)
{
    return pow(x, 3);
}

double scientificCalculator :: calc_cbrt(double x)
{
    return cbrt(x);
}

long long scientificCalculator :: calc_factorial(double x)
{
    string strx = to_string(x);

    for(int i = 0; i < strx.length(); i++)          // Checks if the entered number is negative.
    {
        if(strx.at(i) == '-')
        {
            cout << "\nPlease enter a positive number and try again." << endl;
            break;
        }
    }

    if(floor(x) != x)           // Checks if the entered number is non interger.
    {
        cout << "\nPlease enter an integer and try again." << endl;
        return 0;
    }
    else if(x < 0) {return 0;}
    else if(x <= 1) {return 1;}
    else{
            return x * calc_factorial(x-1);         // Recursion
        }
}

double scientificCalculator :: calc_inverse(double x)
{
    return 1 / x;
}

double scientificCalculator :: calc_absolute_value(double x)
{
    return abs(x);
}

double scientificCalculator :: calc_inv_sign(double x)
{
    return -x;
}

class Calculator : public simpleCalculator, public scientificCalculator     // Hybrid class made using multiple inheritance.
{

};

int main() {

    Calculator c;

    for (int i = 0; 2 < 3; i++)        // This 'for' loop keeps the main function running infinitly, so that the user
    {                                  // does not require to open the application repeatedly to use the calculator again.
        double d1, d2;
        string x, s;

            cout << "\nEnter first number (or 'end' to quit): " << endl;
            cin >> x;

        if(x == "end")          // If the user enters "end" as the first number, the program will terminate and close the application.
        {
            exit(0);
        }
        else
        {
            d1 = stod(x);          // Converts string to double, which can be used in functions for calculating.

            cout << "\nEnter the mathematical operation: " << endl;
            cin >> s;

            // This calculator can identify different alias used for the same function (eg: square/^2).
            
            if(s == "+" || s == "add" || s == "Add" || s == "sum" || s == "Sum" || s == "plus" || s == "Plus")
            {
                cout << "\nEnter the number to be added: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_sum(d1, d2) << endl;
            }

            else if(s == "-" || s == "minus" || s == "Minus" || s == "subtract" || s == "Subtract")
            {
                cout << "\nEnter the number to be subtracted: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_diff(d1, d2) << endl;
            }

            else if(s == "*" || s == "multiply" || s == "Multiply")
            {
                cout << "\nEnter the number to be multiplied with: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_prod(d1, d2) << endl;
            }

            else if(s == "/" || s == "divide" || s == "Divide")
            {
                cout << "\nEnter the number to be divided with: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_div(d1, d2) << endl;
            }

            else if(s == "%" || s == "remainder" || s == "Remainder")
            {
                cout << "\nEnter the number to be divided with to get remainder: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_remainder(d1, d2) << endl;
            }

            else if(s == "sin" || s == "Sin")
            {
                cout << "\nSolution: " << c.calc_sin(d1) << endl;
            }

            else if(s == "cos" || s == "Cos")
            {
                cout << "\nSolution: " << c.calc_cos(d1) << endl;
            }

            else if(s == "cosec" || s == "Cosec")
            {
                cout << "\nSolution: " << c.calc_cosec(d1) << endl;
            }

            else if(s == "sec" || s == "Sec")
            {
                cout << "\nSolution: " << c.calc_sec(d1) << endl;
            }

            else if(s == "tan" || s == "Tan")
            {
                cout << "\nSolution: " << c.calc_tan(d1) << endl;
            }

            else if(s == "cot" || s == "Cot")
            {
                cout << "\nSolution: " << c.calc_cot(d1) << endl;
            }

            else if(s == "inverse_sin" || s == "Inverse_sin" || s == "inverse-sin" || s == "Inverse-sin" ||
                    s == "arc_sin" || s == "Arc_sin" || s == "arc-sin" || s == "Arc-sin")
            {
                cout << "\nSolution: " << c.calc_arc_sin(d1) << endl;
            }

            else if(s == "inverse_cos" || s == "Inverse_cos" || s == "inverse-cos" || s == "Inverse-cos" ||
                    s == "arc_cos" || s == "Arc_cos" || s == "arc-cos" || s == "Arc-cos")
            {
                cout << "\nSolution: " << c.calc_arc_cos(d1) << endl;
            }

            else if(s == "inverse_cosec" || s == "Inverse_cosec" || s == "inverse-cosec" || s == "Inverse-cosec" ||
                    s == "arc_cosec" || s == "Arc_cosec" || s == "arc-cosec" || s == "Arc-cosec")
            {
                cout << "\nSolution: " << c.calc_arc_cosec(d1) << endl;
            }

            else if(s == "inverse_sec" || s == "Inverse_sec" || s == "inverse-sec" || s == "Inverse-sec" ||
                    s == "arc_sec" || s == "Arc_sec" || s == "arc-sec" || s == "Arc-sec")
            {
                cout << "\nSolution: " << c.calc_arc_sec(d1) << endl;
            }

            else if(s == "inverse_tan" || s == "Inverse_tan" || s == "inverse-tan" || s == "Inverse-tan" ||
                    s == "arc_tan" || s == "Arc_tan" || s == "arc-tan" || s == "Arc-tan")
            {
                cout << "\nSolution: " << c.calc_arc_tan(d1) << endl;
            }

            else if(s == "inverse_cot" || s == "Inverse_cot" || s == "inverse-cot" || s == "Inverse-cot" ||
                    s == "arc_cot" || s == "Arc_cot" || s == "arc-cot" || s == "Arc-cot")
            {
                cout << "\nSolution: " << c.calc_arc_cot(d1) << endl;
            }

            else if(s == "!" || s == "factorial" || s == "Factorial")
            {
                cout << "\nSolution: " << c.calc_factorial(d1) << endl;
            }

            else if(s == "inverse" || s == "Inverse" || s == "^-1")
            {
                cout << "\nSolution: " << c.calc_inverse(d1) << endl;
            }
            
            else if(s == "square_root" || s == "Square_Root" || s == "Square_root" || s == "^1/2" ||
                    s == "square-root" || s == "Square-Root" || s == "Square-root")
            {
                cout << "\nSolution: " << c.calc_sqrt(d1) << endl;
            }

            else if(s == "square" || s == "Square" || s == "^2")
            {
                cout << "\nSolution: " << c.calc_sqr(d1) << endl;
            }

            else if(s == "ln" || s == "natural_log" || s == "Natural_log" || s == "log_to_the_base_e" ||
                    s == "natural-log" || s == "Natural-log" || s == "log-to-the-base-e")
            {
                cout << "\nSolution: " << c.calc_ln(d1) << endl;
            }

            else if(s == "log" || s == "Log" || s == "log_to_the_base_10" || s == "log-to-the-base-10")
            {
                cout << "\nSolution: " << c.calc_log(d1) << endl;
            }

            else if(s == "cube" || s == "Cube" || s == "^3")
            {
                cout << "\nSolution: " << c.calc_cube(d1) << endl;
            }

            else if(s == "cube_root" || s == "Cube_root" || s == "^1/3" || s == "cube-root" || s == "Cube-root")
            {
                cout << "\nSolution: " << c.calc_cbrt(d1) << endl;
            }

            else if(s == "^" || s == "to-the-power" || s == "to_the_power" || s == "raise-to" || s == "raise_to" ||
                    s == "To-the-power" || s == "To_the_power" || s == "Raise-to" || s == "Raise_to")
            {
                cout << "\nEnter the exponent: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_x_power_y(d1, d2) << endl;
            }

            else if(s == "nth_root" || s == "nth-root" || s == "^1/n"|| s == "to-the-power-^1/n" || s == "to_the_power_^1/n" ||
                    s == "raise-to-^1/n" || s == "raise_to_^1/n" || s == "To-the-power-^1/n" || s == "To_the_power_^1/n" ||
                    s == "Raise-to-^1/n" || s == "Raise_to_^1/n")
            {
                cout << "\nEnter n: " << endl;
                cin >> d2;
                cout << "\nSolution: " << c.calc_nth_root(d1, d2) << endl;
            }

            else if(s == "absolute_value" || s == "Absolute_value" || s == "absolute-value" || s == "Absolute-value")
            {
                cout << "\nSolution: " << c.calc_absolute_value(d1) << endl;
            }
            
            else if(s == "inv-sign" || s == "inv_sign" || s == "Inv-sign" || s == "Inv_sign")
            {
                cout << "\nSolution: " << c.calc_inv_sign(d1) << endl;
            }

            else{cout << "Invalid mathematical operation entered, please try again." << endl;}
        }
    }

    return 0;
}
