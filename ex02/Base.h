/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:04 by areheman          #+#    #+#             */
/*   Updated: 2023/01/17 10:30:31 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base{

	public:
		virtual ~Base();	
};

class A : public Base{
	
	public:
		~A();
	
};

class B : public Base{
	
	public:
		~B();
};

class C : public Base{


	public:
		~C();	
};

Base* generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif