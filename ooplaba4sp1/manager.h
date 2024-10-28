#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "person.h"
#include "project.h"
#include "team.h"
#include "employeer.h"

class manager : public person {
private:
    int totalBudget;
    vector<string> teams;
    string projectResources; 

public:
    // ����������� � �����������
    manager(const char* name, int age, const char* ID, const string& address, const string& position, int totalBudget, const string& resources)
        : person(name, age, ID, address, position), totalBudget(totalBudget), projectResources(resources) {}

    // ����� ��� ��������� ���������� ��� ���������
    void printInfo() const override {
        person::printInfo();
        cout << "Total Budget: $" << totalBudget << "\nResources: " << projectResources << endl;
    }

    // ����� ��� ��������� ���� �������
    void addTeam(const string& teamName) {
        teams.push_back(teamName);
    }

    // ����� ��� ��������� ������ ������
    void printTeams() const {
        cout << "Teams managed: \n";
        for (const auto& team : teams) {
            cout << "- " << team << endl;
        }
    }

    //����������
    ~manager() {
        cout << "Manager destroyed\n";
    }

    // ����� ��� ����������� ������� ���������
    void assignProject(project* proj) {
        managedProjects.push_back(proj);
    }

    // ����� ��� �������� ������� �� ���������
    void distributeProjectToTeam(team& teamObj) {
        assignedTeams.push_back(&teamObj);
    }

    // ����� ��� �������� ������� �� ����������
    void assignBudget(employeer& emp, int amount) {
        emp.setTaskBudget(amount);
    }

    // ����� ��� �������� ������� �� ����������
    void assignResources(employeer& emp, const string& resource) {
        emp.addResource(resource);
    }

    // ������ ��������� �������
private:
    vector<project*> managedProjects;
    vector<team*> assignedTeams;

};