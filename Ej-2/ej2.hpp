#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

class Estudiante {
    private:
        string nombreCompleto;
        int legajo;
        vector<tuple<string, float>> cursos; 

    public:
        Estudiante(string nombreCompleto, int legajo);
        string getName();
        int getLegajo();
        float getAverage();
        void addCourse(string course, float grade);
        void removeCourse(string course);
        bool operator< (const Estudiante& other);

        friend ostream& operator<< (ostream& os, const Estudiante& estudiante);
};

class Curso {
    private:
        vector<shared_ptr<Estudiante>> estudiantes;
        size_t size;
        size_t max_capacity;
        string name;

    public:
        Curso(string cname);
        vector<shared_ptr<Estudiante>> getStudents();
        int getSize();
        int getMaxCapacity();
        string getName();

        void setName(string name) { this->name = name; }
        void setStudents(vector<shared_ptr<Estudiante>> estudiantes);
        void setSize(int size);
        void setMaxCapacity(int max_capacity);
        
        bool isFull();
        void addStudent(shared_ptr<Estudiante> estudiante);
        void removeStudent(shared_ptr<Estudiante> estudiante);
        bool isInCourse(int legajo);
        void printStudents();
        void printStudentsOrdered();
        void deepCopy(vector<shared_ptr<Estudiante>> estudiantes);
};

