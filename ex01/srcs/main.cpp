/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:19:52 by pmaimait          #+#    #+#             */
/*   Updated: 2023/11/29 18:21:02 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serialization.hpp"

int main(void)
{
    {
        Data *launch = new Data;

        launch->str_value = "Str de test - Amazing string save !";
        launch->int_value = -42;

        uintptr_t utest = Serialization::serialize(launch);

        Data *receive = Serialization::deserialize(utest);
        receive->getValues();

        delete launch;
    }
    {
        Data launch;

        launch.str_value = "Str de test2 - Amazing string save without new ? This performance is possible ?!";
        launch.int_value = 56;

        uintptr_t utest = Serialization::serialize(&launch);

        Data *receive = Serialization::deserialize(utest);
        receive->getValues();
    }
        return (0);
}