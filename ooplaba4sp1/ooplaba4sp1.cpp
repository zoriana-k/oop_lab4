#include <iostream>
#include "manager.h"
#include "project.h"
#include "customer.h"
#include "employeer.h"
#include "team.h"
#include "resourceManager.h"
#include "teamLeader.h"
#include "projectController.h"

void processProject(const project& p) {
    cout << "Processing project: " << p.name << endl;
    cout << "Customer: " << p.customer <<endl;
    cout << "Budget: " << p.budget << endl;
}// функція поза межами класу

void processProject(const project* p) {
    if (p) {
        cout << "Processing project: " << p->name << endl;
        cout << "Customer: " << p->customer << endl;
        cout << "Budget: " << p->budget << endl;
    }
}//перевантажена функція

void processProjectPointer(const project* p) {
    cout << "Processing project by pointer: " << p->name << endl;
    cout << "Customer: " << p->customer << endl;
    cout << "Budget: " << p->budget << endl;
}//функція з вказівником

project createNewProject(const char* name, const char* customer, int budget) {
    project p;
    strcpy_s(p.name, name);
    strcpy_s(p.customer, customer);
    p.budget = budget;
    return p;
}// функція для створення нового об'єкта проекту і повернення його

int main() {
    manager projManager("Zavgorodnya Valeria", 37, "SuperManager", "119 Office St", "Manager", 50000, "Main Resources");//менеджер

    customer cust("Zotova Alina", 33, "KvaCommision", "789 Oak St", "Customer", "New Website", 50000, 12);//замовник
    cust.createProjectThroughManager(&projManager, "New Website", 50000);//замовник створює проект через менеджера

    employeer emp1("Nadia Suska", 28, "Angel", "101 Pine St", "Developer", 3, 5000);//робітники
    employeer emp2("Lisovska Viktoria", 35, "Fairy", "202 Maple St", "Marketer", 5, 6000);
    employeer emp3("Borishchuk Sophia", 29, "Borshch", "303 Birch St", "Tester", 2, 4000);
    employeer emp4("Petruk Kateryna", 32, "Petryk", "404 Oak St", "Backend Developer", 4, 7000);
    employeer emp5("Kolba Sergiy", 25, "Glass", "211 Pine St", "Frontend Developer", 2, 5000);

    teamLeader teamLead1("Andrii Solodyuk", 30, "Suslik", "456 Elm St", "Team Leader", 5, 10000, "Rows");//лідери
    teamLeader teamLead2("Potapskii Vladyslav", 34, "Potap", "789 Pine St", "Team Leader", 6, 13000, "Tales");

    teamLead1.resourceManager::addResource("Database");//лідери отримують ресурси
    teamLead1.resourceManager::addResource("API Tools");
    teamLead2.resourceManager::addResource("Cloud Server");
    teamLead2.resourceManager::addResource("Frontend Framework");

    team Rows(teamLead1);//назначення лідерів
    team Tales(teamLead2);

    // Призначаємо проєкт командам через менеджера
    projManager.distributeProjectToTeam(Rows);//назначаємо проект командам через менеджера
    projManager.distributeProjectToTeam(Tales);

    Tales.addEmployeer(emp1);
    Tales.addEmployeer(emp2);
    Rows.addEmployeer(emp3);
    Rows.addEmployeer(emp4);


    project* proj = cust.getProject(); // отримуємо проєкт, створений замовником
    proj->addTeam(Tales);
    proj->addTeam(Rows);
    proj->addEmployeer(emp5);  // додаємо працівників до проєкту

    // друкуємо інформацію про замовника, менеджера, команди, та працівників
    cust.printInfo();
    projManager.printInfo();
    proj->printTeams();
    proj->printEmployeer();

    return 0;
}
