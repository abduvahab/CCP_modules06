/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:00:47 by areheman          #+#    #+#             */
/*   Updated: 2023/01/17 10:31:01 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"

int main(void)
{
	std::cout<<"____test1_____"<<std::endl;
	Base* p = generate();
	Base* c;
	c = NULL;
	identify(p);
	identify(c);

	std::cout<<"____test2_____"<<std::endl;
	Base* p2 = generate();
	identify(*p2);
	std::cout<<"____end_____"<<std::endl;

	delete p;
	delete p2;
	return 0;
}