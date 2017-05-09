/*
	student.h
	Andrew Hess
	5/3/17

*/

#include <iostream>
#include <vector>

using namespace std;

class Student {
	private:
		string name;
		vector<string> languages;
		string school;

	public:
		Student() {
			name = "";
			school = "";
		}

		Student(string n, vector<string> langs, string schl) {
			name = n;
			languages = langs;
			school = schl;
		}

		virtual string getName() {
			return name;
		}

		virtual vector<string> getLanguages() {
			return languages;
		}

		string getSchool() {
			return school;
		}

		virtual void setName(string n) {
			name = n;
		}
	
		virtual void setLanguages(vector<string> langs) {
			languages = langs;
		}

		virtual void addLanguage(string lang) {
			languages.push_back(lang);
		}

		void setSchool(string schl) {
			school = schl;
		}

		virtual void printAtts() {
			cout << "Name: \n\t" << name << endl;
			
			cout << "Languages: " << endl;
			for (string s : languages) cout << "\t" << s << endl;

			cout << "School:\n\t" << school << endl << endl;
		}
};

class ComputerScientist {
	private:
		string name;
		vector<string> languages;
		string employer;

	public:
		ComputerScientist() {
			name = "";
			employer = "";
		}

		ComputerScientist(string n, vector<string> langs, string emp) {
			name = n;
			languages = langs;
			employer = emp;
		}

		virtual string getName() {
			return name;
		}

		virtual vector<string> getLanguages() {
			return languages;
		}

		string getEmployer() {
			return employer;
		}

		virtual void setName(string n) {
			name = n;
		}

		virtual void setLanguages(vector<string> langs) {
			languages = langs;
		}

		virtual void addLanguage(string lang) {
			languages.push_back(lang);
		}

		void setEmployer(string emp) {
			employer = emp;
		}

		virtual void printAtts() {
			cout << "Name: \n\t" << name << endl;

			cout << "Languages: " << endl;
			for (string s : languages) cout << "\t" << s << endl;

			cout << "Employer: \n\t" << employer << endl << endl;
		}
};

class CSStudent: public Student, public ComputerScientist {
	private:
		vector<string> awards;

	public:
		CSStudent(): Student(), ComputerScientist() {};

		CSStudent(string name, vector<string> slangs, vector<string> cslangs, string schl, string emp, vector<string> a): 
				Student(name, slangs, schl), ComputerScientist(name, cslangs, emp) {

			awards = a;
		}

		virtual void printAtts() {
			Student * s = static_cast<Student *>(this);

			cout << "Name: \n\t" << s->getName() << endl;

			cout << "Spoken Languages: " << endl;
			for (string str : Student::getLanguages()) cout << "\t" << str << endl;

			cout << "Coding Languages: " << endl;
			for (string str : ComputerScientist::getLanguages()) cout << "\t" << str << endl;

			cout << "School: \n\t" << getSchool() << endl;
			cout << "Employer: \n\t" << getEmployer() << endl;
			
			cout << "Awards: " << endl;
			for (string str : awards) cout << "\t" << str << endl;
		}

		virtual string getName() {
			return Student::getName();
		}

		virtual void setName(string n) {
			Student::setName(n);
			ComputerScientist::setName(n);
		}

		vector<string> getSLangs() {
			return Student::getLanguages();
		}

		vector<string> getCSLangs() {
			return ComputerScientist::getLanguages();
		}
};


int main() {
	string name = "Andrew";

	vector<string> slangs;
	slangs.push_back("English");
	slangs.push_back("French");
	slangs.push_back("Italian");

	string schl = "ASFA";

	vector<string> cslangs;
	cslangs.push_back("Python");
	cslangs.push_back("Java");
	cslangs.push_back("C");
	cslangs.push_back("C++");

	string emp = "HackerRank";

	vector<string> awards;
	awards.push_back("Award 1");
	awards.push_back("Award 2");

	Student * stu = new Student(name, slangs, schl);
	ComputerScientist * cs = new ComputerScientist(name, cslangs, emp);
	CSStudent * csstu = new CSStudent(name, slangs, cslangs, schl, emp, awards);

	cout << "Student: " << endl;
	stu->printAtts();
	cout << "-------------------------------" << endl << endl;;

	cout << "Computer Scientist: " << endl;
	cs->printAtts();
	cout << "-------------------------------" << endl << endl;

	CSStudent * css  = new CSStudent(name, slangs, cslangs, schl, emp, awards);
	Student * s = static_cast<Student *>(css);
	ComputerScientist * com = static_cast<ComputerScientist *>(css);

	cout << "CS Student as Student: " << endl;
	s->printAtts();
	cout << "------------------------------" << endl << endl;

	cout << "CS Student as Computer Scientist: " << endl;
	com->printAtts();

	cout << "printing name" << endl;
	cout << css->getName() << endl;
	return 0;
}
