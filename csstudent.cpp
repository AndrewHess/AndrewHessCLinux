/*
	csstudent.cpp
	Andrew Hess
	5/3/17

	Create a Student class, ComputerScientist class, and CSStudent
	class that inherits from the other two to see how multiple 
	inheritance works.
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
			cout << "Name: " << name << endl;
			
			cout << "Languages: ";
			for (int i = 0; i < languages.size() -1; i++) cout << languages[i] << ", ";
			cout << languages[languages.size() -1] << endl;

			cout << "School: " << school << endl;
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
			cout << "Name: " << name << endl;

			cout << "Languages: ";
			for (int i = 0; i < languages.size() -1; i++) cout << languages[i] << ", ";
			cout << languages[languages.size() -1] << endl;

			cout << "Employer: " << employer << endl;
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

		void setSLangs(vector<string> langs) {
			Student::setLanguages(langs);
		}

		void addSLang(string lang) {
			Student::addLanguage(lang);
		}

		vector<string> getCSLangs() {
			return ComputerScientist::getLanguages();
		}

		void setCSLangs(vector<string> langs) {
			ComputerScientist::setLanguages(langs);
		}

		void addCSLang(string lang) {
			ComputerScientist::addLanguage(lang);
		}

		void addAward(string a) {
			awards.push_back(a);
		}

		virtual void printAtts() {
			cout << "Name: " << getName() << endl;

			vector<string> langs = getSLangs();
			cout << "Spoken Languages: ";

			for (int i = 0; i < langs.size() -1; i++) cout << langs[i] << ", ";
			cout << langs[langs.size() -1] << endl;

			langs = getCSLangs();
			cout << "Coding Languages: ";

			for (int i = 0; i < langs.size() -1; i++) cout << langs[i] << ", ";
			cout << langs[langs.size() -1] << endl;

			cout << "School: " << getSchool() << endl;
			cout << "Employer: " << getEmployer() << endl;
			
			cout << "Awards: ";
			for (int i = 0; i < awards.size() -1; i++) cout << awards[i] << ", ";
			cout << awards[awards.size() -1] << endl;
		}
};


int main() {
	// setup the variables to make instances of the classes
	string name = "Andrew";

	vector<string> slangs;
	slangs.push_back("English");
	slangs.push_back("French");

	string schl = "ASFA";

	vector<string> cslangs;
	cslangs.push_back("Python");
	cslangs.push_back("Java");
	cslangs.push_back("C");

	string emp = "HackerRank";

	vector<string> awards;
	awards.push_back("Award 1");
	awards.push_back("Award 2");

	// make an instance of each class
	Student * s = new Student(name, slangs, schl);
	ComputerScientist * cs = new ComputerScientist(name, cslangs, emp);
	CSStudent * css = new CSStudent(name, slangs, cslangs, schl, emp, awards);

	// print the student's attributes
	cout << "Student: " << endl;
	s->printAtts();
	cout << "-------------------------------" << endl << endl;;

	// change some of the student's attributes
	s->addLanguage("Italian");
	s->setSchool("Caltech");
	s->setName("Andrew Hess");

	// print the student's new attributes
	cout << "Student: " << endl;
	s->printAtts();
	cout << "-------------------------------" << endl << endl;

	// print the comptuer scientist's attributes
	cout << "Computer Scientist: " << endl;
	cs->printAtts();
	cout << "-------------------------------" << endl << endl;

	// change their attributes
	cs->addLanguage("C++");
	cs->setEmployer("JPL");
	
	// print out their new attributes
	cout << "Computer Scientist: " << endl;
	cs->printAtts();
	cout << "-------------------------------" << endl << endl;

	// cast the CSStudent to Student and ComputerScientist
	s = static_cast<Student *>(css);
	cs = static_cast<ComputerScientist *>(css);

	// should use the CSStudent printAtts method
	cout << "CS Student as Student: " << endl;
	s->printAtts();
	cout << "------------------------------" << endl << endl;

	// change some attributes of cs and css
	cs->setName("Andrew Hess");
	cs->addLanguage("C++");
	cs->setEmployer("JPL");
	css->addAward("Award 3");
	css->setSchool("Caltech");

	// print the attributes, should use the CSStudent printAtts method
	cout << "CS Student as Computer Scientist: " << endl;
	cs->printAtts();

	return 0;
}
