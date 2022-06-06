//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_DEQUEDECOR_H
#define UNTITLED1_DEQUEDECOR_H
#include <Deque>
#include "BaseDecorator.h"

namespace Decorators
{
    class QueueDecor : public BaseDecorator
    {
    protected:
        deque<Survey::BaseSurvey*> container;
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
            container.push_back(value); return 1;
        }

        int Remove(Survey::BaseSurvey* const value) override
        {
            deque<Survey::BaseSurvey*> copy;
            Survey::BaseSurvey* item;
            while (((item = container.front()) != value) && !container.empty())
            {
                item = container.front();
                container.pop_front();
                copy.push_back(item);
            }

            if (container.empty()) { container = copy; return -1; }
            container.pop_front();
            while (!container.empty())
            {
                copy.push_back(container.front());
                container.pop_front();
            }
            genderCount[item->gender]--;
            educationLevelCount[item->educationLevel]--;
            workingCount[item->working]--;
            citizenShipCount[item->citizen]--;
            count--;
            container = copy;
            return 1;
        }

        Survey::BaseSurvey* Search(const int id) override
        {
            deque<Survey::BaseSurvey*> copy;
            Survey::BaseSurvey* item = nullptr;
            while (!container.empty() && ((item = container.front())->surveyid != id))
            {
                container.pop_front();
                copy.push_back(item);
                if (container.empty())break;
            }
            if (container.empty()) {
                container = copy;
                return nullptr;
            }
            while (!container.empty())
            {
                copy.push_back(container.front());
                container.pop_front();
            }
            container = copy;
            return item;
        }

        Survey::BaseSurvey* Search(const Survey::enums::Gender gen) override
        {
            deque<Survey::BaseSurvey*> copy;
            Survey::BaseSurvey* item = nullptr;
            while (!container.empty() && ((item = container.front())->gender != gen))
            {
                container.pop_front();
                copy.push_back(item);
                if (container.empty())break;
            }

            if (container.empty()) {
                container = copy;
                return nullptr;
            }
            while (!container.empty())
            {
                copy.push_back(container.front());
                container.pop_front();
            }
            container = copy;
            return item;
        }

        Survey::BaseSurvey* Search(const Survey::enums::CitizenShip citizenShip) override
        {
            deque<Survey::BaseSurvey*> copy;
            Survey::BaseSurvey* item = nullptr;
            while (!container.empty() && ((item = container.front())->citizen != citizenShip))
            {
                container.pop_front();
                copy.push_back(item);
                if (container.empty())break;
            }
            if (container.empty()) {
                container = copy;
                return nullptr;
            }
            while (!container.empty())
            {
                copy.push_back(container.front());
                container.pop_front();
            }
            container = copy;
            return item;
        }



        Survey::BaseSurvey* Search(const Survey::enums::Choice educationLevel) override
        {
            deque<Survey::BaseSurvey*> copy;
            Survey::BaseSurvey* item = nullptr;
            while (!container.empty() && ((item = container.front())->educationLevel != educationLevel))
            {
                container.pop_front();
                copy.push_back(item);
                if (container.empty())break;
            }
            if (container.empty()) {
                container = copy;
                return nullptr;
            }
            while (!container.empty())
            {
                copy.push_back(container.front());
                container.pop_front();
            }
            container = copy;
            return item;
        }


        Survey::BaseSurvey* Search(const Survey::enums::YesNo working) override
        {
            deque<Survey::BaseSurvey*> copy;
            Survey::BaseSurvey* item = nullptr;
            while (!container.empty() && ((item = container.front())->working != working))
            {
                container.pop_front();
                copy.push_back(item);
                if (container.empty())break;
            }
            if (container.empty()) {
                container = copy;
                return nullptr;
            }
            while (!container.empty())
            {
                copy.push_back(container.front());
                container.pop_front();
            }
            container = copy;
            return item;
        }
    };
}
#endif //UNTITLED1_DEQUEDECOR_H
