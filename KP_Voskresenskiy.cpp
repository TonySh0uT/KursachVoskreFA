#include <iostream>
#include <fstream>
#include "UserDialog.h"
#include "AbstractFactory.h"
#include "Decorators.h"

using namespace std;

int CreateForms(Decorators::BaseDecorator* container, Factory::AbstractFactory* factory)
{
    int n;
    char RandOrMan;
    cout << "Randomize forms or manual input?\nR - for randomize\nM - for manual input \n(R by default or incorrect input):\n";
    cin >> RandOrMan;
    cout << "How many surveys should be created?\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (RandOrMan == 'M')
        {
            Survey::BaseSurvey* var = factory->CreateProduct();
            var->operator>>(cin);
            container->Add(var);
        }
        else
            container->Add(factory->CreateProduct());
    }
    return 0;
}

Survey::BaseSurvey* SearchForms(Decorators::BaseDecorator* container)
{
    UserDialog::menuSearch();
    int a;
    Survey::BaseSurvey* var;
    cin >> a;
    switch (a)
    {
        case 1:
            int id;
            cout << "\nInput id :";
            cin >> id;
            var = container->Search(id);
            if (var != nullptr)
                cout << var->print();
            else cout << "\nForm not found\n";
            return var;
        case 2:
            Survey::enums::YesNo answerYN;
            cout << "\nInput working: ";
            cin >> answerYN;
            var = container->Search(answerYN);
            if (var != nullptr) {
                cout << var->print();
                return var;
            }
            else cout << "\nForm not found\n";
            var = nullptr;
            return var;
        case 3:
            Survey::enums::Gender answerG;
            cout << "\nInput gender: ";
            cin >> answerG;
            var = container->Search(answerG);
            if (var != nullptr)
                cout << var->print();
            else cout << "\nForm not found\n";
            return var;
        case 4:
            Survey::enums::Choice answerC;
            cout << "\nInput education level: ";
            cin >> answerC;
            var = container->Search(answerC);
            if (var != nullptr)
                cout << var->print();
            else cout << "\nForm not found\n";
            return var;
        case 5:
            Survey::enums::CitizenShip answerCS;
            cout << "\nInput CitizenShip: ";
            cin >> answerCS;
            var = container->Search(answerCS);
            if (var != nullptr)
                cout << var->print();
            else cout << "\nForm not found\n";
            return var;
        default:
            cout << "\nTry again\n";
            break;
    }
    return 0;
}

int DeleteForms(Decorators::BaseDecorator* container)
{
    Survey::BaseSurvey* var = SearchForms(container);
    if (var == NULL) return 0; else
    if (container->Remove(var))
        cout << "\nForm deleted" << endl;

    return 0;
}


int GetStats(Decorators::BaseDecorator* container)
{
    container->printStat();
    cout << endl;
    return 0;
}

int Exit()
{
    cout << "Programm closing..";
    return 1;
}

Decorators::BaseDecorator* ContainerChoice()
{
    int a;
    cout << "Input engine" << endl;
    cout << "0 - deque\nany number - SplayTree:" << endl ;
    cin >> a;
    if (a == 0) return new Decorators::QueueDecor();
    else return new Decorators::SplayDecor();
}

int main()
{
    int input;
    Decorators::BaseDecorator* container = ContainerChoice();
    Factory::AbstractFactory* factory = new Factory::SurveyFactory;
    while (true)
    {
        UserDialog::userMenu();
        cin >> input;
        switch (input)
        {
            case 1:
                CreateForms(container, factory);
                break;
            case 2:
                DeleteForms(container);
                break;
            case 3:
                try
                {
                    SearchForms(container);
                }
                catch(Decorators::DecorSurveyException excep)
                {
                    std::cout << "Searching the form failed because of exception: " << excep.GetDetails() << endl;
                }
                break;
            case 4:
                GetStats(container);
                break;
            case 5:
                return Exit();
            default:
                break;
        }
    }
}