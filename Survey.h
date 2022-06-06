//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_SURVEY_H
#define UNTITLED1_SURVEY_H
#include <string>
#include <iostream>
#include <sstream>
#include "enums.h"
using namespace std;

namespace Survey
{
    using namespace enums;

    class BaseSurvey
    {
    public:

        BaseSurvey(int quoteid) : surveyid(quoteid)
        {
            age = 14 + rand() % 84;
            personid = rand() % 10000;
            gender = static_cast<Gender>(rand() % 3);
            citizen = static_cast<CitizenShip>(rand() % 4);
            status = static_cast<MarriedStatus>(rand() % 3);
            rand() % 2 == 0 ? studing = YesNo::Yes : studing = YesNo::No;
            educationLevel = static_cast<Choice>(rand() % 5);
            rand() % 2 == 0 ? working = YesNo::Yes : working = YesNo::No;
            if (!!working)
                employer = "None"; else employer = "Good person";
            name = "None";
            email = "None";
        }

        BaseSurvey(int quoteid,
                   string name,
                   int personid = rand() % 10000,
                   Gender gender = static_cast<Gender>(rand() % 3),
                   int age = 14 + rand() % 84,
                   string email = "autogen",
                   CitizenShip currentcountry = static_cast<CitizenShip>(rand() % 4),
                   MarriedStatus status = static_cast<MarriedStatus>(rand() % 3),
                   YesNo studing = rand() % 2 == 0 ? YesNo::Yes : YesNo::No,
                   Choice educationLevel = static_cast<Choice>(rand() % 5),
                   YesNo working = rand() % 2 == 0 ? YesNo::Yes : YesNo::No,
                   string employer = "autogen",
                   CitizenShip citizen = static_cast<CitizenShip>(rand() % 4))
                :
                surveyid(quoteid),
                name(name), personid(personid), gender(gender), age(age), email(email),
                currentcountry(currentcountry), status(status), studing(studing), educationLevel(educationLevel),
                working(working), employer(employer), citizen(citizen)
        {}

    public:
        int surveyid;
        string name;
        int personid;
        Gender gender;
        int age;
        string email;
        CitizenShip currentcountry;
        MarriedStatus status;
        YesNo studing;
        Choice educationLevel;
        YesNo working;
        string employer;
        CitizenShip citizen;

    public:

        string print() const
        {
            operator<<(cout);
            stringstream ss;
            ss << cout.rdbuf();
            return ss.str();
        }

        virtual	istream& operator>>(istream& stream)
        {
            cout << "\nInput id : ";
            stream >> surveyid;
            cout << endl << "\nInput name : \n";
            stream >> name;
            cout << endl << "\nInput personid : \n";
            stream >> personid;
            cout << endl << "\nInput gender : \n";
            stream >> gender;
            cout << endl << "\nInput age: \n";
            stream >> age;
            cout << endl << "\nInput email: \n";
            stream >> email;
            cout << endl << "\nInput married status: \n";
            stream >> status;
            cout << endl << "\nInput studing: \n";
            stream >> studing;
            cout << endl << "\nInput education level: \n";
            stream >> educationLevel;
            cout << endl << "\nInput working: \n";
            stream >> working;
            cout << endl << "\nInput employer: \n";
            stream >> employer;
            cout << endl << "\nInput citizen: \n";
            stream >> citizen;
            return stream;
        }

        virtual ostream& operator<<(ostream& stream) const
        {
            stream << "\nid: " << surveyid << endl
                   << "name: " << name << endl
                   << "personid: " << personid << endl
                   << "gender: " << gender << endl << "age : " << age << endl
                   << "email: " << email << endl
                   << "status: " << status << endl
                   << "studing: " << studing << endl
                   << "education level:" << educationLevel << endl
                   << "Working: " << working << endl
                   << "Employer: " << employer << endl
                   << "Citizen: " << citizen << endl;
            return stream;
        }

        virtual bool operator==(BaseSurvey* surv)
        {
            return surveyid == surv->surveyid;
        }
    };

    class SocialSurvey final : public BaseSurvey
    {

    public:
        SocialSurvey(int quoteid)
                : BaseSurvey(quoteid)
        {
            city = "autogen city", district = "autogen district", street = "autogen street";
            rand() % 2 == 0 ? rightKnowlage = YesNo::Yes : rightKnowlage = YesNo::No;
            greenOrBlacktea = static_cast<YesNo>(rand() % 4);
            catOrDogs = static_cast<YesNo>(rand() % 4);
            surveyRate = static_cast<YesNo>(rand() % 4);
        }

        SocialSurvey(int quoteid,
                     string name,
                     int personid,
                     Gender gender,
                     int age,
                     string email,
                     CitizenShip currentcountry,
                     MarriedStatus status,
                     YesNo studing,
                     Choice educationLevel,
                     YesNo working,
                     string employer,
                     CitizenShip citizen,
                     string city,
                     string district,
                     string street,
                     YesNo greenOrBlacktea,
                     YesNo rightKnowlage,
                     YesNo catOrDogs,
                     YesNo surveyRate
        )
                : BaseSurvey(quoteid,
                             name,
                             personid,
                             gender,
                             age,
                             email,
                             currentcountry,
                             status,
                             studing,
                             educationLevel,
                             working,
                             employer,
                             citizen),
                  city(city), district(district),
                  street(street), greenOrBlacktea(greenOrBlacktea),
                  rightKnowlage(rightKnowlage), catOrDogs(catOrDogs),
                  surveyRate(surveyRate)
        {}


    public:
        string city;
        string district;
        string street;
        YesNo greenOrBlacktea;
        YesNo rightKnowlage;
        YesNo catOrDogs;
        YesNo surveyRate;
    public:

        istream& operator>>(istream& stream) override final
        {
            BaseSurvey::operator>>(stream);
            cout << endl << "\nInput city: ";
            stream >> city;
            cout << endl << "\nInput district: ";
            stream >> district;
            cout << endl << "\nInput street: ";
            stream >> street;
            cout << endl << "\nLike green tea? ";
            stream >> greenOrBlacktea;
            cout << endl << "\nU feel good right? ";
            stream >> rightKnowlage;
            cout << endl << "\nLike cats? ";
            stream >> catOrDogs;
            cout << endl << "\nLike this surway? ";
            stream >> surveyRate;
            return stream;
        }

        ostream& operator<<(ostream& stream) const override final
        {
            BaseSurvey::operator<<(stream);
            return stream << "Place of living:\n" << "City: " << city << "\ndistrict: " << district << "\nstreet: " << street << endl << endl;
        }
    };
}
#endif //UNTITLED1_SURVEY_H
