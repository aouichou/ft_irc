/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:58:16 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"

void	Monitorer::cmd_nick(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	/* STEP #1 : check if the new nickname is already in use || valid */
	if (request->params.empty())
		return (user->send_message(ERR_NONICKNAMEGIVEN()));
	std::string nickname = request->params.front();
	request->params.pop_front();
	if (0
		|| nickname == "anonymous"
		|| nickname == "localhost"
		|| nickname.find_first_of("<>?/\\!%#@&$") != std::string::npos)
		return (user->send_message(ERR_ERRONEUSNICKNAME(nickname)));

	/* STEP #2 : check if the new nickname is already in use */
	for (t_clients::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		if ((*it)->is_alive() && *it != user)
		{
			if ((*it)->nick_name == nickname)
				return (user->send_message(ERR_NICKNAMEINUSE(nickname)));
		}
	}
				
	std::string oldnick;
	if (user->nick_name.size())
		oldnick = user->nick_name;
	else
		oldnick = nickname;
	user->nick_name = nickname;
	user->send_message(NICK(oldnick, nickname));
	user->connectionStep(_pass, 1);
	
}
