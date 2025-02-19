#ifndef  COURSEINFO_H
#define COURSEINFO_H
/*
* Courses class for the AVL TREE
* it contains the course information
* which is course id and marks
* it also contains the methods to get and set course id and marks
* it will be used as a member of the node class
* to store the course id and marks of the student
* we make array of courses in the node class to store the courses of the student
*/
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