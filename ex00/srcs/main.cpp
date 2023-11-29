/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:45:09 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/29 17:55:00 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "we need a parameter to convert, and only one parameter" << std::endl;
        return 1;
    }
    if (std::atol(argv[1]) > INT_MAX || std::atol(argv[1]) < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (1);
	}
    ScalarConverter::convert(argv[1]);

    return 0;
}