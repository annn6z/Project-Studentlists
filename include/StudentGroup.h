#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H

#include <string>
#include <vector>
#include "Student.h"

/**
 * Класс StudentGroup представляет учебную группу студентов
 * Хранит название группы и список студентов
 */
class StudentGroup {
private:
    std::string groupName;              // Название группы
    std::vector<Student> students;      // Список студентов в группе

public:
    // Конструкторы
    StudentGroup();                                      // Конструктор по умолчанию
    StudentGroup(const std::string& name);               // Конструктор с названием группы

    // Геттеры
    std::string getGroupName() const;
    int getStudentCount() const;

    // Сеттеры
    void setGroupName(const std::string& name);

    // Основные методы работы с группой
    void addStudent(const Student& student);             // Добавить студента в группу
    Student* findStudentById(int id);                    // Найти студента по ID
    const Student* findStudentById(int id) const;        // Константная версия для поиска

    double calculateGroupAverage() const;                // Вычислить средний балл по группе
    void printAllStudents() const;                       // Вывести информацию о всех студентах

    // Метод для демонстрации работы (по желанию)
    void addGradeToStudent(int studentId, int grade);    // Добавить оценку студенту по ID
};

#endif
