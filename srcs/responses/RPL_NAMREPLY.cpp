/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_NAMREPLY.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:10:18 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_NAMREPLY (474)
:<server> 353 <nickname> <channel> :[[@|+]<nick>] [@[|+]<nick>] ...
<channel> :<reason>

RPL_ENDOFNAMES
*/
std::string	RPL_NAMREPLY(std::string nickname, Channel *channel)
{
	std::stringstream	output;
	(void)nickname;
	output << ":" << HOSTNAME;
	output << " 353";
	output << " " << nickname;
	output << " = #" << channel->name;
	output << " : " << channel->getUserList();
	output << "\r\n";
	return (output.str());
}

std::string	RPL_ENDOFNAMES(std::string nickname, Channel *channel)
{
	std::stringstream	output;
	(void)nickname;
	output << ":" << HOSTNAME;
	output << " 366";
	output << " " << nickname;
	output << " #" << channel->name;
	output << " :End of /NAMES list";
	output << "\r\n";
	return (output.str());
}
