/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SocketConnection.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:37:08 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKETCONNECTION_HPP
# define SOCKETCONNECTION_HPP

# include <netinet/in.h>
# include <string>
# include "IQueue.hpp"
# include <stdexcept>
# include <unistd.h>

# define BUFFER_LEN	512

# include "Colors.hpp"
# define DEBUG_CALL_SOCKET_CONNECTION_CONSTRUCTOR \
	PRINT_DEBUG_CALL_MESSAGE(CYAN, "", SocketConnection, RESET << " -> ")

# define DEBUG_CALL_SOCKET_CONNECTION_DESTRUCTOR \
	PRINT_DEBUG_CALL_MESSAGE(CYAN, "", SocketConnection, RESET << " -> ")

class SocketConnection : public IQueue::IEventListener
{
	private:
		IQueue					&_queue;
		int						_fd;
		struct sockaddr			_addr;
		socklen_t				_addr_len;
		char					_buffer[BUFFER_LEN];

		std::string				_read_cache, _write_cache;

	protected:
		~SocketConnection();
		int				getFD(void)	const;
		std::string&	getReadCache(void);
		void			setSendCache(std::string message);

	public:
		SocketConnection(IQueue &queue, int fd_socketBind);

		void			read(void);
		void			write(void);
};

#endif
