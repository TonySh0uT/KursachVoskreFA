//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_USERDIALOG_H
#define UNTITLED1_USERDIALOG_H
#include <iostream>
#include <string>
#include <map>
using namespace std;

namespace UserDialog
{
    static const void userMenu()
    {
        std::cout << "Select item:" << endl <<
                  "\t1. " << "Create new form" << endl <<
                  "\t2. " << "Delete form" << endl <<
                  "\t3. " << "Search form" << endl <<
                  "\t4. " << "Get statistic" << endl <<
                  "\t5. " << "Exit" << endl << endl;
    }


    static const void menuSearch()
    {
        std::cout << "Select a search term: " << endl <<
                  "1. " << "Select survey id: " << endl <<
                  "2. " << "Search by working: " << endl <<
                  "3. " << "Search by gender: " << endl <<
                  "4. " << "Search by education level: " << endl <<
                  "5. " << "Select by citizenship" << endl;

    }
}
#endif //UNTITLED1_USERDIALOG_H
