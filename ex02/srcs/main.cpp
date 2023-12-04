/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <pmaimait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:32:07 by pmaimait          #+#    #+#             */
/*   Updated: 2023/12/04 14:17:47 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/C.hpp"

Base	*generate(void)
{
    Base*	p;
	std::srand(time(0));
	int i = ((rand() % 3));
	std::cout << i << std::endl;
	switch(i)
	{
		case 0:
			p = new A();
			break;
		case 1:
			p = new B();
			break;
		case 2:
			p = new C();
			break;
	}
	return p;
}

void	identify(Base *p)
{
	if (p == NULL)
		std::cout << "No Base find for this pointer ! " << std::endl;
	if (dynamic_cast<A *>(p))
		std::cout << "Base pointer is type A ! " << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Base pointer is type B ! " << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Base pointer is type C ! " << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Base is type A ! " << std::endl;
	}
	catch(const std::exception &)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Base is type B ! " << std::endl;
	}
	catch(const std::exception &)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Base is type C ! " << std::endl;
	}
	catch(const std::exception &)
	{
	}
}
int	main(void)
{
	Base *p;
    p = generate();
    
	identify(*p);
	identify(p);

	delete p;

	Base *p2 = NULL;
    p2 = generate();

	identify(*p2);
	identify(p2);

	delete p2;
	return 0;
}