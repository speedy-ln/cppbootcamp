/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkadime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 10:13:22 by lnkadime          #+#    #+#             */
/*   Updated: 2017/05/22 10:13:25 by lnkadime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char     to_upper(int c)
{
    if (c >= 97 && c <= 122)
    {
        c = c - 32;
        return (c);
    }
    else
        return (c);
}

int main(int argc, char **argv)
{
    int     j = 0;
    for (int i = 1; i < argc; ++i)
    {
        j = 0;
        while (argv[i][j])
        {
            std::cout << to_upper(argv[i][j]);
            j++;
        }
    }
    std::cout << std::endl;
    return (0);
}