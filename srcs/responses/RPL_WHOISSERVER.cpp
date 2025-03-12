/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WHOISSERVER.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/01/31 04:59:21 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*[AJOUT]*/

/*
RPL_WHOISSERVER (312) 

"<client> <nick> <server> :<server info>"

Sent as a reply to the WHOIS (or WHOWAS) command, this numeric shows which server 
the client with the nickname <nick> is (or was) connected to. <server> is the name 
of the server (as used in message prefixes). <server info> is a string containing 
a description of that server.

*/

std::string	RPL_WHOISSERVER(User * _user)
{
	std::stringstream	output;

	(void)_user;
	output << "Server: " << SERVERNAME;
	output << "\r\n";
	return (output.str());
}