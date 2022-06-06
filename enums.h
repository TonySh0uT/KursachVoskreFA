//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_ENUMS_H
#define UNTITLED1_ENUMS_H
using namespace std;
#include <string>

namespace Survey
{
    namespace enums
    {
        enum class CitizenShip : int
        {
            Russia,
            UnitedStates,
            England,
            Poland,
            China
        };

        static ostream& operator<<(ostream& stream, CitizenShip const& gen)
        {
            if (gen == CitizenShip::Russia)
                return stream << "Russia";
            else if (gen == CitizenShip::UnitedStates)
                return stream << "USA";
            else if (gen == CitizenShip::England)
                return stream << "England";
            else if (gen == CitizenShip::Poland)
                return stream << "Poland";
            else if (gen == CitizenShip::China)
                return stream << "China";


        }

        static istream& operator>>(istream& it, CitizenShip& var)
        {
            int a;
            bool correct = false;
            while (!correct)
            {
                cout << "Input citizen (1. Ru, 2. US, 3.Po, 4. Ch, default - Ru) : ";
                it >> a;
                switch (a)
                {
                    case 1:
                        correct = true;
                        var = CitizenShip::Russia;
                        break;
                    case 2:
                        correct = true;
                        var = CitizenShip::UnitedStates;
                        break;
                    case 3:
                        correct = true;
                        var = CitizenShip::Poland;
                        break;
                    case 4:
                        correct = true;
                        var = CitizenShip::China;
                        break;
                    default:
                        correct = true;
                        var = CitizenShip::Russia;
                        break;
                }
            }
            return it;
        }

        enum class YesNo : bool
        {
            Yes = true, No = false
        };

        static bool operator ! (YesNo var)
        {
            if (var == YesNo::Yes) return false;
            else return true;
        }

        static ostream& operator<<(ostream& stream, YesNo const& gen)
        {
            return stream << (gen == YesNo::Yes ? "Yes" : "No");
        }

        static istream& operator>>(istream& it, YesNo& var)
        {
            int a;
            bool correct = false;
            while (!correct)
            {
                cout << "Input yes(1)/no(2) : ";
                it >> a;
                switch (a)
                {
                    case 1:
                        correct = true;
                        var = YesNo::Yes;
                        break;
                    case 2:
                        correct = true;
                        var = YesNo::No;
                        break;
                    default:
                        cout << "Try next time : ";
                        return it;
                }
            }
            return it;
        }

        enum class Gender : int
        {
            Male,
            Female,
            AttackHelicopter
        };
        static ostream& operator<<(ostream& stream, Gender const& gen)
        {
            if (gen == Gender::Male)
                return stream << "Male";
            else if (gen == Gender::Female)
                return stream << "Female";
            else if (gen == Gender::AttackHelicopter)
                return stream << "AttackHelicopter";
        }

        static istream& operator>>(istream& it, Gender& gender)
        {
            int a;
            bool correct = false;
            while (!correct)
            {
                cout << "1. Male, 2. Female, 3.Attack helicopter : ";
                it >> a;
                switch (a)
                {
                    case 1:
                        correct = true;
                        gender = Gender::Male;
                        break;
                    case 2:
                        correct = true;
                        gender = Gender::Female;
                        break;

                    case 3:
                        correct = true;
                        gender = Gender::AttackHelicopter;
                        break;
                    default:
                        break;
                }
            }
            return it;
        }

        enum class Choice : int
        {
            Preschool,
            School,
            Middleschool,
            Highschool,
            NotGraduated
        };

        static void operator>>(istream& it, Choice& var)
        {
            int a;
            bool correct = false;
            while (!correct)
            {
                cout << "1. Preschool, 2. School, 3. Middleschool, 4. Highschool, 5. Not Graduated : ";
                it >> a;
                switch (a)
                {
                    case 1:
                        correct = true;
                        var = Choice::Preschool;
                        break;
                    case 2:
                        correct = true;
                        var = Choice::School;
                        break;
                    case 3:
                        correct = true;
                        var = Choice::Middleschool;
                        break;
                    case 4:
                        correct = true;
                        var = Choice::Highschool;
                        break;
                    case 5:
                        correct = true;
                        var = Choice::NotGraduated;
                        break;

                    default:
                        break;
                }
            }
        }
        static ostream& operator<<(ostream& stream, Choice const& gen)
        {
            if (gen == Choice::Preschool)
                return stream << "Preschool";
            else if (gen == Choice::School)
                return stream << "School";
            else if (gen == Choice::Middleschool)
                return stream << "Middleschool";
            else if (gen == Choice::Highschool)
                return stream << "Highschool";
            else
                return stream << "Not graduated";
        }


        enum class MarriedStatus : int
        {
            Married,
            InRelationship,
            Free
        };

        static ostream& operator<<(ostream& stream, MarriedStatus const& gen)
        {
            if (gen == MarriedStatus::Married)
                return stream << "Married";
            else if (gen == MarriedStatus::InRelationship)
                return stream << "In relationship";
            else if (gen == MarriedStatus::Free)
                return stream << "Free";
        }

        static void operator>>(istream& it, MarriedStatus& var)
        {
            int a;
            bool correct = false;
            while (!correct)
            {
                cout << "1. Married, 2. In Relationship, 3.Free : ";
                it >> a;
                switch (a)
                {
                    case 1:
                        correct = true;
                        var = MarriedStatus::Married;
                        break;
                    case 2:
                        correct = true;
                        var = MarriedStatus::InRelationship;
                        break;
                    case 3:
                        correct = true;
                        var = MarriedStatus::Free;
                        break;

                    default:
                        break;
                }
            }
        }
    }
}
#endif //UNTITLED1_ENUMS_H
