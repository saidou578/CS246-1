/**********************************************************
 * Lecture 02: Inheritance and Polymorphism
 * File: Exception.h
 * Description: An exception is an problem that occurs
 * during the execution of a program. Exceptions are 
 * readonly classes.
 *********************************************************/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>
#include <sstream>

class Exception 
{
private: 
    std::string msg;
    std::string file;
    int line;

    /****************************************
     * Make the default constructor private
     * so that an error will occur if used.
     ***************************************/ 
    Exception();
public: 
    Exception(std::string msg,std::string file,int line) : msg(msg), file(file), line(line) { }

    Exception(const Exception& obj)
    {
        msg = obj.msg;
        file = obj.file;
        line = obj.line;
    }

    Exception& operator=(const Exception& rhs)
    {
        if(this != &rhs)
        {
            msg = rhs.msg;
            file = rhs.file;
            line = rhs.line;
        }

        return *this;
    }

    ~Exception() {}

    //Get Methods Only
    int GetLine() const {return line;}

    std::string GetFile() const { return file; }

    std::string GetMsg() const { return msg; } 

    std::string ToString() const
    {
        std::stringstream out;

        out << msg << " error occurred in " << file << " on line " << line;
        return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out,const Exception& obj)
    {
        out << obj.ToString();
        return out;
    }
};

/***************************************************************************
 * Derived Classes
 * Derived classes (or children classes) are classes that inherits the 
 * fields and methods of another class (or multiple classes) called a base 
 * class (or parent class). A derive class has direct access only to the 
 * fields and methods of the base class that have either public or protected 
 * access. Furthermore, a derive class can inherit a base class either 
 * publicly, privately or protected. The way the derive class inherits the 
 * base class indicates how the field and methods of the base class are 
 * accessed through the derive class. Constructors, the destructor, the
 * other special member functions and friends are not inherited by the 
 * derive class.
 **************************************************************************/

/*Public Inheritance*/
class DivideByZeroException : public Exception
{
private:
    DivideByZeroException();
public:
    /*Initializing the fields of Exception by
    calling the Exception constructor with the
    member initialization list*/
    DivideByZeroException(std::string file,int line) : Exception("Divide by zero",file,line) {}

    /*Upcasting*/
    DivideByZeroException(const DivideByZeroException& obj) : Exception(dynamic_cast<const Exception&>(obj)) {}

    DivideByZeroException& operator=(const DivideByZeroException& rhs)
    {
        if(this != &rhs)
        {
            //Explicit assignment operator call 
            Exception::operator=(dynamic_cast<const Exception&>(rhs));
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out,const DivideByZeroException& obj)
    {
        out << obj.ToString();
        return out;
    }
};

/*Protected Inheritance*/
class OverflowException : protected Exception
{
private:
    OverflowException();
public:
    /*Initializing the fields of Exception by
    calling the Exception constructor with the
    member initialization list*/
    OverflowException(std::string file,int line) : Exception("Overflow",file,line) {}

    /*Upcasting*/
    OverflowException(const OverflowException& obj) : Exception(dynamic_cast<const Exception&>(obj)) {}

    OverflowException& operator=(const OverflowException& rhs)
    {
        if(this != &rhs)
        {
            //Explicit assignment operator call 
            Exception::operator=(dynamic_cast<const Exception&>(rhs));
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out,const OverflowException& obj)
    {
        out << obj.ToString();
        return out;
    }
};

/*Protected Inheritance*/
class UnderflowException : private Exception
{
private:
    UnderflowException();
public:
    /*Initializing the fields of Exception by
    calling the Exception constructor with the
    member initialization list*/
    UnderflowException(std::string file,int line) : Exception("Underflow",file,line) {}

    /*Upcasting*/
    UnderflowException(const UnderflowException& obj) : Exception(dynamic_cast<const Exception&>(obj)) {}

    UnderflowException& operator=(const UnderflowException& rhs)
    {
        if(this != &rhs)
        {
            //Explicit assignment operator call 
            Exception::operator=(dynamic_cast<const Exception&>(rhs));
        }
        return *this;
    }

    /*Overridden Method
    std::string ToString() const
    {
        return Exception::ToString() + " (new)";
    } 
    */

    friend std::ostream& operator<<(std::ostream& out,const UnderflowException& obj)
    {
        out << obj.ToString();
        return out;
    }
};

#endif 