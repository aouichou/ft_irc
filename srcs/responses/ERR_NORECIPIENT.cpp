/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERR_NORECIPIENT.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:01:55 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
ERR_NORECIPIENT (411)
:<reason>
Returned when no recipient is given with a command
*/
std::string	ERR_NORECIPIENT(std::string reason)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 411";
	output << " :" << reason;
	output << "\r\n";
	return (output.str());
}
