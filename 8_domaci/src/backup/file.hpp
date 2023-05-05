class File : public std::fstream
{
private:
	std::string fname;
	// static const std::size_t max_line_size;
	// std::array<char, max_line_size> line_buffer;
public:
	File(std::string filename);
	
	const std::string& getFilename() const;
	void set(const std::string& filename);
	void reset();
};
