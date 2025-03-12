/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JOIN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 00:50:21 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:06:12 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "responses.hpp"

/*
JOIN
*/
std::string	JOIN(User* user, std::string channel)
{
	std::stringstream	output;

	output << ":" <<  user->nick_name;
	output << "!" <<  user->user_name.get();
	output << "@" <<  user->host_name.get();
	output << " JOIN ";
	output << "#" << channel;
	output << "\r\n";
	return (output.str());
}
