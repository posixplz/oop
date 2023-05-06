class File : public std::fstream
{
private:
	std::string fname_;
	void reopen(std::ios::openmode);
public:
	File(std::string fname);
	const std::string& getFilename() const;
	void set(const std::string& fname);
	void erase();
};
