#include <iostream>
#include <vector>

class Person {
public:
    Person(std::string name, int age) : name(name), age(age) {}

    virtual void displayDetails() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

class Student : public Person {
public:
    Student(std::string name, int age, int studentID) : Person(name, age), studentID(studentID) {}

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "Student ID: " << studentID << std::endl;
    }

    int getStudentID() const {
        return studentID;
    }

private:
    int studentID;
};

class Course {
public:
    Course(std::string courseName, int courseId) : courseName(courseName), courseId(courseId) {}

    std::string getCourseName() const {
        return courseName;
    }

    int getCourseId() const {
        return courseId;
    }

private:
    std::string courseName;
    int courseId;
};

class Enrollment {
public:
    Enrollment(const Student& student, const Course& course, int enrollmentId)
        : student(student), course(course), enrollmentId(enrollmentId) {}

    void displayDetails() const {
        std::cout << "Enrollment Details:" << std::endl;
        student.displayDetails();
        std::cout << "Course: " << course.getCourseName() << std::endl;
        std::cout << "Enrollment ID: " << enrollmentId << std::endl;
    }

private:
    const Student& student;
    const Course& course;
    int enrollmentId;
};

class EnrollmentSystem {
public:
    void enrollStudent(const Student& student, const Course& course) {
        Enrollment enrollment(student, course, nextEnrollmentId++);
        enrollments.push_back(enrollment);
    }

    void displayAllEnrollments() const {
        for (const auto& enrollment : enrollments) {
            enrollment.displayDetails();
            std::cout << "------------------------" << std::endl;
        }
    }

private:
    std::vector<Enrollment> enrollments;
    static int nextEnrollmentId;
};

int EnrollmentSystem::nextEnrollmentId = 1;

int main() {
    Student student1("Christian Jay ", 20, 12345);
    Student student2("Jay Valdez", 22, 54321);

    Course course1("Advanced C++ Programming", 101);
    Course course2("Database Management", 102);

    EnrollmentSystem enrollmentSystem;

    enrollmentSystem.enrollStudent(student1, course1);
    enrollmentSystem.enrollStudent(student2, course2);

    std::cout << "All Enrollments:" << std::endl;
    enrollmentSystem.displayAllEnrollments();

    return 0;
}
