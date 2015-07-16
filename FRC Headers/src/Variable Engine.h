#include <vector>
#include <atomic>
#include <string>

using namespace std;

class Variable;

class VariableEngineBase {
public:

	/**
	 * Reads the file at CONSTANTS_FILE_PATH as a key-value file. Sets any overridden constants from the file.
	 *
	 * Writes an error to the dashboard/log if any errors occur. Logs what variables are replaced.
	 *
	 * Should be called on robot init.
	 */
	void LoadFromFile();

	/**
	 * Contains a pointer to every variable.
	 */
	static vector<atomic<Variable>**> variables;

	VariableEngineBase();
	~VariableEngineBase();

private:

	static const string CONSTANTS_FILE_PATH;// = "Constants.txt"
};

//
class VariableEngine: public VariableEngineBase {
public:

	/**
	 * Each constant is defined here.
	 */
	static const atomic<Variable>* x; //pointers used here so that the compiler can optimize

	/**
	 * This class should only be used statically.
	 */
	VariableEngine();
	~VariableEngine();
private:

};

class Variable {
public:

	/**
	 * Constructs a Variable object and adds itself to the variables array.
	 */
	static atomic<Variable>* ConstructVariable(string name, double value);

	string GetName();
	double GetDouble();
	int GetInt();


	Variable(string name, double value);
	~Variable();

private:
	string name;
	double value;
};
