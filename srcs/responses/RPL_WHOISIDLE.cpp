/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WHOISIDLE.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:56:11 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*[AJOUT]*/

/*
RPL_WHOISIDLE (317) 

"<client> <nick> <secs> <signon> :seconds idle, signon time"

Sent as a reply to the WHOIS command, this numeric indicates how long the client 
with the nickname <nick> has been idle. <secs> is the number of seconds since 
the client has been active. Servers generally denote specific commands 
(for instance, perhaps JOIN, PRIVMSG, NOTICE, etc) as updating the ‘idle time’, 
and calculate this off when the idle time was last updated. <signon> is a unix 
timestamp representing when the user joined the network. The text used in the 
last param of this message may vary.

*/

std::string	RPL_WHOISIDLE(User * _user, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 317 ";
	output << _user->nick_name << " ";
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}