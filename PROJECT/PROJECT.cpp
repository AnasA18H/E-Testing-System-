#include <iostream>
#include <fstream>
#include<string>
#include <iomanip>
#include<cstdlib>
#include <conio.h>
#include <ctime>
#include <assert.h>
using std::getline;
using std::cout;
using std::cin;

using namespace std;

//global Functions ------------------------------------------------------------------------------------------------------------------------------------------------------------->

bool cheakpassword(string password, int size);
bool cheakID(string id, int size);

//Classes ------------------------------------------------------------------------------------------------------------------------------------------------------------->

class User
{
private:
	string Name;
	string ID;
	string Password;

public:

	void setID(string id) { ID = id; }
	void setName(string name) { Name = name; }
	void creatPassword(string Pass) { Password = Pass; }
	void changePassword(string PassChange) { Password = PassChange; }

	string getName() { return Name; }
	string getID() { return ID; }
	string getPassword() { return Password; }

	bool login()
	{
		string pass = "";
		string identity = "";
		cout << setw(110) << "LOGIN\n";
		cout << endl;
		cout << setw(118) << "FAST NUCES ISLAMABAD " << endl;
		cout << endl;
		cout << endl;
		cout << "Pleas Enter you ID : " << endl;
		cin >> identity;
		cout << endl;
		cout << "Pleas Enter you Password : " << endl;
		cin >> pass;

		if (identity == ID && pass == Password) { return true; }
		else
		{
			if (Password != pass)
			{
				if (ID != identity) { system("cls"); cout << "\nwrong Password and ID ! " << endl; }

				else { system("cls"); cout << "\nwrong Password ! " << endl; }

			}
			else { system("cls"); cout << "\nWrong ID ! " << endl; }

			return false;
		}
	}

	string confirmPassword()
	{
		char pass[20] = { 0 };
		char character;
		int j = 0;
		int size = 0;

		for (int i = 0; Password[i] != '\0'; i++)
			size++;

		int cheak = 0;
		cheak = cheakpassword(Password, size);
		while (cheak == 0)
		{
			cout << endl;
			cout << "The Password must contain The following :\n1. Lower Case\n1. Upper Case\n3. Digits\n4. Special Characters\n5. Lenght must be greater then 5  " << endl;
			cout << "\nEnter Password again : " << endl;

			while (j != 18)
			{
				character = _getch();

				if (character == '\b')
					j--;
				else if (character == '\r')
					break;
				else
				{
					pass[j] = character;
					j++;
					cout << "*";
				}
			}
			pass[j] = '\0';
			for (int i = 0; i < j; i++)
			{
				Password += pass[i];
			}

			size = 0;
			for (int i = 0; Password[i] != '\0'; i++)
				size++;
			cheak = cheakpassword(Password, size);
		}
		return Password;
	}
	string confirmID()
	{
		int size = 0;

		for (int i = 0; ID[i] != '\0'; i++)
			size++;

		int cheak = 0;
		cheak = cheakID(ID, size);

		while (cheak == 0)
		{
			cout << endl;
			cout << "Pleas Enter Correct ID -- ID is 7 Figur long and starts with batch number and Followed bt I ( 22I - 1987 ) : " << endl;
			cin >> ID;

			size = 0;

			for (int i = 0; ID[i] != '\0'; i++)
				size++;

			cheak = cheakID(ID, size);
		}
		return ID;
	}
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------->

class instructor : public User
{
private:
	string courses[11] = { "Programming Fundamentals","Object Oriented Programming", "Introduction To Computing", "Data Structures", "Analysis of Algorithms", "Software Requirements Engineerings", "Research Methodology", "Big Data Analytics", "Artificial Intelligence", "Deep Learning", "Digital Image Processing" };
	string courseAssigned;
	int static countteacher;


public:
	int CorrectedQuestionCourse[21] = { 0 };
	void setcourseteacher() { courseAssigned = courses[countteacher]; countteacher++; }
	string getcourseAssignedteacher() { return courseAssigned; }

	friend istream& operator>>(istream& input, instructor& in);
	friend ostream& operator<<(ostream& output, instructor& out);
};
int instructor::countteacher = 0;

//=====================================================

istream& operator>>(istream& input, instructor& in)
{
	string cp = "";

	char pass[20] = { 0 };
	char character;
	int j = 0;

	cout << "Pleas Enter you Password : " << endl;

	while (j != 18)
	{
		character = _getch();

		if (character == '\b')
			j--;
		else if (character == '\r')
			break;
		else
		{
			pass[j] = character;
			j++;
			cout << "*";
		}
	}
	pass[j] = '\0';

	for (int i = 0; i < j; i++)
	{
		cp += pass[i];
	}
	in.changePassword(cp);
	in.confirmPassword(); cout << endl;

	return input;
}

//======================================================

ostream& operator<<(ostream& output, instructor& out)
{
	output << "Your Name is : " << out.getName(); cout << endl;
	cout << endl;
	output << "Your Password is : " << out.getPassword(); cout << endl;
	output << "Your ID is : " << out.getID(); cout << endl;
	output << "Your Course is : " << out.courseAssigned; cout << endl;
	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	return output;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------->

class student : public User
{
private:
	string Course;
	int coursecode;
	float score;
	int correctedQuestions[25] = { 0 };

public:
	int i, j = 0;
	student()
	{
		score = 0;
		coursecode = 0;
		i = 0;
	}
	void setcoursestudent(string course) { Course = course; }
	string getcoursestudent() { return Course; }
	void setscore(float sc) { score = sc; }
	float getscore() { return score; }
	void setcoursestudentCode(int coursecod) { coursecode = coursecod; }
	int getcoursestudentCode() { return coursecode; }

	void correctedQuestionofStudent(int CQ)
	{
		correctedQuestions[i] = CQ;
		i++;
	}

	int getCQS()
	{
		return correctedQuestions[j];
		j++;
	}

	friend istream& operator>>(istream& input, student& in);
	friend ostream& operator<<(ostream& output, student& out);
};

//=========================================================

istream& operator>>(istream& input, student& in)
{
	string cp = "";

	char pass[20] = { 0 };
	char character;
	int j = 0;

	cout << "Pleas Enter you Password : " << endl;

	while (j != 18)
	{
		character = _getch();

		if (character == '\b')
			j--;
		else if (character == '\r')
			break;
		else
		{
			pass[j] = character;
			j++;
			cout << "*";
		}
	}
	pass[j] = '\0';


	for (int i = 0; i < j; i++)
	{
		cp += pass[i];
	}
	in.changePassword(cp);
	in.confirmPassword(); cout << endl;

	return input;
}

//========================================================
ostream& operator<<(ostream& output, student& out)
{
	output << out.getName() << "           " << out.getID() << "           " << out.getPassword() << "           " << out.getcoursestudent() << endl;

	return output;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------->

class Course
{
private:
	string Course;

public:
	void setcourse(string course) { Course = course; }
	string getcourse() { return Course; }

};
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------->
class Date
{
private:
	int Day;
	int Month;
	int Year;

public:
	Date()
	{
		Day = 0;
		Month = 0;
		Year = 0;
	}

	void setDay(int D) { Day = D; }
	void setMonth(int M) { Month = M; }
	void setYear(int Y) { Year = Y; }


	int getDay() { return Day; }
	int getMonth() { return Month; }
	int getYear() { return Year; }

};

//========================================================

class Time : public Date
{
private:
	int Hour;
	int Min;
	int Sec;

public:
	Time()
	{
		Hour = 0;
		Min = 0;
		Sec = 0;
	}

	void setH(int H) { Hour = H; }
	void setMin(int M) { Min = M; }

	int getH() { return Hour; }
	int getMin() { return Min; }


};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------->
class Quiz : public instructor
{
private:
	string QuestionNumber;
	string option;
	int Correctoption;

public:
	Quiz()
	{
		Correctoption = 0;
	}
	void setQuestionNum(string QQ) { QuestionNumber = QQ; }
	void setOption(string OO) { option = OO; }
	void setcop(int CO) { Correctoption = CO; }

	string getQuestionNumber() { return QuestionNumber; }
	string getOption() { return option; }
	int getCP() { return Correctoption; }

};

void WriteQuestions(Quiz Qpaper[], int type, string topic)
{
	int num = 1;
	char alpha = 'a';
	ofstream WriteQ;

	WriteQ.open("QuizCreated.txt", ios::app);
	if (!WriteQ) { cout << "Failed to open file -> PLease try agian or Re-chech the location of QuizCreated.txt : " << endl; assert(!WriteQ.fail()); }

	string markerM = "2efcdea";
	string markerTF = "b94d27a";
	string markerS = "88f7aca";
	char itrateQ = 'a';
	char alphachar[5] = { 'x','a','b','c','d' };
	if (type == 1)
	{
		alpha = 'a';
		int j = 0;

		for (j = 0; j < 1; j++)
		{
			char itrateMQ = 'a';
			WriteQ << "a5380ee";
			WriteQ << endl;
			WriteQ << topic;
			WriteQ << endl;
			WriteQ << endl;
			WriteQ << markerM;
			markerM[6] = ++itrateMQ;
			WriteQ << endl;
			WriteQ <<num++<< Qpaper[j].getQuestionNumber();
			WriteQ << endl;
			for (int i = 0; i < 4; i++)
			{
				WriteQ << alpha << ") " << Qpaper[i].getOption();
				alpha++;
				WriteQ << endl;
			}
			WriteQ << "dabfac4\n" <<alphachar[Qpaper[j].getCP()] << ") " << Qpaper[Qpaper[j].getCP()-1].getOption();
			WriteQ << endl;
			WriteQ << endl;
		}
	}
	if (type == 2)
	{
		int j = 0;

		for (j = 0; j < 1; j++)
		{
			char itrateTF = 'a';
			WriteQ << "a5380ee";
			WriteQ << endl;
			WriteQ << topic;
			WriteQ << endl;
			WriteQ << endl;
			WriteQ << markerTF;
			markerTF[6] = ++itrateTF;
			WriteQ << endl;
			WriteQ << num++ << Qpaper[j].getQuestionNumber();
			WriteQ << endl;
			WriteQ << "dabfac4\n" << Qpaper[j].getCP();
			WriteQ << endl;
			WriteQ << endl;
		}
	}
	if (type == 3)
	{
		for (int j = 0; j < 1; j++)
		{
			char itrateSQ = 'a';
			WriteQ << "a5380ee";
			WriteQ << endl;
			WriteQ << topic;
			WriteQ << endl;
			WriteQ << endl;
			WriteQ << markerS;
			markerS[6] = ++itrateSQ;
			WriteQ << endl;
			WriteQ << num++ << Qpaper[j].getQuestionNumber();
			WriteQ << endl;
			WriteQ << endl;
		}
	}

	WriteQ.close();
}

class QuestionSetUp : public Quiz
{

public:
	Quiz* Qpaper = new Quiz[100];
	string Quest;
	string optt;
	int cpp = 0;
	string topic;
	void GeneratePaper()
	{

		int i = 0;
		int copt = 0;
		bool t = true;
		while (t)
		{
			int type = 0;
			cout << endl;
			cout << "Specify Question Type :\n1. MCQs\n2. True/False\n3. Subjective\n4. Exit(x) " << endl;
			cout << endl;
			cout << "TASK : ";
			cin >> type;
			while (type < 1 && type > 4)
			{
				cout << "Specify Question Type :\n1. MCQs\n2. True/False\n3. Subjective\n4. Exit(x) " << endl;
				cout << endl;
				cout << "TASK : ";
				
				cin >> type;
			}
			cout << endl;
			system("cls");
			cout << endl;
			cout << "Specify Question topic : " << endl;
			cout << "Topic : ";
			cin.ignore();
			getline(cin, topic);
			cout << endl;
			if (type == 1)
			{
				int numbering = 0;
				cout << "Enter The Question statement : " << endl;
				cin.ignore();
				getline(cin, Quest);
				Qpaper[i].setQuestionNum(Quest);
				cout << endl;
				while (numbering < 4)
				{
					cout << "Enter Option " << numbering + 1 << endl;
					getline(cin, optt);
					Qpaper[numbering].setOption(optt);
					numbering++;
				}
				cout << endl;
				cout << "Enter Correct Option (1 , 2 ,3 , 4): " << endl;
				cin >> cpp;
				Qpaper[copt].setcop(cpp);
				while (cpp < 1 && cpp > 4)
				{
					cout << "Enter Correct Option (1 , 2 ,3 , 4): " << endl;
					cin >> cpp;
					Qpaper[copt].setcop(cpp);
				}
				WriteQuestions(Qpaper, type, topic);
			}
			cout << endl;
			if (type == 2)
			{
				cout << "Enter The Question statement : " << endl;
				cin.ignore();
				getline(cin, Quest);
				Qpaper[i].setQuestionNum(Quest);
				cout << endl;
				cout << "Enter Correct Option (1 / 0): " << endl;
				cin >> cpp;
				Qpaper[copt].setcop(cpp);
				cout << endl;
				while (cpp < 0 && cpp > 1)
				{
					cout << "Enter Correct Option (1 / 0) : " << endl;
					cin >> cpp;
					Qpaper[copt].setcop(cpp);
				}
				WriteQuestions(Qpaper, type, topic);
			}
			cout << endl;
			if (type == 3)
			{
				int i = 0;
				cout << "Enter The Question statement : " << endl;
				cin.ignore();
				getline(cin, Quest);
				Qpaper[i].setQuestionNum(Quest);
				WriteQuestions(Qpaper, type, topic);
				cout << endl;
			}
			if (type == 4)
			{
				t = false;
				break;
			}
		}
	}

	void ImportQuestion(string courseTeacher)
	{
		string QType;
		int task;
		char Alpha = 'A';
		cout << endl;
		cout << "1. MCQS : " << endl;
		cout << "2. True / False : " << endl;
		cout << "3. Subjective : " << endl;
		cout << endl;
		cout << "TASK : ";
		cin >> task;
		cout << endl;

		char itrateM = 'a';
		char itrateTF = 'a';
		char itrateS = 'a';

		string markerM = "2efcdea";
		string markerTF = "b94d27a";
		string markerS = "88f7aca";
		int itr = 0;
		int numofQues = 0;
		cout << endl;
		cout << "How Many ";
		cin >> numofQues;
		int max = 7;
		int* randomArray = NULL;
		randomArray = new int[max];
		srand(time(NULL));

		int numadd = 0;
		for (int i = 0; i < max; i++) {
			randomArray[i] = numadd++;
		}

		int j = 0;
		for (int i = max - 1; i > 0; i--)
		{
			j = rand() % (i + 1);

			int temp = randomArray[i];
			randomArray[i] = randomArray[j];
			randomArray[j] = temp;
		}
		while (itr < numofQues)
		{

			int randomchose = 0;
			randomchose = randomArray[itr];

			if (task == 1) { markerM[6] = itrateM + randomchose; QType = markerM; }
			if (task == 2) { markerTF[6] = itrateTF + randomchose; QType = markerTF; }
			if (task == 3) { markerS[6] = itrateS + randomchose; QType = markerS; }

			ifstream copy;

			itr++;
			ofstream past("QuizCreated.txt", ios::app);
			string correctopt;
			int countQ = 0;
			bool titleFinder = 0, typeFinder = 0;
			int i = 0;
			string statement, title, question, type, option[4], optionSubTF;
			string txt = ".txt";
			copy.open(courseTeacher + txt);
			if (!copy)
			{
				cout << "Failed to open file -> PLease try agian or Re-chech the location of the " << courseTeacher << " file : " << endl;
				assert(!copy.fail());
			}
			while (getline(copy, statement))
			{
				if (statement == "a5380ee")
				{
					titleFinder = 1;
					getline(copy, statement);
					title = statement;
				}
				else if (titleFinder)
				{
					if (statement == QType)
					{
						typeFinder = 1;
						type = statement;

						getline(copy, question);
						if (task == 1)
						{
							for (int i = 0; i < 4; i++)
							{
								getline(copy, option[i]);
							}
							getline(copy, statement);
							if (statement == "dabfac4")
							{
								getline(copy, statement);
								correctopt = statement;
							}
						}
						else if (task == 2)
						{
							for (int i = 0; i < 2; i++)
							{
								getline(copy, option[i]);
							}
							getline(copy, statement);
							if (statement == "dabfac4")
							{
								getline(copy, statement);
								correctopt = statement;
							}
						}
						countQ++;
						if (past.is_open())
						{
							past << endl;
							past << "a5380ee" << endl;
							past << title << endl;
							past << endl;
							past << type << endl;
							past << question << endl;
							if (task == 1)
							{
								for (int i = 0; i < 4; i++)
									past << option[i] << endl;

								past << "dabfac4" << endl;
								past << correctopt << endl;

							}
							else if (task == 2)
							{
								Alpha = 'A';
								for (int i = 0; i < 2; i++)
									past << option[i] << endl;

								past << "dabfac4" << endl;
								past << correctopt << endl;
							}
							past.close();
						}
						else
						{
							cout << "Failed to open file -> PLease try agian or Re-chech the location of the " << courseTeacher << " file : " << endl;
							assert(!past.fail());
						}

						typeFinder = 0;
						titleFinder = 0;
					}
				}
			}
			copy.close();
		}
	}
};

//===========================================

bool ValidatStartEndTimeDate(Date& Dstart, Date& Dend, Time& Tstart, Time& Tend, string course)
{
	ifstream ReadDateTime;

	ReadDateTime.open(course + "DateTime.txt");
	int Data;
	string text;
	if (!ReadDateTime)
	{
		cout << "Failed to open file -> PLease try agian or Re-chech the location of the "<< course + "DateTime.txt" << " file : " << endl;
		assert(!ReadDateTime.fail());
	}
	while (getline(ReadDateTime, text))
	{
		Data = stoi(text);
		Dstart.setYear(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Dstart.setMonth(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Dstart.setDay(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Tstart.setH(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Tstart.setMin(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Dend.setYear(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Dend.setMonth(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Dend.setDay(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Tend.setH(Data);
		getline(ReadDateTime, text);
		Data = stoi(text);
		Tend.setMin(Data);
	}

	time_t Timing = time(nullptr);

	struct tm CurrentTime;
	localtime_s(&CurrentTime, &Timing);

	if (CurrentTime.tm_year + 1900 >= Dstart.getYear() && CurrentTime.tm_year + 1900 <= Dend.getYear())
	{
		if (CurrentTime.tm_year + 1900 >= Dstart.getYear() && CurrentTime.tm_year + 1900 < Dend.getYear())
			return true;

		if (CurrentTime.tm_mon + 1 >= Dstart.getMonth() && CurrentTime.tm_mon + 1 <= Dend.getMonth())
		{
			if (CurrentTime.tm_mon + 1 >= Dstart.getMonth() && CurrentTime.tm_mon + 1 < Dend.getMonth())
				return true;

			if (CurrentTime.tm_mday >= Dstart.getDay() && CurrentTime.tm_mday <= Dend.getDay())
			{
				if (CurrentTime.tm_mday >= Dstart.getDay() && CurrentTime.tm_mday < Dend.getDay())
					return true;

				if (CurrentTime.tm_hour >= Tstart.getH() && CurrentTime.tm_hour <= Tend.getH())
				{
					if (CurrentTime.tm_hour >= Tstart.getH() && CurrentTime.tm_hour < Tend.getH())
						return true;

					if (CurrentTime.tm_min >= Tstart.getMin() && CurrentTime.tm_min <= Tend.getMin())
					{
						return true;
					}
					else
						return false;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

//========================================================

class attemptquiz : public Quiz, student
{
private:
	float scores = 0;
	int* courseStd = new int[12];
	instructor* inst = new  instructor[12];
	Date Dstart, Dend;
	Time  Tstart, Tend;
public:

	bool DisplayQuiz(student std[], int studentNumber, student** stdcourse, int Randomarray[])
	{
		string AnswerSheet[21];
		string coursestoselect[11];
		int coursestoselectcode[11] = { 0 };
		int courseselect = 0;
		cout << endl;

		int times = 0;
		int countQ = 0;

		int itr = 0;
		int loofcourse = 0;
		int x, y;
		const int totaltime = 1200;
		while (loofcourse < Randomarray[studentNumber])
		{	
			time_t startingtime = time(nullptr);
	
			system("cls");
			courseseleting:
			std[studentNumber].setscore(0);
			scores = 0;
			cout << "You Are Registerd in the following Courses : " << endl;
			cout << endl;
			cout << endl;
			cout << "Course ->   " << endl;
			int num = 1;
			for (int i = studentNumber; i < studentNumber + 1; i++)
			{
				for (int j = 1; j < Randomarray[i] + 1; j++)
				{
					cout << num++ << ". " << stdcourse[i][j].getcoursestudent() << endl;
					coursestoselect[j] = stdcourse[i][j].getcoursestudent();
					coursestoselectcode[j] = stdcourse[i][j].getcoursestudentCode();
				}
				cout << endl;
			}
			cout << endl;
			cout << "Select Your Course (To Attemp) : 1 , 2 .....  :   ";
			cin >> courseselect;

			while (courseselect > Randomarray[studentNumber])
			{
				cout << endl;
				system("cls");
				cout << "No Such Course! " << endl;
				cout << endl;
				cout << "Course ->   " << endl;
				int num = 1;
				for (int i = studentNumber; i < studentNumber + 1; i++)
				{
					for (int j = 1; j < Randomarray[i] + 1; j++)
					{
						cout << num++ << ". " << stdcourse[i][j].getcoursestudent() << endl;
						coursestoselect[j] = stdcourse[i][j].getcoursestudent();
						coursestoselectcode[j] = stdcourse[i][j].getcoursestudentCode();
					}
					cout << endl;
				}
				cout << endl;

				cout << " Select Your Course(To Attemp) : 1, 2 ..... : ";
				cin >> courseselect;
				cout << endl;
			}
			system("cls");
			times = 0;
			countQ = 0;
			int correctquestioncheakeranalytics[21] = { 0 };
			bool timecheck = ValidatStartEndTimeDate(Dstart, Dend, Tstart, Tend, coursestoselect[courseselect]);
			if (!timecheck)
			{
				cout << endl;
				cout << "Acess Denied! To : " << coursestoselect[courseselect] << "  (Time Condition not met) PLeasae select another Course : " << endl;
				cout << endl;
				cout << endl;
				goto courseseleting;
			}
			while (times < 3)
			{
				string QType;
				int task = 0;
				string optionchosed;
				int optionChos;
				string answer;
				system("cls");
				if (times == 0)
				{
					task = 1;
					x = 0; y = 7;
					cout << "MCQs Section " << endl;
				}
				if (times == 1)
				{
					task = 2;
					x = 7; y = 14;
					cout << "True / False Section " << endl;
				}
				if (times == 2)
				{
					task = 3;
					x = 14; y = 21;
					cout << "Subjective Section " << endl;
				}

				cout << endl;
				cout << endl;

				char itrateM = 'a';
				char itrateTF = 'a';
				char itrateS = 'a';

				string markerM = "2efcdea";
				string markerTF = "b94d27a";
				string markerS = "88f7aca";

				int max = 7;
				int* randomArray = NULL;
				randomArray = new int[max];
				srand(time(NULL));

				int numadd = 0;
				for (int i = 0; i < max; i++) {
					randomArray[i] = numadd++;
				}
				int j = 0;
				for (int i = max - 1; i > 0; i--)
				{
					j = rand() % (i + 1);

					int temp = randomArray[i];
					randomArray[i] = randomArray[j];
					randomArray[j] = temp;
				}

				while (itr < 7)
				{
					int RandomOption[4] = { 0, 1, 2, 3 };
					for (int i = 3; i >= 1; i--)
					{
						int j = rand() % (i + 1);
						int store = RandomOption[i];
						RandomOption[i] = RandomOption[j];
						RandomOption[j] = store;
					}
					int randomchose = 0;
					randomchose = randomArray[itr];

					if (task == 1) { markerM[6] = itrateM + randomchose; QType = markerM; }
					if (task == 2) { markerTF[6] = itrateTF + randomchose; QType = markerTF; }
					if (task == 3) { markerS[6] = itrateS + randomchose; QType = markerS; }

					ifstream copy;
					string correctopt;
					itr++;
					bool titleFinder = 0, typeFinder = 0;
					int i = 0;
					string statement, title, question, type, option[4], optionSubTF;
					string txt = ".txt";
					copy.open(coursestoselect[courseselect] + txt);
					if (!copy)
					{
						cout << "Failed to open file -> PLease try agian or Re-chech the location of "<< coursestoselect[courseselect] + txt <<" : " << endl;
						assert(!copy.fail());
					}
					while (getline(copy, statement))
					{
						if (statement == "a5380ee")
						{
							getline(copy, statement);
							titleFinder = 1;
							title = statement;
						}
						else if (titleFinder)
						{
							if (statement == QType)
							{
								typeFinder = 1;
								type = statement;

								getline(copy, question);
								time_t timepassed = time(nullptr) - startingtime;

								if (timepassed > totaltime)
								{
									cout << endl;
									cout << endl;
									system("cls");
									cout << "Time's up!" << endl;
									break;
								}
								if (task == 1)
								{
									for (int i = 0; i < 4; i++)
									{
										getline(copy, option[i]);
									}
									getline(copy, statement);
									if (statement == "dabfac4")
									{
										getline(copy, statement);
										correctopt = statement;
									}
								}
								else if (task == 2)
								{
									for (int i = 0; i < 2; i++)
									{
										getline(copy, option[i]);
									}
									getline(copy, statement);
									if (statement == "dabfac4")
									{
										getline(copy, statement);
										correctopt = statement;
									}
								}
								cout << countQ + 1 << ". " << question << endl;
								cout << endl;
								if (task == 1)
								{
								

									for (int i = 0; i < 4; i++)
										cout << option[RandomOption[i]] << endl;

									cout << endl;
									cout << "Choose Option. Press (x) To Submiit :  ";
									cin >> optionChos;
									while (optionChos < 1 && optionChos > 5)
									{
										cout << "Enter Correct Option (1 , 2 , 3 , 4) - (5) : " << endl;
										cin >> optionChos;
									}

									if (optionChos == 5 )
										return true;

									if (option[RandomOption[optionChos-1]] == correctopt)
									{
										scores += 3;
										AnswerSheet[countQ] = optionChos;
										std[studentNumber].setscore(scores);
										correctquestioncheakeranalytics[countQ] += 1;
										inst[coursestoselectcode[courseselect]].CorrectedQuestionCourse[countQ] += 1;
									}
									system("cls");
								}
								else if (task == 2)
								{
									for (int i = 0; i < 2; i++)
										cout << option[i] << endl;

									cout << endl;
									cout << "Choose Option. Press  (x) To Submiit :  ";
									cin >> optionchosed;
									while (optionchosed < "0" && optionchosed > "1")
									{
										cout << "Enter Correct Option (0 , 1) - (x) : " << endl;
										cin >> optionchosed;
									}

									if (optionchosed == "x")
										return true;

									if (optionchosed == correctopt)
									{
										scores += 2;
										AnswerSheet[countQ] = optionchosed;
										std[studentNumber].setscore(scores);
										correctquestioncheakeranalytics[countQ] += 1;
										inst[coursestoselectcode[courseselect]].CorrectedQuestionCourse[countQ] += 1;
									}
									system("cls");
								}
								else
								{
									int num_word = 0;
									cout << "Write 'break' to Exit(x) :\n\nAnswere :  ";
									cin.ignore();
									getline(cin, answer);
							
									if (answer == "break") { break; }
									else
									{
										correctquestioncheakeranalytics[countQ] += 1;
										inst[coursestoselectcode[courseselect]].CorrectedQuestionCourse[countQ] += 1;

										for (int i = 0; i < answer[i] != '\0'; i++)
										{
											if (answer[i] == ' ') { num_word++; }
											else { continue; }
										}

									}				
									scores = scores + ((num_word + 1) * 0.01);
									std[studentNumber].setscore(scores);
									system("cls");
								}

								typeFinder = 0;
								titleFinder = 0;
							}
						}
					}
					copy.close();

					countQ++;
				}
				cout << endl;
				cout << endl;
				cout << "Scored : " << std[studentNumber].getscore() << " Marks." << endl;
				cout << endl;
				cout << "Corrected Questions : ";

				for (i = x; i < y; i++)
				{
					if (correctquestioncheakeranalytics[i] == 1)
						cout << "Q" << i + 1 << "   ";
				}
				cout << endl;
				char pause;
				cout << endl;
				cout << "Press any KEY Move To Next Section: " << endl;
				pause = _getch();
				system("cls");
			
;				itr = 0;
				times++;

			}
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Result : -> " << endl;
			cout << endl;
			cout << endl;
			cout << std[studentNumber].getName() << " Scored : " << std[studentNumber].getscore() << " Marks." << endl;
			string csv = "Ana.csv";
			cout << endl;
			cout << "Course : " << coursestoselect[courseselect] << endl;

			cout << endl;

			cout << "Corrected Questions : ";
			for (int i = 0; i < 21; i++)
			{
				if (correctquestioncheakeranalytics[i] == 1)
					cout << "Q" << i + 1 << "   ";
			}
			char pauses;
			cout << endl;
			cout << endl;
			cout << "Press any KEY Move To Next Course: " << endl;
			pauses = _getch();

			//--------------------------------------------------------------

			ifstream CorrectQuRead;

			CorrectQuRead.open(coursestoselect[courseselect] + csv);

			if (!CorrectQuRead) {
				cout << "Failed to open file -> PLease try agian or Re-chech the location of "<< coursestoselect[courseselect] + csv <<" : " << endl;
				assert(!CorrectQuRead.fail());
			}

			char read;
			bool condition = false;
			int col = 1;
			int CellData = 0;

			while (CorrectQuRead.get(read))
			{
				if (read == '"')
				{
					condition = !condition;
				}
				else if (read == ',')
				{
					for (int i = 0; i < 21; i++)
					{
						if (col == i + 1) { inst[coursestoselectcode[courseselect]].CorrectedQuestionCourse[i] += CellData - 48; }
					}
					CellData = 0;
					col++;
				}
				else if (read == '\n')
				{
					col = 1;
					condition = false;
				}
				else {
					if (!condition || read != '"') {
						CellData += read;
					}
				}
			}
			CorrectQuRead.close();

			ofstream analyticsCorrectQ;

			analyticsCorrectQ.open(coursestoselect[courseselect] + csv);
			if (!analyticsCorrectQ) {
				cout << "Failed to open file -> PLease try agian or Re-chech the location of "<< coursestoselect[courseselect] + csv <<" : " << endl;
				assert(!analyticsCorrectQ.fail());
			}

			if (analyticsCorrectQ.is_open())
			{
				for (int i = 0; i < 21; i++)
				{
					analyticsCorrectQ << inst[coursestoselectcode[courseselect]].CorrectedQuestionCourse[i] << ",";
				}
				analyticsCorrectQ << endl;
			}
			analyticsCorrectQ.close();

			//-----------------------------------------------------------------

			ofstream resultstd;

			resultstd.open("result.csv", ios::app);
			if (!resultstd) {
				cout << "failed to open file -> please try agian or re-chech the location of the result.csv file : " << endl;
				assert(!resultstd.fail());
			}

			if (resultstd.is_open())
			{
				resultstd << coursestoselect[courseselect] << "," << std[studentNumber].getName() << "," << std[studentNumber].getID() << "," << std[studentNumber].getscore() << endl;
			}
			resultstd.close();

			//-------------------------------------------------------------------

			ofstream analyticpast;

			analyticpast.open("ForAnalytics.csv", ios::app);
			if (!analyticpast) {
				cout << "Failed to open file -> PLease try agian or Re-chech the location of the ForAnalytics.csv file : " << endl;
				assert(!analyticpast.fail());
			}

			if (analyticpast.is_open())
			{
				analyticpast << coursestoselect[courseselect] << "," << std[studentNumber].getID() << "," << std[studentNumber].getscore() << ",";

				for (int i = 0; i < 21; i++)
				{
					analyticpast << inst[coursestoselectcode[courseselect]].CorrectedQuestionCourse[i] << ",";
				}
				analyticpast << endl;
			}

			analyticpast.close();

			//--------------------------------------------------------------------

			loofcourse++;
		}

	}
};

//--------------------------------------------------------------------------------------------------------------------------------->

class Attendence : public student
{
private:
	int static attendence;
public:
	int* atten = new int[216];

	void setattendencestudents()
	{
		attendence++;
	}
	void setattestd(int att, student std[])
	{
		atten[attendence] = att;

		ofstream attend;

		attend.open("AttendenceSheet.csv", ios::app);

		if (attend.is_open())
		{
			attend << atten[attendence] << "," << std[att].getName() << "," << std[att].getID() << "," << "P" << endl;
		}

		attend.close();
	}
	int getattstd()
	{
		return *atten;
	}
	int getattendence()
	{
		return attendence;
	}
	void ShowPresentStudent(student std[])
	{
		ifstream attendcout;

		attendcout.open("AttendenceSheet.csv");

		if (!attendcout) {
			cout << "Failed to open file -> PLease try agian or Re-chech the location of the AttendenceSheet.csv file : " << endl;
			assert(!attendcout.fail());
		}

		char read;
		bool condition = false;
		int row = 1, col = 1;
		string CellData;
		cout << endl;
		cout << endl;
		cout << "Attendence Sheet :-" << endl;
		cout << endl;
		while (attendcout.get(read))
		{
			if (read == '"')
			{
				condition = !condition;
			}
			else if (read == ',')
			{
				if (col == 1) { cout << setw(4) << left << CellData << setw(5) << left << "     "; }
				if (col == 2) { cout << setw(15) << left << CellData << setw(5) << left << "     "; }
				if (col == 3) { cout << setw(15) << left << CellData << setw(5) << left << "     "; }
				if (col == 4) { cout << setw(8) << left << CellData << setw(5) << left << endl; }

				CellData.clear();
				col++;
			}
			else if (read == '\n')
			{
				if (col == 1) { cout << setw(4) << left << CellData << setw(5) << left << "     "; }
				if (col == 2) { cout << setw(15) << left << CellData << setw(5) << left << "     "; }
				if (col == 3) { cout << setw(15) << left << CellData << setw(5) << left << "     "; }
				if (col == 4) { cout << setw(8) << left << CellData << setw(5) << left << endl; }

				CellData.clear();
				row++;
				col = 1;
				condition = false;
			}
			else {
				if (!condition || read != '"') {
					CellData += read;
				}
			}
		}
		attendcout.close();
	}

}; int Attendence::attendence = -1;

//--------------------------------------------------------------------------------------------------------------------------------->
class Analytics
{
private:
	int AQcontent[21] = { 0 };

public:
	void ShowStudentAnalytics(student std[], string TEACOURSE,instructor inst[], int person)
	{
		ifstream analyticcopy;

		analyticcopy.open("ForAnalytics.csv");

		if (!analyticcopy) {
			cout << "Failed to open file -> PLease try agian or Re-chech the location of the ForAnalytics.csv file : " << endl;
			assert(!analyticcopy.fail());
		}
		cout << endl;
		cout << endl;
		cout << "Marks Sheet :-" << endl;
		cout << endl;
		cout << endl;
		cout <<"Course :  "<< TEACOURSE;
		cout << endl;
		cout << "Teacher :  " << inst[person].getName();
		cout << endl;
		cout << endl;
		float avg = 0;
		char read;
		bool condition = false;
		int row = 1, col = 1;
		string CellData;
		int  cheak = 0;
		int count = 0;
		cout << endl;
		cout << setw(25) << left << "Name" << setw(15) << left << "ID" << setw(8) << left << "Score " << endl;
		while (analyticcopy.get(read))
		{
			if (read == '"')
			{
				condition = !condition;
			}
			else if (read == ',')
			{		
				if (col == 1 && CellData == TEACOURSE) { cheak = row; }
				if (col == 2 && row == cheak) { cout << setw(20) << left << CellData << setw(5) << left << "     "; }
				if (col == 3 && row == cheak) { cout << setw(10) << left << CellData << setw(5) << left << "     "; }
				if (col == 4 && row == cheak) { cout << setw(8) << left << CellData << setw(5) << left << endl; avg += stoi(CellData); count++;}
				
				CellData.clear();
				col++;
			}
			else if (read == '\n')
			{
				if (col == 1 && CellData == TEACOURSE) { cheak = row; }
				if (col == 2 && row == cheak) { cout << setw(20) << left << CellData << setw(5) << left << "     "; }
				if (col == 3 && row == cheak) { cout << setw(10) << left << CellData << setw(5) << left << "     "; }
				if (col == 4 && row == cheak) { cout << setw(8) << left << CellData << setw(5) << left << endl; avg += stoi(CellData); count++; }

				CellData.clear();
				col++;

				CellData.clear();
				row++;
				col = 1;
				condition = false;
			}
			else {
				if (!condition || read != '"') {
					CellData += read;
				}
			}
		}

		analyticcopy.close();
		cout << endl;
		cout << endl;
		cout << "Average Score in " << TEACOURSE << " is : " << avg/count;
		cout << endl;
		cout << endl;
	}

	void ShowAnalyticGraph(string TeacherCourse, instructor inst[], int user)
	{
		cout << endl;
		cout << endl;
		int CoQuArray[21] = { 0 };

		ifstream CorrectQuRead;
		string csv = "Ana.csv";
		CorrectQuRead.open(TeacherCourse + csv);

		if (!CorrectQuRead) {
			cout << "Failed to open file -> PLease try agian or Re-chech the location of the "<< TeacherCourse + csv <<" file : " << endl;
			assert(!CorrectQuRead.fail());
		}

		char read;
		bool condition = false;
		int col = 1;
		int CellData = 0;

		while (CorrectQuRead.get(read))
		{
			if (read == '"')
			{
				condition = !condition;
			}
			else if (read == ',')
			{
				for (int i = 0; i < 21; i++)
				{
					if (col == i + 1) { CoQuArray[i] = CellData - 48; }

				}
				CellData = 0;
				col++;
			}
			else if (read == '\n')
			{
				col = 1;
				condition = false;
			}
			else {
				if (!condition || read != '"') { CellData += read; }
			}
		}
		CorrectQuRead.close();
		cout << endl;
		Attendence ATT;
		cout << "Course :   " << TeacherCourse << endl;
		cout << endl;
		cout << "Teacher :   " << "Mr. " + inst[user].getName() << endl;
		cout << endl;
		cout << endl;
		int max = 0, min = 100;
		int MaxIndex = 0, MinIndex = 0, avg = 0;
		for (int i = 0; i < 21; i++)
		{
			cout << setw(1) << left << "Q" << setw(3) << left << i + 1 << setw(6) << left << "|   ";
			for (int j = 0; j < CoQuArray[i]; j++)
			{
				if (CoQuArray[i] > max) { max = CoQuArray[i]; MaxIndex = i; }
				if (CoQuArray[i] < min) { min = CoQuArray[i]; MinIndex = i; }

				cout << "*";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << "Maximun Performance in 'Q" << MaxIndex + 1 << "'  ->  Total of '" << max << "' Students Corrected it  " << endl;
		cout << endl;
		cout << "Minimun Performance in 'Q" << MinIndex + 1 << "'  ->  Only '" << min << "' Students Corrected it  " << endl;
		cout << endl;
	}
};
//global =====================================================================================

void SettingDateTime(Date& D, Time& T,string Tcourse)
{
	int d, m, y;
	ofstream SaveTime;

	SaveTime.open(Tcourse + "DateTime.txt", ios::app);

	if (!SaveTime)
	{
		cout << "Failed to open file -> PLease try agian or Re-chech the location of "<< Tcourse + "DateTime.txt" <<" file : " << endl;
		assert(!SaveTime.fail());
	}

	cout << "Set Year : ";
	cin >> y;
	D.setYear(y);
	cout << endl;
	SaveTime << D.getYear() << endl;

	cout << "Set Month : ";
	cin >> m;
	D.setMonth(m);
	cout << endl;
	SaveTime << D.getMonth() << endl;

	bool daybool = false;

	while (daybool == false)
	{
		cout << "Set Day : ";
		cin >> d;
		cout << endl;
		if (m == 2)
		{
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
			{
				if (d <= 28)
				{
					D.setDay(d);
					SaveTime << D.getDay() << endl;
					daybool = true;
				}
				else
					cout << "Date Does not exist in this Month and Year " << endl;
			}
			else
			{
				if (d <= 29)
				{
					D.setDay(d);
					SaveTime << D.getDay() << endl;
					daybool = true;
				}
				else
					cout << "Date Does not exist in this Month and Year " << endl;
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d <= 30)
			{
				D.setDay(d);
				SaveTime << D.getDay() << endl;
				daybool = true;
			}
			else
				cout << "Date Does not exist in this Month and Year " << endl;
		}
		else
		{
			if (d <= 31)
			{
				D.setDay(d);
				SaveTime << D.getDay() << endl;
				daybool = true;
			}
			else
				cout << "Date Does not exist in this Month and Year " << endl;
		}
	}
	system("cls");
	int h, M;
	cout << "TIME " << endl; cout << endl;
	cout << "Set Hour Use 24 Hour Formate : ";
	cin >> h;
	T.setH(h);
	cout << endl;
	SaveTime << T.getH() << endl;

	cout << "Set Minutes : ";
	cin >> M;
	T.setMin(M);
	cout << endl;
	SaveTime << T.getMin() << endl;
	system("cls");
	cout << "Date : " << D.getDay() << " / " << D.getMonth() << " / " << D.getYear() << endl;
	cout << "Time : " << T.getH() << " : " << T.getMin() << endl;

	SaveTime.close();
}
//====================================================


bool cheakpassword(string password, int size)
{
	if (size < 6)
	{
		return 0;
	}

	int index = 0;
	int uppercase = 0, lowercase = 0, digits = 0, specail = 0;

	for (int j = 0; j < size; j++)
	{
		if (password[j] >= 'A' && password[j] <= 'Z') { uppercase++; }
		if (password[j] >= 'a' && password[j] <= 'z') { lowercase++; }
		if (password[j] >= '1' && password[j] <= '9') { digits++; }
		if ((password[j] >= 33 && password[j] <= 47) || (password[j] >= 58 && password[j] <= 64) || (password[j] >= 91 && password[j] <= 96) || (password[j] >= 123 && password[j] <= 126)) { specail++; }
	}
	if (uppercase > 0 && lowercase > 0 && digits > 0 && specail > 0)
		return 1;
	else
		return 0;
}

//====================================================

bool cheakID(string id, int size)
{
	int a = 0, b = 0, c = 0;

	if (size != 7) { return 0; }

	if (id[0] == 105)
		a = 1;

	if (id[1] == 49 || id[1] == 50 && id[2] == 49 || id[2] == 50)
		b = 1;

	if (id[3] >= 48 || id[3] <= 57 && id[4] >= 48 || id[4] <= 57 && id[5] >= 48 || id[5] <= 57 && id[6] >= 48 || id[6] <= 57)
		c = 1;

	if (a == 0 || b == 0 || c == 0)
		return 0;
	else
		return 1;
}

//====================================================

void showcourse(int RamdomSizeArray[11], student** std, int StudentNumberCOurse)
{
	cout << "Your Courses Are : ";
	for (int i = StudentNumberCOurse; i < StudentNumberCOurse + 1; i++)
	{
		for (int j = 1; j < RamdomSizeArray[i] + 1; j++)
		{
			cout << std[i][j].getcoursestudent() << " - ";
		}
		cout << endl;
	}
}

//========================================================

void PasswordGnerator(student std[], instructor inst[])
{


	ifstream file("passwordfile.csv");

	if (!file) {
		cout << "Failed to open file -> PLease try agian or Re-chech the location of the passwordfile.csv file : " << endl;
		assert(!file.fail());
	}
	char read;
	bool condition = false;
	int row = 1, col = 1;
	string CellData;
	int CellCountPassword = 1;
	int CellCountPasswordT = 0;

	while (file.get(read))
	{
		if (read == '"')
		{
			condition = !condition;
		}
		else if (read == ',') {
			if (col == 1 && row <= 216)
			{
				std[CellCountPassword].creatPassword(CellData);
				CellCountPassword++;
			}
			if (col == 1 && row >= 217)
			{
				inst[CellCountPasswordT].creatPassword(CellData);
				CellCountPasswordT++;
			}
			CellData.clear();
			col++;
		}
		else if (read == '\n') {
			if (col == 1 && row <= 216)
			{
				std[CellCountPassword].creatPassword(CellData);
				CellCountPassword++;
			}
			if (col == 1 && row >= 217)
			{
				inst[CellCountPasswordT].creatPassword(CellData);
				CellCountPasswordT++;
			}
			CellData.clear();
			row++;
			col = 1;
			condition = false;
		}
		else { if (!condition || read != '"') { CellData += read; } }
	}
	file.close();
}

//========================================================

int USERNUMBER(string username, student st[], instructor ins[])
{
	int cond = 0;
	int i = 1;
	int j = 0;

	for (i; i < 217; i++)
	{
		if (st[i].getName() == username)
		{
			cond = 1;
			return i;
		}
	}
	for (j; j < 11; j++)
	{
		if (ins[j].getName() == username)
		{
			cond = 1;
			return j;
		}
	}
	if (cond == 0)
	{
		return -1;
	}
}

//=========================================================
void OverWritePasswords(student std[], instructor inst[])
{
	ofstream overwrite;

	overwrite.open("passwordfile.csv");

	if (!overwrite)
	{
		cout << "Failed to open file -> PLease try agian or Re-chech the location of the passwordfile.csv file : " << endl;
		assert(!overwrite.fail());
	}

	int j = 0;

	for (int i = 1; i <= 227; i++) {
		if (i >= 1 && i <= 216) {
			overwrite << std[i].getPassword();
		}

		if (i >= 217 && i <= 227) {

			overwrite << inst[j].getPassword();
			j++;
		}
		overwrite << "\n";
	}
	overwrite.close();

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------>
void Menu(student std[], instructor inst[], int RamdomSizeArray[], student** stdcourse)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << setw(110) << "WELCOME\n";
	cout << endl;
	cout << setw(125) << "FAST NUCES ENTRY TEXT EXAM ISLAMABAD " << endl;
	cout << setw(135) << "__________________________________________________________";
	cout << endl;
	cout << endl;
	char instview;

	Date Dstart, Dend;
	Time Tstart, Tend;
	QuestionSetUp Qpaper;
	Attendence* StdAtd = new Attendence[216];
	attemptquiz* AttempQ = new attemptquiz[216];
	Attendence Att;
	Analytics Ana;

	cout << "View Instructions (Y/N) :  ";
	cin >> instview; cout << endl;

	if (instview == 'y' || instview == 'Y')
	{
		system("cls");
	instruction:
		cout << "Salam Aliakum !" << endl; cout << endl;
		cout << "Instructions -> Read Carefully" << endl;	cout << endl;

		cout << "1.  Be sure to arrive at the test center on time. Latecomers may not be allowed to take the test." << endl; cout << endl;
		cout << "2.  Bring your registration slip, national identity card, or passport for identification purposes." << endl; cout << endl;
		cout << "3.  Use a black or blue ballpoint pen to fill out the answer sheet." << endl; cout << endl;
		cout << "4.  Read the instructions for each section carefully before beginning." << endl; cout << endl;
		cout << "5.  Answer the questions in the order they appear on the test.Do not skip any questions." << endl; cout << endl;
		cout << "6.  If you do not know the answer to a question, do not waste too much time on it.." << endl; cout << endl;
		cout << "7.  Do not talk to other candidates during the test." << endl; cout << endl;
		cout << "8.  If you finish early, use the remaining time to review your answers." << endl; cout << endl;
		cout << endl;
	}
	else if (instview == 'n' || instview == 'N')
	{
		system("cls");
		cout << "Salam Aliakum !" << endl;
		cout << endl;
	}
	else
	{
		cout << "wrong input !";
		Menu(std, inst, RamdomSizeArray, stdcourse);
	}
	char person;
ST:
STs:
	string courseteacher;
	cout << "Login as Teacher Or Student -> (T / S) :  ";
	cin >> person;

	if (person == 'T' || person == 't')
	{
		system("cls");
		char yesno;
	log:
		cout << "Do you wan to Login -> (Y / N) To go back to MENU Press B :  ";
		cin >> yesno;
		if (yesno == 'Y' || yesno == 'y')
		{

			int USERperson = 0;
			string username;
			cout << endl;
			system("cls");
		tea:
			cout << endl;
			cout << "Enter your User Name : ";
			cin.ignore();
			getline(cin, username);

			system("cls");
			USERperson = USERNUMBER(username, std, inst);
			if (USERperson == -1)
			{
				cout << "User Name Not Found ! " << endl;
				cout << endl;
				goto ST;
			}
			cout << endl;
			cout << "ID : " << inst[USERperson].getID() << endl;
			cout << "Password : " << inst[USERperson].getPassword() << endl;
			cout << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << endl;
			if (inst[USERperson].login())
			{
				system("cls");
				cout << "Login sucessful ! : " << endl;
				char option;
				cout << endl;
				cout << "*" << endl;
				cout << endl;
			changepasst:
				cout << "IF you want to chane your Password enter Y else N to Generate Quiz Menu or B To go back to MENU :  ";
				cin >> option;
				cout << endl;
				if (option == 'Y' || option == 'y')
				{
					system("cls");
					cout << endl;
					cin >> inst[USERperson];
					OverWritePasswords(std, inst);
					system("cls");
					cout << "Your New Password is : ";
					cout << inst[USERperson].getPassword() << endl;
					cout << endl;
					char qopt;
				generatemenu:
					cout << "Go to Quiz Generate Menu (Y / B) :  ";
					cin >> qopt;
					if (qopt == 'Y' || qopt == 'y')
					{
					choicesT:
						system("cls");
						cout << endl;
						cout << "Your Course is : ";
						cout << inst[USERperson].getcourseAssignedteacher();
						courseteacher = inst[USERperson].getcourseAssignedteacher();
						cout << endl;
						cout << endl;
						int choice3;
						cout << "1. Generate and compile Quiz : " << endl; cout << endl;
						cout << "2. Add Questions to Quiz (import) : " << endl; cout << endl;
						cout << "3. Set Start and End Time For Quiz : " << endl; cout << endl;
						cout << "4. Login as Student or teacher : " << endl; cout << endl;
						cout << "5. See Student Who have attempted Quiz : " << endl; cout << endl;
						cout << "6. See Student Quiz Reasult : " << endl; cout << endl;
						cout << "7. See Student Quiz Analytics Graph MAX and MIN : " << endl; cout << endl;
						cout << endl;
						cout << "TASK : ";
						cin >> choice3;
						system("cls");
						if (choice3 == 3)
						{
							ofstream Date$Time;
							Date$Time.open(courseteacher + "DateTime.txt", ofstream::out | ofstream::trunc);
							if (!Date$Time)
							{
								cout << "Could not Open file to DELETE ! its Contents : " << endl;
							}
							Date$Time.close();

							cout << "Set Starting time :" << endl;
							SettingDateTime(Dstart, Tstart, courseteacher);
							cout << endl;
							cout << "Set Ending time :" << endl;
							SettingDateTime(Dend, Tend, courseteacher);
							goto choicesT;
						}
						else if (choice3 == 2)
						{
							Qpaper.ImportQuestion(courseteacher);
							goto choicesT;
						}
						else if (choice3 == 1)
						{
							Qpaper.GeneratePaper();
							goto choicesT;
						}
						else if (choice3 == 7)
						{
							char see;
							cout << endl;
							cout << endl;
							cout << "Do you want to See the Graph :  ";
							cin >> see;

							if (see == 'y' || see == 'Y')
							{
								system("cls");
								Ana.ShowAnalyticGraph(courseteacher, inst, USERperson);
							}
							char pause;
							cout << endl;
							cout << "Press any KEY to go BACK  : " << endl;
							pause = _getch();
							goto choicesT;

						}
						else if (choice3 == 4) { system("cls");	goto ST; }
						else if (choice3 == 5)
						{
							Att.ShowPresentStudent(std);
							char pause;
							cout << endl;
							cout << "Press any KEY to go BACK  : " << endl;
							pause = _getch();
							goto choicesT;
						}
						else if (choice3 == 6)
						{
							Ana.ShowStudentAnalytics(std, courseteacher,inst,USERperson);
							char pause;
							cout << endl;
							cout << "Press any KEY to go BACK  : " << endl;
							pause = _getch();
							goto choicesT;
						}
						else
						{
							system("cls");
							cout << "Wrong Input ! " << endl;
							goto choicesT;
						}
					}
					else if (qopt == 'B' || qopt == 'b')
					{
						system("cls");
						goto STs;
					}
					else
					{
						system("cls");
						cout << "Wrong Input ! " << endl;
						goto generatemenu;
					}
				}
				else if (option == 'B' || option == 'b')
				{
					system("cls");
					Menu(std, inst, RamdomSizeArray, stdcourse);
				}
				else if (option == 'N' || option == 'n')
				{
					system("cls");
					cout << "Your Course is : ";
					cout << inst[USERperson].getcourseAssignedteacher();
					cout << endl;
					cout << endl;
					string courseteacher = inst[USERperson].getcourseAssignedteacher();
					int choice3;
					cout << "1. Generate and compile Quiz : " << endl; cout << endl;
					cout << "2. Add Questions to Quiz (import) : " << endl; cout << endl;
					cout << "3. Set Start and End Time For Quiz : " << endl; cout << endl;
					cout << "4. Login as Student or teacher : " << endl; cout << endl;
					cout << "5. See Student Who have attempted Quiz : " << endl; cout << endl;
					cout << "6. See Student Quiz Reasult : " << endl; cout << endl;
					cout << "7. See Student Quiz Analytics Graph MAX and MIN : " << endl;
					cout << endl;
					cout << "TASK : ";
					cin >> choice3;
					system("cls");
					if (choice3 == 3)
					{
						ofstream Date$Time;
						Date$Time.open(courseteacher + "DateTime.txt", ofstream::out | ofstream::trunc);
						if (!Date$Time)
						{
							cout << "Could not Open file to DELETE ! its Contents : " << endl;
						}
						Date$Time.close();

						cout << "Set Starting time :" << endl;						
						SettingDateTime(Dstart, Tstart, courseteacher);
						cout << endl;
						cout << "Set Ending time :" << endl;
						SettingDateTime(Dend, Tend, courseteacher);
						goto choicesT;
					}
					else if (choice3 == 2)
					{
						Qpaper.ImportQuestion(courseteacher);
						goto choicesT;
					}
					else if (choice3 == 1)
					{
						Qpaper.GeneratePaper();
						goto choicesT;
					}
					else if (choice3 == 7)
					{
						char see;
						cout << endl;
						cout << endl;
						cout << "Do you want to See the Graph :  ";
						cin >> see;

						if (see == 'y' || see == 'Y')
						{
							system("cls");
							Ana.ShowAnalyticGraph(courseteacher, inst, USERperson);
						}
						char pause;
						cout << endl;
						cout << "Press any KEY to go BACK  : " << endl;
						pause = _getch();
						goto choicesT;

					}
					else if (choice3 == 4) { system("cls");	goto ST; }
					else if (choice3 == 5)
					{
						Att.ShowPresentStudent(std);
						char pause;
						cout << endl;
						cout << "Press any KEY to go BACK  : " << endl;
						pause = _getch();
						goto choicesT;
					}
					else if (choice3 == 6)
					{
						Ana.ShowStudentAnalytics(std, courseteacher,inst, USERperson);
						char pause;
						cout << endl;
						cout << "Press any KEY to go BACK  : " << endl;
						pause = _getch();
						goto choicesT;
					}
					else
					{
						system("cls");
						cout << "Wrong Input ! " << endl;
						goto choicesT;
					}
				}
				else
				{
					system("cls");
					cout << "Wrong Input ! " << endl;
					goto changepasst;
				}
			}
			else
			{
				cout << endl;
				cout << "Login failed ! : " << endl;
				cout << endl;
				cout << "Try Again ! Re - Cheak your User Name  : " << endl;
				cout << endl;
				goto tea;
			}

		}
		else if (yesno == 'N' || yesno == 'n')
		{
			system("cls");
			char x;
		closet:
			cout << "Do you want to Exit (x) or go back to Menu (b / B) :  ";
			cin >> x;
			if (x == 'x')
				exit(0);
			else if (x == 'b' || x == 'B')
			{
				system("cls");
				Menu(std, inst, RamdomSizeArray, stdcourse);
			}
			else
			{
				system("cls");
				cout << "Wrong Input!" << endl;
				goto closet;
			}
		}
		else if (yesno == 'B' || yesno == 'b')
		{
			system("cls");
			Menu(std, inst, RamdomSizeArray, stdcourse);
		}
		else
		{
			system("cls");
			cout << "Wrong Input ! " << endl;
			goto log;
		}
	}
	else if (person == 'S' || person == 's')
	{
		system("cls");
		char yesno;
		cout << "Do you wan to Login -> (Y / N) To go back to MENU Press B :  ";
		cin >> yesno;

		if (yesno == 'Y' || yesno == 'y')
		{
			system("cls");
		Stu:
			cout << endl;
			int USERperson = 0;
			string username;
			cout << "Enter your User Name :  ";
			cin.ignore();
			getline(cin, username);
			system("cls");
			USERperson = USERNUMBER(username, std, inst);
			if (USERperson == -1)
			{
				cout << "User Name Not Found ! " << endl;
				goto STs;
			}
			cout << endl;
			cout << "ID : " << std[USERperson].getID() << endl;
			cout << "Password : " << std[USERperson].getPassword() << endl;
			cout << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;

			if (std[USERperson].login())
			{
				system("cls");
				cout << "Login sucessful ! : " << endl;
				char option;
				cout << endl;
				cout << "*" << endl;
				cout << endl;
			changepass:
				cout << "IF you want to chane your Password enter Y else N to Quiz Attempt Menu or B To go back to MENU :  ";
				cin >> option;
				cout << endl;
				if (option == 'Y' || option == 'y')
				{
					system("cls");
					cout << endl;
					cin >> std[USERperson];
					OverWritePasswords(std, inst);
					system("cls");
					cout << "Your New Password is : ";
					cout << std[USERperson].getPassword() << endl;
					cout << endl;
					char qopt;
				attempt:
					cout << "Go to Quiz Attemp Menu (Y / B) :  ";
					cin >> qopt;
					if (qopt == 'Y' || qopt == 'y')
					{
						char attemptQ;
						system("cls");
						cout << endl;
						showcourse(RamdomSizeArray, stdcourse, USERperson);
						cout << endl;
						cout << "Attempt Quiz :  ";
						cin >> attemptQ;
						if (attemptQ == 'y' || attemptQ == 'Y')
						{
							bool QuizDoneNotDone = false;													
								if (RamdomSizeArray[USERperson] == 0)
								{
									system("cls");
									cout << endl;
									cout << "You are NOT ! Registered for any Course." << endl;
									goto Stu;
								}
								else
								{
									QuizDoneNotDone = AttempQ[USERperson].DisplayQuiz(std, USERperson, stdcourse, RamdomSizeArray);
									if (QuizDoneNotDone)
									{
										StdAtd[USERperson].setattendencestudents();
										StdAtd[USERperson].setattestd(USERperson, std);
									}
									else
									{
										cout << endl;
										cout << endl;
										cout << "Attendence Not Marked! You need to Submit the Quiz : " << endl;
										goto attempt;
									}
								}
							
						}
						else if (attemptQ == 'N' || attemptQ == 'n')
						{
							system("cls");
							goto ST;
						}
						else if (attemptQ == 'B' || attemptQ == 'b')
						{
							system("cls");
							goto ST;
						}
						else
						{
							system("cls");
							cout << "Wrong Input ! " << endl;
							goto ST;
						}
					}
					else if (qopt == 'B' || qopt == 'b')
					{
						system("cls");
						goto ST;
					}
					else
					{
						system("cls");
						cout << "Wrong Input ! " << endl;
						goto attempt;
					}
				}
				else if (option == 'B' || option == 'b')
				{
					system("cls");
					goto STs;
				}
				else if (option == 'N' || option == 'n')
				{
					char attemptQ;
					system("cls");
					cout << endl;
					showcourse(RamdomSizeArray, stdcourse, USERperson);
					cout << endl;
					cout << "Attempt Quiz (Y / N) :  ";
					cin >> attemptQ;
					if (attemptQ == 'y' || attemptQ == 'Y')
					{

						bool QuizDoneNotDone = false;
					
							if (RamdomSizeArray[USERperson] == 0)
							{
								system("cls");
								cout << endl;
								cout << "You are NOT ! Registered for any Course." << endl;
								goto Stu;
							}
							else
							{
								QuizDoneNotDone = AttempQ[USERperson].DisplayQuiz(std, USERperson, stdcourse, RamdomSizeArray);
								if (QuizDoneNotDone)
								{
									StdAtd[USERperson].setattendencestudents();
									StdAtd[USERperson].setattestd(USERperson, std);
								}
								else
								{
									cout << endl;
									cout << endl;
									cout << "Attendence Not Marked! You need to Submit the Quiz : " << endl;
									goto attempt;
								}

							}
					
					}
					else if (attemptQ == 'N' || attemptQ == 'n')
					{
						system("cls");
						goto ST;
					}
					else if (attemptQ == 'B' || attemptQ == 'b')
					{
						system("cls");
						goto ST;
					}
					else
					{
						system("cls");
						cout << "Wrong Input ! " << endl;
						goto ST;
					}
				}
				else
				{
					system("cls");
					cout << "Wrong Input ! " << endl;
					goto changepass;
				}
			}
			else
			{

				cout << endl;
				cout << "Login failed ! : " << endl;
				cout << endl;
				cout << "Try Again ! and Re - Cheak your User Name : " << endl;
				cout << endl;
				goto Stu;
			}

		}
		else if (yesno == 'N' || yesno == 'n')
		{
			system("cls");
			char x;
		close:
			cout << "Do you want to Exit (x) or go back to Menu (b / B) :  ";
			cin >> x;
			if (x == 'x')
				exit(0);
			else if (x == 'b' || x == 'B')
			{
				system("cls");
				Menu(std, inst, RamdomSizeArray, stdcourse);
			}
			else
			{
				system("cls");
				cout << "Wrong Input!" << endl;
				goto close;
			}
		}
		else if (yesno == 'B' || yesno == 'b')
		{
			system("cls");
			Menu(std, inst, RamdomSizeArray, stdcourse);
		}
	}
	else if (person == 'B' || person == 'b')
	{
		system("cls");
		goto instruction;
	}
	else
	{
		system("cls");
		cout << "Wrong Input!" << endl;
		goto ST;
	}


}

//Main function ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------->

int main()
{
	student* std = new student[225], ** stdcourse;
	instructor* inst = new instructor[13];
	stdcourse = new student * [225]; for (int i = 0; i < 225; i++) { stdcourse[i] = new student[13]; }

	PasswordGnerator(std, inst);

	string teacherNames[13] = { "Abu Bakkar", "Farooq","Usman", "Ali", "Altaf", "Muzzamil", "Sharjeel", "Hamza", "Bilal", "Yousha", "Hashir" };
	string teacherID[13] = { "i22-1111", "i22-2222","i22-3333", "i22-4444", "i22-5555", "i22-6666", "i22-7777", "i22-8888", "i22-9999", "i21-1111", "i21-2222" };

	for (int i = 0; i < 11; i++)
	{
		inst[i].setName(teacherNames[i]);
		inst[i].setID(teacherID[i]);
		inst[i].setcourseteacher();
	}

	ifstream file("data.csv");

	if (!file) {
		cout << "Failed to open file -> PLease try agian or Re-chech the location of the data.CSV file : " << endl;
		assert(!file.fail());
		return 1;
	}

	char read;
	bool condition = false;
	int row = 1, col = 1;
	string CellData;
	int CellDataCode = 0;
	int CellCountNames = 1;
	int CellCountID = 1;
	int CellcountcourseCol = 1;
	int RamdomSizeArray[220] = { 0 };

	while (file.get(read))
	{
		if (read == '"')
		{
			condition = !condition;
		}
		else if (read == ',') {
			if (col == 1)
			{
				std[CellCountID].setID(CellData);
				CellCountID++;
			}
			if (col == 2) {
				std[CellCountNames].setName(CellData);
				CellCountNames++;
			}
			if (col == 3 || col == 4 || col == 5 || col == 6 || col == 7 || col == 8 || col == 9 || col == 10 || col == 11 || col == 12 || col == 13) {
				if (CellData == "1")
				{
					if (col == 3) { CellData = "Programming Fundamentals"; CellDataCode = 1; }
					if (col == 4) { CellData = "Object Oriented Programming"; CellDataCode = 2; }
					if (col == 5) { CellData = "Introduction To Computing"; CellDataCode = 3; }
					if (col == 6) { CellData = "Data Structures"; CellDataCode = 4; }
					if (col == 7) { CellData = "Analysis of Algorithms"; CellDataCode = 5; }
					if (col == 8) { CellData = "Software Requirements Engineerings"; CellDataCode = 6; }
					if (col == 9) { CellData = "Research Methodology"; CellDataCode = 7; }
					if (col == 10) { CellData = "Big Data Analytics"; CellDataCode = 8; }
					if (col == 11) { CellData = "Artificial Intelligence"; CellDataCode = 9; }
					if (col == 12) { CellData = "Deep Learning"; CellDataCode = 10; }
					if (col == 13) { CellData = "Digital Image Processing"; CellDataCode = 11; }


					stdcourse[row][CellcountcourseCol].setcoursestudent(CellData);
					stdcourse[row][CellcountcourseCol].setcoursestudentCode(CellDataCode);
					RamdomSizeArray[row] = CellcountcourseCol++;
				}
			}
			CellData.clear();
			col++;
		}
		else if (read == '\n') {
			if (col == 1)
			{
				std[CellCountID].setID(CellData);
				CellCountID++;
			}
			if (col == 2)
			{
				std[CellCountNames].setName(CellData);
				CellCountNames++;
			}
			if (col == 3 || col == 4 || col == 5 || col == 6 || col == 7 || col == 8 || col == 9 || col == 10 || col == 11 || col == 12 || col == 13)
			{
				if (CellData == "1")
				{
					if (col == 3) { CellData = "Programming Fundamentals"; CellDataCode = 1; }
					if (col == 4) { CellData = "Object Oriented Programming"; CellDataCode = 2; }
					if (col == 5) { CellData = "Introduction To Computing"; CellDataCode = 3; }
					if (col == 6) { CellData = "Data Structures"; CellDataCode = 4; }
					if (col == 7) { CellData = "Analysis of Algorithms"; CellDataCode = 5; }
					if (col == 8) { CellData = "Software Requirements Engineerings"; CellDataCode = 6; }
					if (col == 9) { CellData = "Research Methodology"; CellDataCode = 7; }
					if (col == 10) { CellData = "Big Data Analytics"; CellDataCode = 8; }
					if (col == 11) { CellData = "Artificial Intelligence"; CellDataCode = 9; }
					if (col == 12) { CellData = "Deep Learning"; CellDataCode = 10; }
					if (col == 13) { CellData = "Digital Image Processing"; CellDataCode = 11; }

					stdcourse[row][CellcountcourseCol].setcoursestudent(CellData);
					stdcourse[row][CellcountcourseCol].setcoursestudentCode(CellDataCode);
					RamdomSizeArray[row] = CellcountcourseCol++;
				}
			}
			CellData.clear();
			row++;
			col = 1;
			CellcountcourseCol = 1;
			condition = false;
		}
		else
		{
			if (!condition || read != '"')
			{
				CellData += read;
			}
		}
	}

	file.close();

	cout << endl;
	cout << endl;

	Menu(std, inst, RamdomSizeArray, stdcourse);
	char pause;
	cout << endl;
	cout << "Press any KEY Exit and clear Memmory  : " << endl;
	pause = _getch();


	return 0;
}
//-----------------------------------------------------------------------------------------------
