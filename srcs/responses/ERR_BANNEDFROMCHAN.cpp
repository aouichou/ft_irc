/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_BANNEDFROMCHAN.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:58:05 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_BANNEDFROMCHAN (474) // canJoin
<channel> :<reason>
*/
std::string	ERR_BANNEDFROMCHAN(std::string channel, std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 474";
	output << " " << channel;
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
