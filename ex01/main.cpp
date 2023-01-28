/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:30:45 by areheman          #+#    #+#             */
/*   Updated: 2023/01/17 10:28:19 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	try{
		Data* p = new Data;
		p->name = "sam";
		p->age = 5;
	//	Data* p =	NULL;

		uintptr_t uin = serialize(p);
		
		std::cout<<"p: "<<p<<std::endl;
		std::cout<<"uin: "<<uin<<std::endl;
		
		Data* s = deserialize(uin);
		
		std::cout<<"s: "<<s<<std::endl;

		delete p;
	}catch(const char* s)
	{
		std::cout<<s<<std::endl;
	}
	
	return (0);
}