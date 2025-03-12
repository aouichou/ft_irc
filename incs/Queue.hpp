/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:34:25 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:21:51 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

extern "C" {
# include <sys/epoll.h>
}

# include <unistd.h>

# include <map>
# include <stdexcept>
# include "ICrud.hpp"

# define MAX_EVENTS 32

# include "Colors.hpp"
# define DEBUG_CALL_QUEUE PRINT_DEBUG_CALL(MAGENTA, Queue)

# define DEBUG_CALL_QUEUE_UNSUBSCRIBE \
	PRINT_DEBUG_CALL_MESSAGE(MAGENTA, "", Queue, RESET << " -> ")

class Queue : public IQueue {
	private:
		int					_epoll_instance;
		struct epoll_event	*_events_list;
		size_t				_max_events;

	public:
		Queue(size_t nevents = MAX_EVENTS);
		~Queue();

		void	subscribe(int fd, IQueue::IEventListener* listener);
		void	unsubscribe(int fd);
		bool	event_loop(ICrud& crud);
};
#endif
