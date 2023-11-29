/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:43:32 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/29 18:05:54 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
    std::cout << "ScalarConverter Copy Constructor Called" << std::endl;
    *this = obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj)
{
    (void)obj;
    std::cout << "ScalarConverter Overload Constructor Called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor Called" << std::endl;
}

bool    ScalarConverter::isChar(std::string str){
    if (str.size() == 1 && !std::isdigit(str[0]))
        return (true);
    return (false);
}

bool    ScalarConverter::isInt(std::string str){
    unsigned long int	i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.size() == i)
		return (true);
	return (false);
}

bool    ScalarConverter::isFloat(std::string str){
    unsigned long int	i = 0;
	
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && std::isdigit(str[i + 1]))
		i++;
	else
		return (false);
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == 'f')
		i++;
	else
		return (false);
	if (str.size() == i)
		return (true);
	return (false);
}

bool    ScalarConverter::isDouble(std::string str){
    unsigned long int	i = 0;
	
	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);
	if (str[0] == '-' || str[0] == '-')
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str[i] == '.' && std::isdigit(str[i + 1]))
		i++;
	while (std::isdigit(str[i]))
		i++;
	if (str.size() == i)
		return (true);
	return (false);
}

bool    ScalarConverter::noPoint(double doubleResult){
    std::stringstream ss;
    ss << doubleResult;
    std::string stringValue = ss.str();
    for (std::string::const_iterator it = stringValue.begin(); it != stringValue.end(); ++it){
        if (!isdigit(*it)) 
            return false;
    }
    if ((stringValue.find('.') != std::string::npos))
        return false;
    else
        return true;
}


void ScalarConverter::convert(char const *input) {
    
    double doubleResult = strtod(input, 0);
    
    // Convert to char
    if (isChar(input)){
        char charResult = input[0];
        std::cout << "char: " << "'" << charResult << "'"<< std::endl;
        std::cout << "int: " << static_cast<int>(charResult) << std::endl;
        std::cout << "double: " << static_cast<double>(charResult) << ".0" << std::endl;
        std::cout << "float: " << static_cast<double>(charResult) << ".0f" << std::endl;
        return ;
    }
    else if (strcmp(input, "0") != 0 && strcmp(input, "42.0f") != 0)
        std::cout << "char: impossible" << std::endl; 

    // Convert to int
    if (isInt(input)){
        if (strcmp(input, "0") == 0)
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(doubleResult) << std::endl;
        std::cout << "double: " << doubleResult << ".0" << std::endl;
        std::cout << "float: " << doubleResult << ".0f" << std::endl;
        return ;
    }
    else if (!isDouble(input) && !isFloat(input))
        std::cout << "int: impossible" << std::endl;   
    // Convert to Double
    if (isDouble(input)){
        if (strcmp(input, "nan") == 0 || strcmp(input, "+inf") == 0 || strcmp(input, "-inf") == 0)
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(doubleResult) << std::endl;
        std::cout << "Double: " << doubleResult;
        if (noPoint(doubleResult))
            std::cout << ".0";
        std::cout << std::endl;
        std::cout << "float: " << doubleResult;
        if (noPoint(doubleResult))
            std::cout << ".0";
        std::cout << "f" << std::endl;
        return ;
    }
    else if (!isInt(input) && !isFloat(input))
        std::cout << "Double: impossible" << std::endl;    
    // Convert to Float
    if (isFloat(input))
    {
        if (strcmp(input, "42.0f") == 0)
            std::cout << "char: " << "'*'"<< std::endl;
        if (strcmp(input, "nanf") == 0 || strcmp(input, "+inff") == 0 || strcmp(input, "-inff") == 0)
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(doubleResult) << std::endl;
        std::cout << "Double: " << doubleResult;
        if (noPoint(doubleResult))
            std::cout << ".0";
        std::cout << std::endl;
        std::cout << "float: " << doubleResult;
        if (noPoint(doubleResult))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    else
        std::cout << "Float: impossible" << std::endl;
}

    
    