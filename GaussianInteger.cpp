#include "GaussianInteger.h"
#include <iostream>
GaussianInteger::GaussianInteger(int a, int b)
{
    m_a = a;
    m_b = b;
}

int GaussianInteger::norm()
{
    return m_a*m_a + m_b*m_b;
}

int GaussianInteger::normOf(int a, int b)
{
    return a*a + b*b;
}

void GaussianInteger::multiplyBy(GaussianInteger other)
{
    int a = other.getA();
    int b = other.getB();
    multiplyBy(a,b);
}

void GaussianInteger::multiplyBy(int a, int b)
{
    int a0 = m_a;
    int b0 = m_b;
    m_a = a0*a - b0*b;
    m_b = a0*b + b0*a;
}

GaussianInteger GaussianInteger::remainderUponDivision(GaussianInteger other)
{
    GaussianInteger conjugate(other.getA(),other.getB()*-1);
    
    GaussianInteger top(m_a, m_b);
    GaussianInteger bottom(other.m_a, other.m_b);
    
    top.multiplyBy(conjugate);
    bottom.multiplyBy(conjugate);
    
    double a_frac = (double) top.m_a/bottom.m_a;
    double b_frac = (double) top.m_b/bottom.m_a;
    
    int a = round(a_frac);
    int b = round(b_frac);
    
    GaussianInteger bestOption(a,b);
    //std::cout << "Best option: " << bestOption.toString() << '\n';
    
    GaussianInteger subtracter(other.m_a, other.m_b);
    subtracter.multiplyBy(bestOption);
    
    GaussianInteger answer(m_a, m_b);
    answer.subtract(subtracter);
    
    return answer;
}

void GaussianInteger::add(GaussianInteger other)
{
    m_a += other.m_a;
    m_b += other.m_b;
}

void GaussianInteger::add(int a, int b)
{
    m_a += a;
    m_b += b;
}

void GaussianInteger::subtract(GaussianInteger other)
{
    m_a -= other.m_a;
    m_b -= other.m_b;
}

void GaussianInteger::subtract(int a, int b)
{
    m_a -= a;
    m_b -= b;
}

int GaussianInteger::getA()
{
    return m_a;
}

int GaussianInteger::getB()
{
    return m_b;
}

std::string GaussianInteger::toString()
{
    std::string output = "";
    output+=std::to_string(m_a);
    output+=" + ";
    output+=std::to_string(m_b);
    output+="i";
    return output;
}

GaussianInteger GaussianInteger::GCD(GaussianInteger other)
{
    int norm1 = norm();
    int norm2 = other.norm();
    
    //hackiest fix ever below:
    GaussianInteger g1(0,0); //temp value - I didn't feel like making another constructor
    GaussianInteger g2(0,0); //temp value
    
    if(norm1 > norm2)
    {
        GaussianInteger g1_temp(m_a, m_b);
        GaussianInteger g2_temp(other.m_a, other.m_b);
        
        g1.m_a = g1_temp.m_a; g1.m_b = g1_temp.m_b;
        g2.m_a = g2_temp.m_a; g2.m_b = g2_temp.m_b;
    }
    else
    {
        GaussianInteger g2_temp(m_a, m_b);
        GaussianInteger g1_temp(other.m_a, other.m_b);
        
        g1.m_a = g1_temp.m_a; g1.m_b = g1_temp.m_b;
        g2.m_a = g2_temp.m_a; g2.m_b = g2_temp.m_b;
    }
    
    GaussianInteger remainder = g1.remainderUponDivision(g2);
    //std::cout << "Remainder: " << remainder.toString() << '\n';
    if(remainder.m_a == 0 && remainder.m_b == 0)
        return other;
    else
    {
        //std::cout << "PASSING IN: " << other.toString() << ", " << remainder.toString() << "\n";
        return other.GCD(remainder);
    }
}

int GaussianInteger::round(double d)
{
    return (int) (floor(0.5 + d));
}
