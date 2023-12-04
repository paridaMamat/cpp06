/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:19:52 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/04 14:26:26 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
    {
        Data *A = new Data;

        A->name = "A";
        A->int_value = -42;

        uintptr_t uintp = Serializer::serialize(A);

        Data *b = Serializer::deserialize(uintp);
        b->getValues();

        delete A;
    }
    {
        Data a;

        a.name = "a";
        a.int_value = 56;
        
        uintptr_t uintp = Serializer::serialize(&a);

        Data *b = Serializer::deserialize(uintp);
        b->getValues();
    }
    {
        Data originalData;

        originalData.int_value = 42;
        
        uintptr_t serializedValue = Serializer::serialize(&originalData);


        Data* deserializedData = Serializer::deserialize(serializedValue);


        if (deserializedData == &originalData) 
        {
            std::cout << "Serialization and deserialization successful!" << std::endl;
            std::cout << "Original Data value: " << originalData.int_value << "  Deserialized Data value: " << deserializedData->int_value << std::endl;
        } else 
        {
            std::cout << "Serialization and deserialization failed!" << std::endl;
        }
    }
        return (0);
}