/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitorer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/01/31 23:25:03 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORER_HPP
# define MONITORER_HPP

# include <set>
# include <map>
# include "ICrud.hpp"
# include "responses.hpp"

# define DEBUG_CALL_MONITORER \
	PRINT_DEBUG_CALL(YELLOW, Monitorer)

# define DEBUG_CALL_MONITORER_COMMAND \
	PRINT_DEBUG_CALL(YELLOW, Monitorer) \
	User::debug(user); \
	PRINT_DEBUG_MESSAGE(BLUE, "\t" << request) \

class Monitorer: public ICrud
{
	public:
		Monitorer(std::string pass);
		~Monitorer();

		void	addEventListener(IQueue &queue, int fd_socketBind);
		void	treatEventListener(IQueue::IEventListener* listener);
		void	removeEventListener(IQueue::IEventListener* listener);

		size_t getNumberOfUsers() const
		{
			return _clients.size();
		}

		std::string getAllServerChannels() const
		{
			std::string channels;
			for (t_channel_map::const_iterator it = _channel_map.begin(); it != _channel_map.end(); ++it)
			{
				if (!channels.empty())
				{
					channels += ' ';
				}
				channels += it->first;
			}
			return channels;
		}

	private:
		typedef void (Monitorer::*pfonc)(void);
		typedef std::map<std::string, pfonc>			t_cmd_map;
		typedef std::set<User*>							t_clients;
		typedef	std::map<std::string, Channel*>			t_channel_map;


		t_cmd_map								_cmd;
		t_clients								_clients;
		t_channel_map							_channel_map;
		std::string 							_pass;

// Context
		User*			user;
		Message*		request;

		void	cmd_pass		(void);
		void	cmd_cap			(void);
		void	cmd_nick		(void);
		void	cmd_user		(void);
		void	cmd_ping		(void);
		void	cmd_quit		(void);
		void	cmd_whois		(void);
		void	cmd_who			(void);
		void	cmd_mode		(void);
		void	cmd_join		(void);
		void	cmd_privmsg		(void);
		void	cmd_kick		(void);
		void	cmd_invite		(void);
		void	cmd_topic		(void);
		void	cmd_unknown		(void);
		void	cmd_marvin		(void);

		User*		findClient(std::string name);
		Channel*	find_or_create_channel(std::string name);
		Channel*	find_channel(std::string name);

};

#endif
