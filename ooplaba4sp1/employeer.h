#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "person.h"

class employeer : public person {
private:
    int experience;
    int taskBudget;
    vector<string> assignedTasks;

public:
    employeer(const char* name, int age, const char* ID, const std::string& address, const std::string& position, int experience, int taskBudget)
        : person(name, age, ID, address, position), experience(experience), taskBudget(taskBudget) {}// Конструктор з параметрами

    // Метод для виведення інформації про робітника
    void printInfo() const override {
        person::printInfo();
        cout << "Experience: " << experience << " years\nTask Budget: $" << taskBudget << endl;
    }

    // Метод для додавання завдання
    void assignTask(const string& task) {
        assignedTasks.push_back(task);
    }

    // Метод для виведення списку завдань
    void printAssignedTasks() const {
        cout << "Assigned Tasks: \n";
        for (const auto& task : assignedTasks) {
            cout << "- " << task << endl;
        }
    }

    //Деструктор
    ~employeer() {
        cout << "Employeer destroyed\n";
    }

    void setTaskBudget(int amount) {
        taskBudget = amount;
    }

    void addResource(const string& resource) {
        assignedResources.push_back(resource);
    }

    // Список ресурсів, призначених робітнику
private:
    vector<string> assignedResources;

};