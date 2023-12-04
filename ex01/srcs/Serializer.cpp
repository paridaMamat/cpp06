/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:19:43 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/04 11:23:36 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &obj)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = obj;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &obj)
{
	(void)obj;
	std::cout << "Serializer Copy assignment operator called" << std::endl;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

void	Data::getValues() const
{
	std::cout << "Data name = " << this->name  << " and Data int = " << this->int_value << std::endl;
}