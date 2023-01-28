/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:43:39 by areheman          #+#    #+#             */
/*   Updated: 2023/01/14 11:17:46 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <limits.h>

enum types{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	DL,
	FL
};

class Convert
{
	private:
		char*	s;
		std::string str;
		char	_c;
		int		_int;
		double	_d;
		float	_f;
		bool	_dl;
		bool	_fl;
		bool	_imp;

	public:
		Convert();
		Convert(const Convert& obj);
		Convert& operator=(const Convert& obj);
		~Convert();

		void	setStrs(char *s);
		void	convert();
		bool	isEmpty();
		int		checkType();
		int		isChar();
		int		isInt();
		int		isDouble();
		int		isFloat();
		int		isLitera();
		void	printChar();
		void	printInt();
		void	printDouble();
		void	printFloat();
		void	printFL();
		void	printDL();

		class UnkwonType:public std::exception
		{
			const char* what() const throw()
			{return "UnkwonType!!";}	
		};
		class Empty:public std::exception
		{
			const char* what() const throw()
			{return "empty!!";}	
		};
};

#endif