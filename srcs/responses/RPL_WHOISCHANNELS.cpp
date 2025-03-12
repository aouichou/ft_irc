/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WHOISCHANNELS.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/01/31 04:27:35 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*[AJOUT]*/

/*
RPL_WHOISCHANNELS (319) 

"<client> <nick> :[prefix]<channel>{ [prefix]<channel>}

Sent as a reply to the WHOIS command, this numeric lists the channels that the client 
with the nickname <nick> is joined to and their status in these channels. 
<prefix> is the highest channel membership prefix that the client has in that channel, 
if the client has one. <channel> is the name of a channel that the client is joined to. 
The last parameter of this numeric is a list of [prefix]<channel> pairs, 
delimited by a SPACE character (' ', 0x20).

*/

std::string	RPL_WHOISCHANNELS(std::string prefix, Channel *channel)
{
	std::stringstream	output;

	output << "*((" << prefix << ")<" << channel->name << ">)";
	output << "\r\n";
	return (output.str());
}