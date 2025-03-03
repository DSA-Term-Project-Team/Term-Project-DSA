#ifndef COURSEINFO_H
#define COURSEINFO_H
class courses {
private:
    int courseId;
    float marks;
public:
    courses(int courseId = 0, float marks = 0.0);
    int getCourseId();
    float getMarks();
    void setCourseId(int newCourseId);
    void setMarks(float newMarks);
};
#endif