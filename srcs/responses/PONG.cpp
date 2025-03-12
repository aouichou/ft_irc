/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PONG.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:07:11 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
PONG
*/
std::string	PONG(std::string server)
{
	std::stringstream	output;

	output << ":" << HOSTNAME;
	output << " PONG ";
	output << server;
	output << "\r\n";
	return (output.str());
}
