/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_MYINFO.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 06:12:48 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
RPL_MYINFO (004)
:<server_name> <version> <user_modes> <chan_modes>
*/
std::string	RPL_MYINFO()
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " 004 ";
	output << ": " << BOLD << BLUE << SERVERNAME << RESET << " " << RED << VERSION << RESET;
	output << CYAN << LOGO << RESET;
	output << BOLD << RED << "\n\t\t\t\t& Don't forget your towel" << RESET;
	output << "\r\n";
	return (output.str());
}
