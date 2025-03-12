/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NEEDMOREPARAMS.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:00:55 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

std::string	ERR_NEEDMOREPARAMS(std::string channel, std::string cmd, std::string reason)
{
	std::stringstream	output;

	(void)channel;
	output << ":" << HOSTNAME;
	output << " 461";
	if (channel.size())
		output << " #" << channel;
	output << " " << cmd;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
