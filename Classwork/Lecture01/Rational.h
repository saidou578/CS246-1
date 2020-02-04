/**********************************************************
 * Lecture 01: Abstraction And Encapsulation
 * File: Rational.h
 * Description: A rational number is a number that can 
 * be written as a fraction with numerator and 
 * denominator both integers except that denominator 
 * cannot equal zero. Likewise, a rational number is a 
 * decimal that either repeats or terminates.
 *********************************************************/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <string>
#include <sstream>

class Rational 
{
//Private Fields and Methods
private: //Private Access Specifier
    int num;
    int dem;
    bool sign;
    static int COUNT;

    int abs(int n)
    {
        return ((n < 0)?(-1 * n):(n));
    }

    int gcd(int m,int n)
    {
        int r;

        while(n != 0)
        {
            r = m % n;
            m = n;
            n = r;
        }

        return m;
    }

    void format()
    {
        if(dem == 0)
        {
            throw "Denominator cannot be zero";
        }

        sign = (num * dem >= 0);
        num = abs(num);
        dem = abs(dem);
    }

//Public Methods
public: //Public Access Specifier
    /*Default Constructor that uses the 
    member initialization list to initialize
    the field*/
    Rational() : num(1), dem(1), sign(true) {COUNT += 1;}

    /*Overloaded Construtor that uses the
    member initialization list to call 
    another constructor to initialize the 
    fields*/
    Rational(int num) :  Rational(num,1) {}

    /*Overloaded Constructor that takes 
    two int parameters*/
    Rational(int num,int dem)
    {
        /*using this pointer to distinguish betweeen 
        parameter and field. It is unnecessary if 
        the names are not ambiguous. Fields that 
        can be referenced with the this pointer
        are called instance fields; they are unique
        for every object of the class*/
        this->num = num; 
        this->dem = dem;
        format();
        COUNT += 1;
    }

    /*Copy Constructor*/
    Rational(const Rational& obj) 
    {
        num = obj.num;
        dem = obj.dem;
        sign = obj.sign;
        COUNT += 1;
    }

    /*Overloaded Assignment Operator*/
    Rational& operator=(const Rational& rhs)
    {
        /*It is always similar to the copy constructor.
        You typically make sure you are not doing 
        anything when you are assigning an object to
        itself*/

        if(this != &rhs)
        {
            num = rhs.num;
            dem = rhs.dem;
            sign = rhs.sign;
        }

        //Always returns a reference of the class
        return *this;
    }

    /*Destructor*/
    ~Rational() {COUNT -= 1;}

    /*Get Methods. They are field read access methods*/
    int GetNumerator() 
    {
        return ((sign)?(num):(-1 * num));
    }

    int GetNumerator() const 
    {
        return ((sign)?(num):(-1 * num));
    }

    int GetDenominator() 
    {
        return dem;
    }

    int GetDenominator() const 
    {
        return dem;
    }

    /*Static Method*/
    static int GetCount() 
    {
        return COUNT;
    }

    /*Set Methods. They are field write access methods.
    These methods do not have constant versions*/
    void SetNumerator(int value)
    {
        sign = (value * dem >= 0);
        num = abs(value);
    }

    void SetDenominator(int value)
    {
        if(value == 0)
        {
            throw "Denominator cannot be zero";
        }
        sign = (num * value >= 0);
        dem = abs(value);
    }

    /*ToString() method. Used to create a string format 
    of the output of the object*/
    std::string ToString() const
    {
        std::stringstream out;

        if(!sign)
        {
            out << "-" << num;
        }
        else
        {
            out << num;
        }

        if(dem > 1 && num != 0)
        {
            out << "/" << dem;
        }
    
        return out.str();
    }

    /*Overloaded Ostream Operator. It must be a friend function*/
    friend std::ostream& operator<<(std::ostream& out,const Rational& obj)
    {
        out << obj.ToString();
        return out;
    }

    /*Define yourself*/
    void Reduce();
};

int Rational::COUNT = 0;

#endif 