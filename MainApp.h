#pragma once



class MainApp : public Poco::Util::ServerApplication
{
public:
	MainApp();
	~MainApp();

protected:
	void initialize(Application& self);
	void uninitialize();
	void defineOptions(OptionSet& options);
	void handleOption(const std::string& name, const std::string& value);
	void displayHelp();
	int main(const std::vector<std::string>& args);
private:
	bool _helpRequested;
};

