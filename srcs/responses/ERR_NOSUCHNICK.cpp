/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NOSUCHNICK.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:02:41 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NOSUCHNICK (401)
<nick> :<reason> 
Used to indicate the nickname parameter supplied 
to a command is currently unused 
*/
std::string	ERR_NOSUCHNICK(std::string userNickName, std::string channel, std::string nickname, std::string reason)
{
	std::stringstream	output;
	(void)nickname;
	output << ":" << HOSTNAME;
	output << " 401";
	output << " " << userNickName;
	if (channel.size())
		output << " #" << channel;
	output << " " << nickname;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
