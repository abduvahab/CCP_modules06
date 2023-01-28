/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:24:06 by areheman          #+#    #+#             */
/*   Updated: 2023/01/17 10:52:53 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.h"

int	main(int n, char** s)
{
	
	if (n != 2)
		std::cout<<"you have to enter one parameter!!"<<std::endl;
	else
	{
		try{
			Convert	convert;
			convert.setStrs(s[1]);
			convert.convert();
		}catch(std::exception& e)
		{
			std::cout<<e.what()<<std::endl;
		}
	}
	return 0;
}