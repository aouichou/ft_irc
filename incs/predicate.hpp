/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicate.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:34:51 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:34:54 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREDICATE_HPP
# define PREDICATE_HPP

template <typename Data>
class predicate {
	public:
		virtual bool operator () (Data) = 0;
};

#endif
