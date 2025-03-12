/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WELCOME.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:11:07 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_WELCOME (001)
:Welcome to the Internet Relay Network <nick>!<user>@<host>
*/

std::string	RPL_WELCOME(User * user, std::string channel, std::string message)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 001 ";
	output << user->nick_name;
	if (channel.size())
		output << " #" << channel;
	output << " :" << message;
	output << user->nick_name << "!" << user->user_name.get();
	output << "@"+ user->host_name.get();
	output << "\r\n";
	return (output.str());
}
