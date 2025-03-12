/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_TOPIC.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:10:50 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_TOPIC (332)
<channel> :<info>
Response to TOPIC when no topic is set
*/
std::string	RPL_TOPIC(std::string nickname, std::string channel, std::string topic)
{
	std::stringstream	output;
	(void)nickname;
	output << ":" << HOSTNAME;
	output << " 332";
	output << " " << nickname;
	output << " #" << channel;
	output << " :" << topic;
	output << "\r\n";
	return (output.str());
}
