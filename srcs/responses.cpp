/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responses.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:52:59 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_TRYAGAIN (263)
<command> :<info>
When a server drops a command without processing it, 
it MUST use this reply.
*/

std::string	RPL_TRYAGAIN(std::string command, std::string info)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " " << command;
	output << " :" << info;
	output << "\r\n";
	return (output.str());
}


std::string	NICK(std::string old, std::string newnick)
{
	std::stringstream	output;

	output << ":" << old;
	output << " NICK";
	output << " " << newnick;
	output << "\r\n";
	return (output.str());
}

/*
ERR_NOORIGIN (409)
:<reason> 
PING or PONG message missing the originator parameter
which is required since these commands must work without 
valid prefixes
*/

std::string	ERR_NOORIGIN()
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 409";
	output << " :message missing the originator parameter";
	output << "\r\n";
	return (output.str());
}

/*
ERR_NOSUCHSERVER (402)
<server> :<reason>      
Used to indicate the server name given currently doesn't exist
*/

std::string	ERR_NOSUCHSERVER(std::string server)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 402 ";
	output << server;
	output << " :the server name given currently doesn't exist\r\n";
	return (output.str());
}

/*
ERR_NOTREGISTERED (451)
:<reason>      
Returned by the server to indicate that the client 
must be registered before the server will allow it to be parsed in detail
*/

std::string	ERR_NOTREGISTERED(void)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 451";
	output << " :you are not registered\r\n";
	return (output.str());
}
