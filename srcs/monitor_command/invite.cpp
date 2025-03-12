/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:14:40 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Monitorer.hpp"

/*
Command: INVITE
Parameters: <nickname> <channel>

The INVITE message is used to invite users to a channel.  The
parameter <nickname> is the nickname of the person to be invited to
the target channel <channel>.  There is no requirement that the
channel the target user is being invited to must exist or be a valid
channel.  To invite a user to a channel which is invite only (MODE
+i), the client sending the invite must be recognised as being a
channel operator on the given channel.

*/
void	Monitorer::cmd_invite(void)
{
	DEBUG_CALL_MONITORER_COMMAND
	if (!user->isConnected())
		return (user->send_message(ERR_NOTREGISTERED()));

	std::string	channelName;
	std::string	nickToInvite;
	std::string	userNickName = user->nick_name;
	size_t		paramsCount = request->params.size();

//1. check si au moins 2 params
	if (paramsCount < 2)
	{
		user->send_message(ERR_NEEDMOREPARAMS("", "IVITE"));
		return ;
	}

	nickToInvite = request->params[0];
	channelName = request->params[1];
    if (!channelName.empty() && channelName[0] == '#')
	{
		channelName = channelName.substr(1);
	}
	Channel	*channel = find_channel(channelName);

//2. prendre le param #1 - verifier que la channel existe
	if (channel == NULL)
	{
		user->send_message(ERR_NOSUCHCHANNEL(userNickName, channelName));
		return ;
	}

//3. verifier que user est sur la channel avec :
	User * test = channel->findUser(userNickName);
	if (!test)
	{
		user->send_message(ERR_NOTONCHANNEL(userNickName, channelName));
		return ;
	}

//4. verifier les droits operateurs de user avec :
	if (!channel->isOperator(user))
	{
		user->send_message(ERR_CHANOPRIVSNEEDED(userNickName, channelName));
		return ;
	}

//5. verifier que la personne à invite est dans la base t_client avec
	User * monitor_userToInvite = findClient(nickToInvite);
	if (!monitor_userToInvite)
	{
		user->send_message(ERR_NOSUCHNICK(userNickName, channelName, nickToInvite));
		return ;
	}
	User * userToInvite = channel->findUser(nickToInvite);
//6. verifier si la personne à invite est deja dans le channel avec
	if (userToInvite && !channel->isInvited(userToInvite))
	{
		user->send_message(ERR_USERONCHANNEL(channelName, nickToInvite));
		return ;
	}
	if (!userToInvite)
		channel->invite(monitor_userToInvite);

	std::string	reply = RPL_INVITING(user->nick_name, nickToInvite, channelName);
	channel->sendToAllUsers(reply);
}

