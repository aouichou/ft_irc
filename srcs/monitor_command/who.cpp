/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:32:37 by aouichou          #+#    #+#             */
/*   Updated: 2024/02/02 05:57:31 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Monitorer.hpp"
# include "User.hpp"
# include <algorithm>
# include <list>
# include <string>
# include "responses.hpp"

static void 	is_valid_mask(const std::string &mask)
{
	if (mask[0] == '#' && mask.find("*", 0) != std::string::npos)
		throw std::exception();
	if (std::count(mask.begin(), mask.end(), '@') > 1 || std::count(mask.begin(), mask.end(), '!') > 1)
		throw std::exception();
	size_t host_pos = mask.find("@", 0);
	size_t user_pos = mask.find("!", 0);
	if (host_pos == std::string::npos || user_pos == std::string::npos)
		return;
	if (user_pos > host_pos)
		throw std::exception();
	return;
}

#include <cstdio>

void	Monitorer::cmd_who(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	std::string param = request->params[0];

	if (param.empty())
	{
		return (user->send_message(ERR_NOSUCHSERVER(param)));
	}
    if (!param.empty() && param[0] == '#')
	{
        param.erase(0, 1);
    }
	try
	{
		is_valid_mask(param);
	}
	catch (const std::exception &e) { return; }

	Channel* channel = find_channel(param);
	if (channel == NULL)
		return (user->send_message(ERR_NOSUCHCHANNEL(user->nick_name, param)));
	if (!channel->isOperator(user) && !channel->isInChannel(user))
		return (user->send_message(ERR_NOTONCHANNEL(user->nick_name, param)));
	if (request->params.size() >= 3 && request->params[1].size() == 1 && param[0] == 'o')
	{
		if (!channel->isOperator(user))
			return (user->send_message(ERR_CHANOPRIVSNEEDED(user->nick_name, param)));
	}
	else
	{
		std::string		users_list = channel->getUserList();
		user->send_message(RPL_WHOREPLY(param, users_list));
	}
	user->send_message(RPL_ENDOFWHO(param));
}
