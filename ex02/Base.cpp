/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:58:52 by areheman          #+#    #+#             */
/*   Updated: 2023/01/17 10:29:27 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"

Base::~Base(){std::cout<<"Base destructor"<<std::endl;};
A::~A(){std::cout<<"A destructor"<<std::endl;};
B::~B(){std::cout<<"B destructor"<<std::endl;};
C::~C(){std::cout<<"C destructor"<<std::endl;};

Base* generate(void)
{
	Base* b;
	if ((std::rand() % 3) == 0)
		b = new A;
	else if ((std::rand() % 3) == 1)
		b = new B;
	else
		b = new C;
	return b;
}

void	identify(Base* p)
{
	if ((dynamic_cast<A*>(p)) != NULL)
		std::cout<<"A type"<<std::endl;
	else if ((dynamic_cast<B*>(p)) != NULL)
		std::cout<<"B type"<<std::endl;
	else if ((dynamic_cast<C*>(p)) != NULL)
		std::cout<<"C type"<<std::endl;
	else
		std::cout<<"unknown type"<<std::endl;
		
}

void	identify(Base& p)
{
		try{
			A& a = dynamic_cast<A&>(p);			
			std::cout<<"A type"<<std::endl;
			(void)a;
		}catch(std::exception& e){}
		try{
			B& b = dynamic_cast<B&>(p);			
			std::cout<<"B type"<<std::endl;
			(void)b;
		}catch(std::exception& e){}
		try{
			C& c = dynamic_cast<C&>(p);			
			std::cout<<"C type"<<std::endl;
			(void)c;
		}catch(std::exception& e){}
}



//static_cast , reinterpret_cast, const_cast
//https://www.bogotobogo.com/cplusplus/typecast.php


//dynamic_cast
//https://www.bogotobogo.com/cplusplus/dynamic_cast.php