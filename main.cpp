//main.cpp

#include "GaussianInteger.h"
#include <iostream>
#include <string>
#include <fstream>

int min(int a, int b)
{
    if(a>b)
        return b;
    return a;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int gcd(int a, int b)
{
    int x = max(a,b);
    int y = min(a,b);
    
    int r = x%y;
    if(r==0)
        return y;
    else
        return gcd(y,r);
}

int main(int argc, char** argv)
{
    const int R = 100;
    const int C = 100;
    int values[R][C];
    
    //initialize output array
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<R; j++)
            values[i][j] = 0;
    }
    
    /*GaussianInteger plus(3,17);
    GaussianInteger minus(3,-17);
    
    GaussianInteger gcd = plus.GCD(minus);
    std::cout << gcd.toString();*/
    
    //computation
    for(int a = 1; a<R; a++)
    {
        for(int b = 1; b<C; b++)
        {
            GaussianInteger plus(a,b);
            GaussianInteger minus(a,b*-1);
            GaussianInteger divisor = plus.GCD(minus);
            //if(divisor.norm() != 1) // output1.txt
            //if(divisor.norm() != 1 && divisor.getA() != 0 && divisor.getB() != 0) //output2.txt
            if(divisor.norm() != 1 && divisor.getA() != 0 && divisor.getB() != 0 
                && gcd(divisor.getA(), divisor.getB())==1) //output3.txt
            {
                values[a][b] = 1;
                std::cout << a << ", " << b << '\n';
                std::cout << divisor.getA() << " + " << divisor.getB() << "i\n\n";
            }
        }
    }
    
    //print to screen
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<R; j++)
        {
            if(values[i][j] == 0)
                std::cout << " ";
            if(values[i][j] == 1)
                std::cout << "*";
        }
        std::cout << "\n";
    }
    
    //file output
    if(argc > 1)
    {
        std::string file = argv[1];
        std::ofstream out;
        out.open(file);
        
        for(int i=1; i<R; i++)
        {
            for(int j=1; j<R; j++)
            {
                if(values[i][j] == 0)
                    out << " ";
                if(values[i][j] == 1)
                    out << "*";
            }
            out << "\n";
        }
    }
    
    return 0;
}
