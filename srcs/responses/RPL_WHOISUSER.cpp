/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPL_WHOISUSER.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:56:01 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

std::string	RPL_WHOISUSER(User * _user)
{
	std::stringstream	output;

	output << _user->nick_name << " ";
	output << _user->user_name.get() << " ";
	output << _user->host_name.get() << " ";
	output << "* :";
	output << _user->real_name.get() << " ";
	output << "\r\n";
	return (output.str());
}
