/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkadime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 10:32:49 by lnkadime          #+#    #+#             */
/*   Updated: 2017/05/22 10:32:51 by lnkadime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact addContact(Contact *contact)
{
    std::cout << "What's your first name?";
    std::getline(std::cin, contact->first_name);
    std::cout << "What's your last name?";
    std::getline(std::cin, contact->last_name);
    std::cout << "What's your nickname?";
    std::getline(std::cin, contact->nickname);
    std::cout << "What's your login?";
    std::getline(std::cin, contact->login);
    std::cout << "What's your postal_address?";
    std::getline(std::cin, contact->postal_address);
    std::cout << "What's your email?";
    std::getline(std::cin, contact->email);
    std::cout << "What's your phone_number?";
    std::getline(std::cin, contact->phone_number);
    std::cout << "What's your birthday?";
    std::getline(std::cin, contact->birthday);
    std::cout << "What's your favourite_meal?";
    std::getline(std::cin, contact->favourite_meal);
    std::cout << "What's your underwear_colour?";
    std::getline(std::cin, contact->underwear_colour);
    std::cout << "What's your darkest_secret?";
    std::getline(std::cin, contact->darkest_secret);
}

int main ()
{
    std::string  cmd;
    Contact     phonebook[8];
    Contact     contact;
    int         i = 0;
    std::cout << "Enter a command...";
    while (1)
    {
        std::cout << ">> ";
        std::getline (std::cin, cmd);
        if (cmd == "EXIT")
            break;
        else if(cmd == "ADD")
        {
            for (int j = 0; j < 8; ++j)
            {
                if (i == 8)
                    std::cout << "Phonebook is full" << std::endl;
                else
                {
                    if (phonebook[j].set == 0)
                    {
                        contact.set = 1;
                        addContact(&contact);
                        phonebook[j] = contact;
                        i++;
                    }
                }
            }
        }
        else if (cmd == "SEARCH")
        {

        }
    }
    return (0);
}