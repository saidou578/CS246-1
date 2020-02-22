#include <iostream>

/**************************
 * IsLower()
 *************************/
bool IsLower(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

/**************************
 * IsUpper()
 *************************/
bool IsUpper(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

/**************************
 * LetterCount()
 *************************/
int LetterCount(std::string str)
{
    int count = 0;

    for(int i = 0;str[i] != '\0';i += 1)
    {
        if(IsLower(str[i]) || IsUpper(str[i]))
        {
            count += 1;
        }
    }
    return count;
}

/**************************
 * ToLower()
 *************************/
std::string ToLower(std::string str)
{
    std::string cstr = "";
    for(int i = 0;str[i] != '\0';i += 1)
    {
        cstr += ((IsUpper(str[i]))?((char)('a' + (str[i] - 'A'))):(str[i]));  
    }
    return cstr;
}

/**************************
 * ToUpper()
 *************************/
std::string ToUpper(std::string str)
{
    std::string cstr = "";
    for(int i = 0;str[i] != '\0';i += 1)
    {
        cstr += ((IsLower(str[i]))?((char)('A' + (str[i] - 'a'))):(str[i]));  
    }
    return cstr;
}

/**************************
 * Substr()
 *************************/
std::string Substr(std::string str,char s,char e)
{
    std::string cstr = "";
    bool read = false;
    for(int i = 0;str[i] != '\0';i += 1)
    {
        if(str[i] == s && !read)
        {
            cstr += str[i];
            read = true;
        }
        else if(read)
        {
            cstr += str[i];

            if(str[i] == e)
            {
                break;
            }
        }  
    }
    return cstr;
}

/**************************************************
 * Substr() Alternative
 **************************************************
std::string Substr(std::string str,char s,char e)
{
    int start = -1, end = str.length() - 1;
    std::string cstr ="";

    for(int i = 0;str[i] != '\0';i += 1)
    {
        if(str[i] == s)
        {
            start = i;
            break;
        }
    }

    if(start == -1)
    {
        return "";
    }

    for(int i = start;str[i] != '\0';i += 1)
    {
        if(str[i+1] == e)
        {
            end = i + 1;
            break;
        }
    }

    for(int i = start;i <= end;i += 1)
    {
        cstr += str[i];
    }
    return cstr;
}
*******************************************************/
int main()
{
    std::string line;
    char start, end;

    std::cout << std::boolalpha;
    std::cout << "Enter a line: ";
    std::getline(std::cin,line);

    std::cout << "\"" << line << "\" has uppercase letters ";

    for(int i = 0;line[i] != '\0';i += 1)
    {
        if(IsUpper(line[i]))
        {
            std::cout << line[i] << " ";
        }
    }

    std::cout << "\nand lowercase letters ";
    for(int i = 0;line[i] != '\0';i += 1)
    {
        if(IsLower(line[i]))
        {
            std::cout << line[i] << " ";
        }
    }
    std::cout << "\n\nThere are " << LetterCount(line) << " letter(s) in the line:\n\"" << line << "\"\n\n";
    std::cout << "To Lowercase: " << ToLower(line) << "\n";
    std::cout << "To Uppercase: " << ToUpper(line) << "\n\n";

    std::cout << "Enter the start character: ";
    std::cin >> start;

    std::cout << "Enter the end character: ";
    std::cin >> end;
    
    std::cout << "The substring is " << Substr(line,start,end) << "\n";

    return 0;
}