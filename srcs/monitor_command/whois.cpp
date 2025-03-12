/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:59:33 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"
#include "User.hpp"
#include <time.h>

/*
4.5.2 Whois query
Command: WHOIS
Parameters: [<server>] <nickmask>[,<nickmask>[,...]]
This message is used to query information about particular user.

The server will answer this message with several numeric messages
indicating different statuses of each user which matches the nickmask
(if you are entitled to see them).  If no wildcard is present in the
<nickmask>, any information about that nick which you are allowed to
see is presented.  A comma (',') separated list of nicknames may be
given.
The latter version sends the query to a specific server.  It is
useful if you want to know how long the user in question has been
idle as only local server (ie. the server the user is directly
connected to) knows that information, while everything else is
globally known.
*/
// Numeric Replies:


static void		whois_client(t_params params, User *userToWhois, User *user)
{
	if (userToWhois == NULL)
	{
		if (params[0].find('.') != std::string::npos)
			return (user->send_message(ERR_NOSUCHSERVER(params[0])));
		else
			return (user->send_message(ERR_NOSUCHNICK(params[0])));
	}

	user->send_message(RPL_WHOISUSER(userToWhois));
	
	t_channels::iterator it1;
	t_channels::iterator it2;
	t_channels channels1 = user->AllUserChannels();
	t_channels channels2 = userToWhois->AllUserChannels();

	it1 = channels1.begin();
	for (; it1 != channels1.end(); it1++)
	{
		it2 = channels2.begin();
		for (; it2 != channels2.end(); it2++)
		{
			std::string prefix;
			prefix = userToWhois->nick_name + " :";
			if (it1->second->name == it2->second->name)
			{

				if (it1->second->isOperator(userToWhois))
					prefix += "@";
				user->send_message(RPL_WHOISCHANNELS(prefix, it1->second));
				break ;
			}
		}
	}
}

void	Monitorer::cmd_whois(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	std::string param = request->params[0];

	if (param.empty())
	{
		return (user->send_message(ERR_NONICKNAMEGIVEN()));
	}
	if (request->params.size() >= 1)
	{
		User *userToWhois = findClient(request->params[0]);
		whois_client(request->params, userToWhois, user);

		if (request->params.size() == 2)
		{
			user->send_message(RPL_WHOISSERVER(userToWhois));
			return (user->send_message(RPL_ENDOFWHOIS(userToWhois)));
		}
		user->send_message(RPL_ENDOFWHOIS(userToWhois));
	}
	
}