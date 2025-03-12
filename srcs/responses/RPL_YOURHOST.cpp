/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_YOURHOST.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:11:38 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_YOURHOST (002)
:Your host is <servername>, running version <version>
*/
std::string	RPL_YOURHOST()
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 002 ";
	output << ": Your host is " << SERVERNAME;
	output << ", running version " << VERSION;
	output << "\r\n";
	return (output.str());
}
