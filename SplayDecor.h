//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_SPLAYDECOR_H
#define UNTITLED1_SPLAYDECOR_H
#include "SplayTree.h"
#include "BaseDecorator.h"

namespace Decorators
{
    class SplayDecor : public BaseDecorator
    {
    protected:
        class StrategeSearchId : public Stratege
        {
        public:
            virtual ~StrategeSearchId() {}
            int compare(const Survey::BaseSurvey* r, const Survey::BaseSurvey* l)
            {
                if (r->surveyid == l->surveyid) return 0;
                else if (r->surveyid > l->surveyid) return 1;
                else return -1;
            }
        };

        class StrategeSearchGen : public Stratege
        {
        public:
            virtual ~StrategeSearchGen() {}
            int compare(const Survey::BaseSurvey* r, const Survey::BaseSurvey* l)
            {
                if (r->gender == l->gender) return 0;
                else if (r->gender > l->gender) return 1;
                else return -1;
            }
        };

        class StrategeSearchCitizenShip : public Stratege
        {
        public:
            virtual ~StrategeSearchCitizenShip() {}
            int compare(const Survey::BaseSurvey* r, const Survey::BaseSurvey* l)
            {
                if (r->citizen == l->citizen) return 0;
                else if (r->citizen > l->citizen) return 1;
                else return -1;
            }
        };

        class StrategeSearchEducationLevel : public Stratege
        {
        public:
            virtual ~StrategeSearchEducationLevel() {}
            int compare(const Survey::BaseSurvey* r, const Survey::BaseSurvey* l)
            {
                if (r->educationLevel == l->educationLevel) return 0;
                else if (r->educationLevel > l->educationLevel) return 1;
                else return -1;
            }
        };


        class StrategeSearchWorking : public Stratege
        {
        public:
            virtual ~StrategeSearchWorking() {}
            int compare(const Survey::BaseSurvey* r, const Survey::BaseSurvey* l)
            {
                if (r->working == l->working) return 0;
                else if (r->working > l->working) return 1;
                else return -1;
            }
        };

        SplayTree<Survey::BaseSurvey*> container;
    public:

        ostream& operator<<(ostream& stream) override
        {
            return stream;
        }


        int Add(Survey::BaseSurvey* const value) override
        {
            genderCount[value->gender]++;
            educationLevelCount[value->educationLevel]++;
            workingCount[value->working]++;
            citizenShipCount[value->citizen]++;
            count++;
            container.Insert(value); return 1;
        }

        int Remove(Survey::BaseSurvey* const value) override
        {
            genderCount[value->gender]--;
            educationLevelCount[value->educationLevel]--;
            workingCount[value->working]--;
            citizenShipCount[value->citizen]--;
            container.Remove(value);
            count--;
            return 1;
        }

        Survey::BaseSurvey* Search(int id) override
        {
            container.SetComparator(new StrategeSearchId());
            if (container.Search(new Survey::BaseSurvey(id)) != nullptr)
                return *container.Search(new Survey::BaseSurvey(id));
            else return nullptr;
        }

        Survey::BaseSurvey* Search(const Survey::enums::Gender gen) override
        {
            container.SetComparator(new StrategeSearchId());
            if (container.SearchByGender(gen) != -1)
                return *container.Search(new Survey::BaseSurvey(container.SearchByGender(gen)));
            else return nullptr;
        }

        Survey::BaseSurvey* Search(const Survey::enums::CitizenShip citizenShip) override
        {

            container.SetComparator(new StrategeSearchId());
            if (container.SearchByCitizenship(citizenShip) != -1)
                return *container.Search(new Survey::BaseSurvey(container.SearchByCitizenship(citizenShip)));
            else return nullptr;
        }

        Survey::BaseSurvey* Search(const Survey::enums::Choice educationLevel) override
        {
            container.SetComparator(new StrategeSearchId());
            if (container.SearchByEdu(educationLevel) != -1)
                return *container.Search(new Survey::BaseSurvey(container.SearchByEdu(educationLevel)));
            else return nullptr;
        }

        Survey::BaseSurvey* Search(const Survey::enums::YesNo working) override
        {
            container.SetComparator(new StrategeSearchId());
            if (container.SearchByWorking(working) != -1)
                return *container.Search(new Survey::BaseSurvey(container.SearchByWorking(working)));
            else return nullptr;
        }
    };
}
#endif //UNTITLED1_SPLAYDECOR_H
