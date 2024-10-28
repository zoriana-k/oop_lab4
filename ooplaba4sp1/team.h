#pragma once
#include "employeer.h"
#include <vector>
#include <iostream>

class team {
private:
    employeer teamLeader;            // ˳��� �������
    std::vector<employeer> members;   // ������ �������� �������

public:
    team(const employeer& leader) : teamLeader(leader) {}

    // ����� ��� ��������� ���������� � �������
    void addEmployeer(const employeer& emp) {
        members.push_back(emp);
    }

    // ����� ��� ��������� ���������� ��� ����� ������� � ��� �������� �������
    void printTeam() const {
        std::cout << "Team Leader: ";
        teamLeader.printInfo();
        std::cout << "\nTeam Members:\n";
        for (const auto& member : members) {
            member.printInfo();
            std::cout << "------------------\n";
        }
    }
};
