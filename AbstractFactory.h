//
// Created by ebonitesh0ut on 06.06.2022.
//

#ifndef UNTITLED1_ABSTRACTFACTORY_H
#define UNTITLED1_ABSTRACTFACTORY_H
#include "Survey.h"

namespace Factory
{
    class AbstractFactory
    {
    protected:
        int id = 0;
    public:
        virtual Survey::BaseSurvey* CreateProduct() = 0;
    };

    class SurveyFactory : public AbstractFactory
    {
    public:
        Survey::BaseSurvey* CreateProduct() override
        {
            return new Survey::SocialSurvey(id++);
        }
    };
}
#endif //UNTITLED1_ABSTRACTFACTORY_H
