#include "ScalarConverter.hpp"

int handleSpecialCases(const std::string &input)
{
    if (input == "+inff")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
        return true;
    }
    else if (input == "-inff")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
        return true;
    }
    else if (input == "nanf")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        return true;
    }
    else if (input == "+inf")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
        return true;
    }
    else if (input == "-inf")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
        return true;
    }
    else if (input == "nan")
    {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
        return true;
    }
    return false;
}

bool is_char(const std::string& input)
{
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    if (input.length() == 1 && !isdigit(static_cast<unsigned char>(input[0])))
        return true;
    return false;
}

bool is_int(const std::string& input)
{
    int i = 0;

    if (input[i] && (input[i] == '+' || input[i] == '-'))
        i++;
    if (!input[i])
        return false;
    while (input[i])
    {
        if (!isdigit(static_cast<unsigned char>(input[i])))
            return false;
        i++;
    }
    return true;
}

bool is_float(const std::string& input)
{
    int i = 0;
    int count = 0;

    if (input[i] && (input[i] == '+' || input[i] == '-'))
        i++;
    while (input[i])
    {
        if (input[i] == '.' && i > 0 && isdigit(input[i - 1]) && isdigit(input[i + 1]))
            count++;
        if (input[i] == 'f' && !input[i + 1] && count == 1)
            return true;
        if ((!isdigit(static_cast<unsigned char>(input[i])) && input[i] != '.') || count > 1)
            return false;
        i++;
    }
    return false;
}

bool is_double(const std::string& input)
{
    int i = 0;
    int count = 0;

    if (input[i] && (input[i] == '+' || input[i] == '-'))
        i++;
    while (input[i])
    {
        if (input[i] == '.' && i > 0 && isdigit(input[i - 1]) && isdigit(input[i + 1]))
            count++;
        if ((!isdigit(static_cast<unsigned char>(input[i])) && input[i] != '.') || count > 1)
            return false;
        i++;
    }
    return (count == 1);
}

void ScalarConverter::convert(const std::string& input)
{
    char c;
    double d_val;

    if (handleSpecialCases(input)) return;

    if (is_char(input))
    {
        c = (input.length() == 3) ? input[1] : input[0];
        std::cout << "char: '" << c << "'" << std::endl; 
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    else if (is_int(input))
    {
        d_val = std::strtod(input.c_str(), NULL);

        if (d_val < 0 || d_val > 127)
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<int>(d_val)))
            std::cout << "char: '" << static_cast<char>(d_val) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (d_val < std::numeric_limits<int>::min() || d_val > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d_val) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d_val) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d_val << std::endl;
    }
    else if (is_float(input))
    {
        float f = static_cast<float>(atof(input.c_str()));

        if (f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<int>(f)))
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
    }
    else if (is_double(input))
    {
        double d = atof(input.c_str());

        if (d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl;
        else if (isprint(static_cast<int>(d)))
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}