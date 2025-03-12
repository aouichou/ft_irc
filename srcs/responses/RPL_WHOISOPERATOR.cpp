/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WHOISOPERATOR.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/01/31 01:10:51 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*[AJOUT]*/

/*
RPL_WHOISOPERATOR (313) 

"<client> <nick> :is an IRC operator"

Sent as a reply to the WHOIS command, this numeric indicates that the client with 
the nickname <nick> is an operator. This command MAY also indicate what type or 
level of operator the client is by changing the text in the last parameter of this numeric. 
The text used in the last param of this message varies wildly, and SHOULD be displayed 
as-is by IRC clients to their users.

*/

std::string	RPL_WHOISOPERATOR(User * _user, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 313 ";
	output << _user->nick_name << " ";
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}