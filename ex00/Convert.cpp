/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <areheman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:51:08 by areheman          #+#    #+#             */
/*   Updated: 2023/01/17 10:52:15 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.h"

Convert::Convert(){
		_c='\0';
		_int = 0;
		_d = 0.0;
		_f = 0.0f;
		_dl = false;
		_fl = false;
		_imp = false;
		
}
Convert::~Convert(){}
Convert::Convert(const Convert& obj)
{
	*this = obj;
}
Convert& Convert::operator=(const Convert& obj)
{
	if (this == & obj)
		return *this;
	str = obj.str;
	_int = obj._int;
	_c = obj._c;
	_d = obj._d;
	_f = obj._f;
	_dl = obj._dl;
	_fl = obj._fl;
	_imp = obj._imp;
	return *this;
}

void	Convert::setStrs(char *s)
{
	this->s = s;
	std::string tem(s);
	str = tem;
}

void	Convert::convert()
{
	if (isEmpty())
		throw Empty();
	switch (checkType())
	{
	case CHAR:printChar();
		break;
	case INT:printInt();
		break;
	case DOUBLE:printDouble();
		break;
	case FLOAT:printFloat();
		break;
	case DL:printDL();
		break;
	case FL:printFL();
		break;
	default:throw UnkwonType();
		break;
	}
}

int Convert::checkType()
{
	int t;
	
	t = -1;
	if (isChar() == CHAR)
		t = CHAR;
	else if(isInt() == INT)
		t = INT;
	else if(isDouble()== DOUBLE)
		t = DOUBLE;
	else if (isFloat()== FLOAT)
		t = FLOAT;
	else if(isLitera() == DL)
		t = DL;
	else if(isLitera() == FL)
		t = FL;
	return t;
}

bool	Convert::isEmpty()
{
	if (!s || s[0] == '\0')
		return true;
	return false;	
}

int	Convert::isChar()
{
	int i;
	for(i=0; s[i]; i++){}
	if (i == 1)
	{
		if((s[0]>=65 && s[0]<=92) || (s[0]>=97 && s[0]<=126) || (s[0]>=32 && s[0]<=47))
		{
			_c = s[0];
			return CHAR;
		}
	}
	return -1;	
}

int	Convert::isInt()
{
	int i;
	int	len;
	
	i = 0;
	for(len = 0; s[len];len++){}
//	for(i; (s[i]==' '); i++){};
	if (s[i] == '-' || s[i] == '+')
		i++;	
	for(; (s[i]>=48 && s[i]<=57); i++){}
	
//	for(i; (s[i]==' '); i++){};
	if (i == len)
		return INT;
	return -1;	
}

int	Convert::isDouble()
{
	int i;
	int	len;
	
	i = 0;
	for(len = 0; s[len];len++){}
//	for(i; (s[i]==' '); i++){};
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!(s[i]>=48 && s[i]<=57))
		return -1;
	for(; (s[i]>=48 && s[i]<=57); i++){}
	if (s[i] == '.')
		i++;
	else
		return -1;
	for(; (s[i]>=48 && s[i]<=57); i++){}
	if (i == len)
		return DOUBLE;
	return -1;	
}

int	Convert::isFloat()
{
	int i;
	int	len;
	
	i = 0;
	for(len = 0; s[len];len++){}
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!(s[i]>=48 && s[i]<=57))
		return -1;
	for(; (s[i]>=48 && s[i]<=57); i++){}
	if (s[i] == '.')
		i++;
	else
		return -1;
	for(; (s[i]>=48 && s[i]<=57); i++){}
	if (s[i] != 'f')
		return -1;
	i++;
	if (i == len)
		return FLOAT;
	return -1;	
}

int	Convert::isLitera()
{
//	int i;
	int	len;
	
	for(len=0;s[len];len++){}
	if ((s[0] == '-' || s[0] == '+') && (len == 4 || len == 5))
	{
		if (s[1] == 'i' && s[2] == 'n' && s[3]== 'f'&& s[4]== '\0')
			return DL;
		else if (s[1] == 'i' && s[2] == 'n' && s[3]== 'f' &&  s[4]== 'f')
			return FL;		
	}
	else if (s[0] == 'n' && (len == 4 || len == 3))
	{
		if ((s[1] == 'a' && s[2] == 'n' && s[3]== '\0'))
			return DL;
		else if (s[1] == 'a' && s[2] == 'n' && s[3]== 'f' && s[4]== '\0')
			return FL;
	}
	//else
		return -1;	
}

void	Convert::printChar()
{
	_c = s[0];
	_int = static_cast<int>(_c);
	_d = static_cast<double>(_c);
	_f = static_cast<float>(_c);

	std::cout<<"char: "<<"'"<<_c <<"'"<<std::endl;
	std::cout<<"int: "<< _int<<std::endl;	
	std::cout<<"float: "<< _f<<".0f"<<std::endl;
	std::cout<<"double: "<< _d<<".0"<<std::endl;
}

void	Convert::printInt()
{
	try{
		_int = std::stoi(str);
	}catch(std::exception& e){
		_imp = true;
	}
	if (_imp)
	{
		std::cout<<"char: "<<"Impossible" <<std::endl;
		std::cout<<"int: "<< "Impossible"<<std::endl;
		std::cout<<"float: "<< "Impossible"<<std::endl;
		std::cout<<"double: "<< "Impossible"<<std::endl;
	}
	else
	{
		if (_int > 127 || _int < 0)
			std::cout<<"char: "<<"Impossible" <<std::endl;
		else if ((_int >= 0 && _int<32) || (_int ==127))
			std::cout<<"char: "<<"Non displayable" <<std::endl;
		else
		{
			_c = static_cast<char>(_int);
			std::cout<<"char: "<<"'"<<_c <<"'"<<std::endl;
		}
		_f = static_cast<float>(_int);
		_d = static_cast<double>(_int);
		std::cout<<"int: "<< _int<<std::endl;
		std::cout<<"float: "<< _f<<".0f"<<std::endl;
		std::cout<<"double: "<< _d<<".0"<<std::endl;
	}
}

void	Convert::printFloat()
{
	try{
		_f = std::stof(str);
	}catch(std::exception& e){
		_imp = true;
	}
	if (_imp)
	{
		std::cout<<"char: "<<"Impossible" <<std::endl;
		std::cout<<"int: "<< "Impossible"<<std::endl;
		std::cout<<"float: "<< "Impossible"<<std::endl;
		std::cout<<"double: "<< "Impossible"<<std::endl;
	}else
	{
		if (((std::numeric_limits<int>::max()) >= static_cast<int> (_f) && (_f > 0))\
			|| ((std::numeric_limits<int>::min()) < static_cast<int>(_f) && (_f < 0)))
		{
				_int = static_cast<int>(_f);
				if (_int > 127 || _int <= 0)
					std::cout<<"char: "<<"Impossible" <<std::endl;
				else if ((_int >= 1 && _int<32) || (_int ==127))
					std::cout<<"char: "<<"Non displayable" <<std::endl;
				else
				{
					_c = static_cast<char>(_int);
					std::cout<<"char: "<<"'"<<_c <<"'"<<std::endl;
				}
				std::cout<<"int: "<< _int<<std::endl;				
		}
		else
		{
			std::cout<<"char: "<<"Impossible" <<std::endl;
			std::cout<<"int: "<< "Impossible"<<std::endl;
		}
		_d = static_cast<double>(_f);
		std::cout<<"float: "<< _f<<".0f"<<std::endl;
		std::cout<<"double: "<< _d<<".0"<<std::endl;
	}
}

void	Convert::printDouble()
{
	try{
		_d = std::stod(str);
	}catch(std::exception& e){
		_imp = true;
	}
	if (_imp){
		std::cout<<"char: "<<"Impossible" <<std::endl;
		std::cout<<"int: "<< "Impossible"<<std::endl;
		std::cout<<"float: "<< "Impossible"<<std::endl;
		std::cout<<"double: "<< "Impossible"<<std::endl;
	}else{
		if ((static_cast<double>(std::numeric_limits<float>::max())> (_d) && (_d > 0))\
			|| (static_cast<double>(std::numeric_limits<float>::min()) < (_d) && (_d < 0)))
		{
			_f = static_cast<float>(_d);
			if ((static_cast<double>(std::numeric_limits<int>::max()) + 1 > (_d) && (_d > 0))\
			|| (static_cast<double>(std::numeric_limits<int>::min()) - 1 < (_d) && (_d < 0)))
			{
				_int = static_cast<int>(_d);
				if (_int > 127 || _int <= 0)
					std::cout<<"char: "<<"Impossible" <<std::endl;
				else if ((_int >= 1 && _int<32) || (_int ==127))
					std::cout<<"char: "<<"Non displayable" <<std::endl;
				else
				{
					_c = static_cast<char>(_int);
					std::cout<<"char: "<<"'"<<_c <<"'"<<std::endl;
				}
				std::cout<<"int: "<< _int<<std::endl;				
			}
			else{
				std::cout<<"char: "<<"Impossible" <<std::endl;
				std::cout<<"int: "<< "Impossible"<<std::endl;
				}
			std::cout<<"float: "<<_f<<".0f"<<std::endl;
		}else{
				std::cout<<"char: "<<"Impossible" <<std::endl;
				std::cout<<"int: "<< "Impossible"<<std::endl;
				std::cout<<"float: "<< "Impossible"<<std::endl;
			}
		std::cout<<"double: "<< _d<<".0"<<std::endl;

	}
}

void	Convert::printDL()
{
	
	std::cout<<"char: "<<"Impossible" <<std::endl;
	std::cout<<"int: "<< "Impossible"<<std::endl;
	std::cout<<"float: "<< str<<"f"<<std::endl;
	std::cout<<"double: "<< str<<std::endl;
}
void	Convert::printFL()
{
	int len;
	for(len=0;s[len]; len++);
	std::cout<<"char: "<<"Impossible" <<std::endl;
	std::cout<<"int: "<< "Impossible"<<std::endl;
	std::cout<<"float: "<< str<<std::endl;
	std::cout<<"double: ";
	for(int i=0; i <len-1;i++)
		std::cout<<s[i];
	std::cout<<std::endl;
}
