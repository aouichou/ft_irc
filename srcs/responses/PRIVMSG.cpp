/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRIVMSG.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:07:37 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
PRIVMSG
*/
std::string	PRIVMSG(std::string sender, std::string channel, std::string message)
{
	std::stringstream	output;

	output << ":" <<  sender;
	output << " PRIVMSG ";
	output << "#" << channel;
	output << " :" << message;
	output << "\r\n";
	return (output.str());
}
