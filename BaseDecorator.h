//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_BASEDECORATOR_H
#define UNTITLED1_BASEDECORATOR_H
#include <iostream>
#include <map>
#include "Survey.h"

namespace Decorators
{

    class DecorSurveyException : exception
    {
    protected:
        string error;
    public:
        string GetDetails() { return error; }
        DecorSurveyException(string errorstr) :error(errorstr) {}
    };

    class BaseDecorator
    {
    protected:
        std::map<Survey::enums::Gender, int> genderCount;
        std::map<Survey::enums::YesNo, int> workingCount;
        std::map<Survey::enums::Choice, int> educationLevelCount;
        std::map<Survey::enums::CitizenShip, int> citizenShipCount;
        int count = 0;
    public:
        virtual ostream& operator<<(ostream& stream) = 0;
        virtual int Add(Survey::BaseSurvey* const value) = 0;
        virtual int Remove(Survey::BaseSurvey* const value) = 0;

        virtual Survey::BaseSurvey* Search(const int id) = 0;
        virtual Survey::BaseSurvey* Search(const Survey::enums::Gender gen) = 0;
        virtual Survey::BaseSurvey* Search(const Survey::enums::CitizenShip citizenShip) = 0;
        virtual Survey::BaseSurvey* Search(const Survey::enums::Choice educationLevel) = 0;
        virtual Survey::BaseSurvey* Search(const Survey::enums::YesNo working) = 0;


        void printStat()
        {
            for (auto iter : genderCount)
                std::cout <<
                          iter.first << ":" << endl <<
                          "Absolute frequency = " << iter.second << endl <<
                          "Relative freauency = " << (double)iter.second / count << endl << endl;

            for (auto iter : workingCount)
                std::cout << "Is Working " <<
                          iter.first << ":" << endl <<
                          "Absolute frequency = " << iter.second << endl <<
                          "Relative freauency = " << (double)iter.second / count << endl << endl;


            for (auto iter : citizenShipCount)
                std::cout << "Citizenship " <<
                          iter.first << ":" << endl <<
                          "Absolute frequency = " << iter.second << endl <<
                          "Relative frequency = " << (double)iter.second / count << endl << endl;
        }

        void printStat(const Survey::enums::Gender gen)
        {
            std::cout <<
                      gen << ":" << endl <<
                      "Absolute frequency = " << genderCount[gen] << endl <<
                      "Relative freauency = " << (double)genderCount[gen] / count << endl;
        }

        void printStat(const Survey::enums::CitizenShip citizenShip)
        {
            std::cout <<
                      " Citizenship " << ":" << endl <<
                      "Absolute frequency = " << citizenShipCount[citizenShip] << endl <<
                      "Relative freauency = " << (double)citizenShipCount[citizenShip] / count << endl << endl;
        }

        void printStat(const Survey::enums::Choice educationLevel)
        {
            std::cout <<
                      "Absolute frequency = " << educationLevelCount[educationLevel] << endl <<
                      "Relative freauency = " << (double)educationLevelCount[educationLevel] / count << endl << endl;
        }

        void printStat(const Survey::enums::YesNo working)
        {
            std::cout <<
                      "Is working" << ":" << endl <<
                      "Absolute frequency = " << workingCount[working] << endl <<
                      "Relative freauency = " << (double)workingCount[working] / count << endl << endl;
        }
    };
}
#endif //UNTITLED1_BASEDECORATOR_H
