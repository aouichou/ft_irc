/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICrud.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:33:34 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 21:13:33 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICrud_HPP
# define ICrud_HPP

# include "IQueue.hpp"

class ICrud
{
	public:
		virtual void	treatEventListener(IQueue::IEventListener*)		= 0;
		virtual void	addEventListener(IQueue&, int)					= 0;
		virtual void	removeEventListener(IQueue::IEventListener*)	= 0;
};

#endif
