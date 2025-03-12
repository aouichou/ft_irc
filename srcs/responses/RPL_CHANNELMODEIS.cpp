/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_CHANNELMODEIS.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:08:54 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_CHANNELMODEIS (324)
<channel> <mode> <mode_params>
*/
std::string	RPL_CHANNELMODEIS(std::string nickname, Channel* channel)
{
	std::stringstream	output;
	(void)nickname;
	if (channel->getChannelModes().size())
	{
		output << ":" << HOSTNAME;
		output << " 324";
		output << " " << nickname;
		output << " #" << channel->name;
		output << " " << channel->getChannelModes();
		output << " :" << channel->getChannelModesParams();
		output << "\r\n";
	}
	return (output.str());
}
