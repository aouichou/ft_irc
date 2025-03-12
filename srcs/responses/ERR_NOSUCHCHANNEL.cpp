/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NOSUCHCHANNEL.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:02:25 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NOSUCHCHANNEL (403)
<channel> :<reason> 
Used to indicate the given channel name is invalid, or does not exist
*/
std::string	ERR_NOSUCHCHANNEL(std::string nickname, std::string channel, std::string reason)
{
	std::stringstream	output;

	(void)reason;
	output << ":" << HOSTNAME;
	output << " 403 ";
	output << " " << nickname;
	output << " #" << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
