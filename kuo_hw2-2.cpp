#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial
{

public:
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
}; // end class Polynomial

#endif

///////////////////////////////
#include<iostream>
#include<cmath>
// #include"10993.h"
using namespace std;

Polynomial::Polynomial()
{
    greatestPower = 0;
    for(int i = 0; i < 51; i++) coefficients[i] = 0;
}
Polynomial::Polynomial(const int grtPow, const int coef[51])
{
    greatestPower = grtPow;
    for(int i = 0; i < 51; i++) coefficients[i] = i <= grtPow ? coef[i] : 0;
}
Polynomial Polynomial::add( const Polynomial poly) const
{
    Polynomial newPoly;
    newPoly.greatestPower = max(greatestPower, poly.greatestPower);
    for(int i = 0; i <= newPoly.greatestPower; i++){
        newPoly.coefficients[i] = coefficients[i] + poly.coefficients[i];
    }
    /*for(int i = newPoly.greatestPower; newPoly.coefficients[i] == 0; i--){
        newPoly.greatestPower--;
    }*/
    return newPoly;
}
Polynomial Polynomial::subtract( const Polynomial poly) const{
    Polynomial newPoly;
    newPoly.greatestPower = max(greatestPower, poly.greatestPower);
    for(int i = 0; i <= newPoly.greatestPower; i++){
        newPoly.coefficients[i] = coefficients[i] - poly.coefficients[i];
    }
    for(int i = newPoly.greatestPower; newPoly.coefficients[i] == 0; i--){
        newPoly.greatestPower--;
    }
    return newPoly;
}
Polynomial Polynomial::multiplication( const Polynomial poly) const{
    Polynomial newPoly;
    newPoly.greatestPower = greatestPower + poly.greatestPower;
    for(int i = 0; i <= greatestPower; i++) for(int j = 0; j <= poly.greatestPower; j++){
        newPoly.coefficients[i + j] += coefficients[i] * poly.coefficients[j];
    }
    /*for(int i = newPoly.greatestPower; newPoly.coefficients[i] == 0; i--){
        newPoly.greatestPower--;
    }*/
    return newPoly;
}
void Polynomial::output() const{
    for(int i = greatestPower; i >= 0; i--){
        cout << coefficients[i];
        if(i != 0) cout << ' ';
    }
}
/////////////////////////////////
using namespace std;

int main()
{
    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;

    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1), b(greatestPower2, coefficient2) ;

    ans = a.add( b );
    ans.output();
    cout << endl;

    ans = a.subtract( b );
    ans.output();
    cout << endl;

    ans = a.multiplication( b );
    ans.output();
    cout << endl;

} // end main

