#include "StudentGroup.h"
#include <iostream>
#include <iomanip>

// Конструктор по умолчанию
StudentGroup::StudentGroup() : groupName("Unnamed Group") {
    std::cout << "📋 Создана группа: " << groupName << " (пустая)" << std::endl;
}

// Конструктор с названием группы
StudentGroup::StudentGroup(const std::string& name) : groupName(name) {
    std::cout << "📋 Создана группа: " << groupName << std::endl;
}

// Геттер для названия группы
std::string StudentGroup::getGroupName() const {
    return groupName;
}

// Геттер для количества студентов
int StudentGroup::getStudentCount() const {
    return students.size();
}

// Сеттер для названия группы
void StudentGroup::setGroupName(const std::string& name) {
    groupName = name;
    std::cout << "📋 Группа переименована в: " << groupName << std::endl;
}

// Добавление студента в группу
void StudentGroup::addStudent(const Student& student) {
    students.push_back(student);
    std::cout << "✅ Студент \"" << student.getName() << "\" (ID: "
              << student.getStudentId() << ") добавлен в группу " << groupName << std::endl;
}

// Поиск студента по ID (неконстантная версия - для модификации)
Student* StudentGroup::findStudentById(int id) {
    for (auto& student : students) {
        if (student.getStudentId() == id) {
            return &student;  // Возвращаем указатель на найденного студента
        }
    }
    return nullptr;  // Студент не найден
}

// Поиск студента по ID (константная версия - только для чтения)
const Student* StudentGroup::findStudentById(int id) const {
    for (const auto& student : students) {
        if (student.getStudentId() == id) {
            return &student;
        }
    }
    return nullptr;
}

// Вычисление среднего балла по группе
double StudentGroup::calculateGroupAverage() const {
    if (students.empty()) {
        std::cout << "⚠️ В группе " << groupName << " нет студентов для расчета среднего балла" << std::endl;
        return 0.0;
    }

    double totalSum = 0.0;
    int totalGrades = 0;

    for (const auto& student : students) {
        // У каждого студента может быть разное количество оценок
        // Используем метод calculateAverage, но он возвращает среднее,
        // а нам нужна сумма для расчета общего среднего
        for (int grade : student.getGrades()) {
            totalSum += grade;
            totalGrades++;
        }
    }

    if (totalGrades == 0) {
        std::cout << "⚠️ У студентов в группе " << groupName << " нет оценок" << std::endl;
        return 0.0;
    }

    double average = totalSum / totalGrades;
    std::cout << "📊 Средний балл по группе " << groupName << ": "
              << std::fixed << std::setprecision(2) << average << std::endl;
    return average;
}

// Вывод информации о всех студентах группы
void StudentGroup::printAllStudents() const {
    std::cout << "\n========================================\n";
    std::cout << "📋 ГРУППА: " << groupName << std::endl;
    std::cout << "========================================\n";

    if (students.empty()) {
        std::cout << "   В группе нет студентов" << std::endl;
    } else {
        std::cout << "   Всего студентов: " << students.size() << std::endl;
        std::cout << "----------------------------------------\n";

        for (const auto& student : students) {
            student.printInfo();
            std::cout << "----------------------------------------\n";
        }
    }
    std::cout << "========================================\n\n";
}

// Добавление оценки студенту по ID (удобный метод для тестирования)
void StudentGroup::addGradeToStudent(int studentId, int grade) {
    Student* student = findStudentById(studentId);
    if (student) {
        student->addGrade(grade);
        std::cout << "✅ Оценка " << grade << " добавлена студенту "
                  << student->getName() << " (ID: " << studentId << ")" << std::endl;
    } else {
        std::cout << "❌ Ошибка: Студент с ID " << studentId << " не найден в группе" << std::endl;
    }
}
