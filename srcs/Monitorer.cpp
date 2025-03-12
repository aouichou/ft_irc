/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitorer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:47:49 by juchene           #+#    #+#             */
/*   Updated: 2024/02/02 05:53:13 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Monitorer.hpp"

Monitorer::Monitorer(std::string pass)
	: _pass(pass)
{
	DEBUG_CALL_MONITORER
	_cmd.insert(std::make_pair("CAP",		&Monitorer::cmd_cap));
	_cmd.insert(std::make_pair("PASS",		&Monitorer::cmd_pass));
	_cmd.insert(std::make_pair("NICK",		&Monitorer::cmd_nick));
	_cmd.insert(std::make_pair("USER",		&Monitorer::cmd_user));
	_cmd.insert(std::make_pair("PING",		&Monitorer::cmd_ping));
	_cmd.insert(std::make_pair("QUIT",		&Monitorer::cmd_quit));
	_cmd.insert(std::make_pair("WHOIS",		&Monitorer::cmd_whois));
	_cmd.insert(std::make_pair("WHO",		&Monitorer::cmd_who));
	_cmd.insert(std::make_pair("MODE",		&Monitorer::cmd_mode));
	_cmd.insert(std::make_pair("JOIN",		&Monitorer::cmd_join));
	_cmd.insert(std::make_pair("PRIVMSG",	&Monitorer::cmd_privmsg));
	_cmd.insert(std::make_pair("KICK",		&Monitorer::cmd_kick));
	_cmd.insert(std::make_pair("INVITE",	&Monitorer::cmd_invite));
	_cmd.insert(std::make_pair("TOPIC",		&Monitorer::cmd_topic));
	_cmd.insert(std::make_pair("MARVIN",	&Monitorer::cmd_marvin));
}

Monitorer::~Monitorer()
{
	for (t_clients::iterator it = _clients.begin() ; it != _clients.end() ; it++)
		delete *it;

	for (t_channel_map::iterator it = _channel_map.begin(); it != _channel_map.end() ; it++)
		delete it->second;
	DEBUG_CALL_MONITORER
}

void	Monitorer::addEventListener(IQueue &queue, int fd_socketBind)
{
	PRINT_DEBUG_CALL_MESSAGE(YELLOW, "", Monitorer, RESET << " -> ")
	User*	user = new User(queue, fd_socketBind);
	if (user == NULL)
		return ;
	_clients.insert(user);
}

void	Monitorer::removeEventListener(IQueue::IEventListener* listener)
{
	PRINT_DEBUG_CALL_MESSAGE(YELLOW, "", Monitorer, RESET << " -> ")
	User*	user = dynamic_cast<User*>(listener);

	t_clients::iterator it = _clients.find(user);
	if (it == _clients.end())
		return ;
	_clients.erase(it);
	IQueue::IEventListener::free(user);
}

void	Monitorer::treatEventListener(IQueue::IEventListener* listener)
{
	user = dynamic_cast<User*>(listener);
	if (user == NULL)
		throw std::runtime_error("Bad EventListener");
	while (user->read_message(&request))
	{
		t_cmd_map::iterator	it = _cmd.find(request->command.name);
		if (it != _cmd.end())
			(this->*(it->second))();
		else
			cmd_unknown();
		delete request;
	}
}

User*		Monitorer::findClient(std::string name)
{
	t_clients::iterator	it = _clients.begin();
	t_clients::iterator	ite = _clients.end();

	for ( ; it != ite ; it++)
	{
		if ((*it)->nick_name == name)
		{
			return *it;
		}
	}
	return (NULL);
}

Channel*	Monitorer::find_channel(std::string name)
{
	t_channel_map::iterator	it;

	it = _channel_map.find(name);
	if (it == _channel_map.end())
		return (NULL);
	return (it->second);
}

Channel*	Monitorer::find_or_create_channel(std::string name)
{
	t_channel_map::iterator	it;

	it = _channel_map.find(name);
	if (it == _channel_map.end())
	{
		Channel*	new_channel = new Channel();
		new_channel->name = name;
		it = _channel_map.insert(std::make_pair(name, new_channel)).first;
	}
	return (it->second);
}
