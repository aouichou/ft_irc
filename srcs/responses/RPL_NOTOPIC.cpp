/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_NOTOPIC.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:10:33 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_NOTOPIC (331)
<channel> :<info>
Response to TOPIC when no topic is set
*/
std::string	RPL_NOTOPIC(std::string nickname, std::string channel, std::string info)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 331";
	output << " " << nickname;
	output << " #" << channel;
	output << " :" << info;
	output << "\r\n";
	return (output.str());
}
