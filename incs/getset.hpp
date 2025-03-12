/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getset.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:27:08 by juchene           #+#    #+#             */
/*   Updated: 2024/02/01 20:31:44 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETSET_HPP
# define GETSET_HPP

template <typename T>
class	getter
{
	public:
		virtual const T&	get(void) = 0;
};

template <typename T>
class	setter
{
	public:
		virtual void	set(T&) = 0;
};

template <typename T>
class	get_set : public getter<T>, public setter<T>
{
	private:
		T	_value;

	public:
		void	set(T& value)
		{
			_value = value;
		}

		const T&	get(void)
		{
			return (_value);
		}

};

#endif
