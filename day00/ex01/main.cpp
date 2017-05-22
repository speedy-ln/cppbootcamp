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

void    addContact(Contact *contact)
{
    do {
        std::cout << "What's your first name?" << std::endl;
        std::getline(std::cin, contact->first_name);
    } while(contact->first_name.empty());

    do {
        std::cout << "What's your last name?" << std::endl;
        std::getline(std::cin, contact->last_name);
    } while(contact->last_name.empty());

    do {
        std::cout << "What's your nickname?" << std::endl;
        std::getline(std::cin, contact->nickname);
    } while(contact->nickname.empty());

    do {
        std::cout << "What's your login?" << std::endl;
        std::getline(std::cin, contact->login);
    } while(contact->login.empty());

    do {
        std::cout << "What's your postal_address?" << std::endl;
        std::getline(std::cin, contact->postal_address);
    } while(contact->postal_address.empty());

    do {
        std::cout << "What's your email?" << std::endl;
        std::getline(std::cin, contact->email);
    } while(contact->email.empty());

    do {
        std::cout << "What's your phone_number?" << std::endl;
        std::getline(std::cin, contact->phone_number);
    } while(contact->phone_number.empty());

    do {
        std::cout << "What's your birthday?" << std::endl;
        std::getline(std::cin, contact->birthday);
    } while(contact->birthday.empty());

    do {
        std::cout << "What's your favorite_meal?" << std::endl;
        std::getline(std::cin, contact->favorite_meal);
    } while(contact->favorite_meal.empty());

    do {
        std::cout << "What's your underwear_color?" << std::endl;
        std::getline(std::cin, contact->underwear_color);
    } while(contact->underwear_color.empty());

    do {
        std::cout << "What's your darkest_secret?" << std::endl;
        std::getline(std::cin, contact->darkest_secret);
    } while(contact->darkest_secret.empty());

}

void    truncate(std::string string)
{
    if (string.length() > 10)
        std::cout << string.substr(0, 9) << '.';
    else
        std::cout << std::setw(10) << string;
}

void    searchContact(Contact phonebook[8], int num_contacts)
{
    int index;
    char str[3];
    std::cout << '|';
    std::cout << std::setw(10) << "Index";
    std::cout << "|";
    std::cout << std::setw(10) << "First name";
    std::cout << "|";
    std::cout << std::setw(10) << "Last name";
    std::cout << "|";
    std::cout << std::setw(10) << "Nickname";
    std::cout << "|" << std::endl;
    for (int i = 0; i < num_contacts; ++i)
    {
        std::cout << '|';
        std::cout << std::setw(10) << (i+1);
        std::cout << '|';
        truncate(phonebook[i].first_name);
        std::cout << '|';
        truncate(phonebook[i].last_name);
        std::cout << '|';
        truncate(phonebook[i].nickname);
        std::cout << "|" << std::endl;
    }
    std::cout << "Pick an index:" << std::endl;
    std::cin >> str;
    index = str[0] - '0';
    if (0 < index && index < (num_contacts + 1))
    {
        index -= 1;
        std::cout << "First name: " << phonebook[index].first_name << std::endl;
        std::cout << "Last name: " << phonebook[index].last_name << std::endl;
        std::cout << "Nickname: " << phonebook[index].nickname << std::endl;
        std::cout << "Login: " << phonebook[index].login << std::endl;
        std::cout << "Postal Address: " << phonebook[index].postal_address << std::endl;
        std::cout << "Email Address: " << phonebook[index].email << std::endl;
        std::cout << "Birthday: " << phonebook[index].birthday << std::endl;
        std::cout << "Phone number: " << phonebook[index].phone_number << std::endl;
        std::cout << "Favorite Meal: " << phonebook[index].favorite_meal << std::endl;
        std::cout << "Underwear Color: " << phonebook[index].underwear_color << std::endl;
        std::cout << "Darkest Secret: " << phonebook[index].darkest_secret << std::endl;
    }
    else
        std::cout << "Invalid index." << std::endl;
}

int main ()
{
    std::string  cmd;
    Contact     phonebook[8];
    Contact     contact;
    int         num_contacts = 0;
    std::cout << "Enter a command..." << std::endl;
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
                if (num_contacts == 8)
                {
                    std::cout << "Phonebook is full" << std::endl;
                    break;
                }
                else
                {
                    if (phonebook[j].set == 0)
                    {
                        contact.set = 1;
                        addContact(&contact);
                        phonebook[j] = contact;
                        num_contacts++;
                        break;
                    }
                }
            }
        }
        else if (cmd == "SEARCH")
        {
            searchContact(phonebook, num_contacts);
        }
    }
    return (0);
}