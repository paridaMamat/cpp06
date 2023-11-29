/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:33:25 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/29 18:03:58 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cstring> 
#include <limits.h>

class ScalarConverter 
{
    private :
    
    ScalarConverter();
    ScalarConverter(ScalarConverter const &obj);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &obj);

    public :
    
    static bool isChar(std::string str);
    static bool isInt(std::string str);
    static bool isFloat(std::string str);
    static bool isDouble(std::string str);
    static bool noPoint(double doubleResult);
   

    static void convert(char const *input);
};

#endif