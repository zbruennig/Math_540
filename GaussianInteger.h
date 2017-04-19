//Code written for MATH 540: Elementary Number Theory
//Goal: Prove or disprove (by counterexample) if GCD(a+bi,a-bi) = +-i,1 for all a,b =/= 0

#ifndef GAUSSIAN_INTEGER_H
#define GAUSSIAN_INTEGER_H

#include <string>
#include <math.h>

class GaussianInteger
{
private:
    int m_a;
    int m_b;
    const int MAX_ITERATIONS = 100;
    
    int round(double d);
public:
    GaussianInteger(int a, int b);
    
    int norm();
    int normOf(int a, int b);
    
    void multiplyBy(GaussianInteger other);
    void multiplyBy(int a, int b);
    
    void add(GaussianInteger other);
    void add(int a, int b);
    
    void subtract(GaussianInteger other);
    void subtract(int a, int b);
    
    GaussianInteger remainderUponDivision(GaussianInteger other);
    
    int getA();
    int getB();
    
    GaussianInteger GCD(GaussianInteger other);
    
    std::string toString();
};
#endif
