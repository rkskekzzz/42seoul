#include <iostream>
#include <string>
#include <fstream>

bool fileCheck(std::fstream& input_file, std::fstream& output_file, std::string &filename) {
	input_file.open(filename);
	output_file.open(filename + ".replace", std::ios::out);
	if (!input_file.is_open()) {
		std::cout << "input file open error" << std::endl;
		return false;
	}
	if (output_file.fail()) {
		std::cout << "output file open error" << std::endl;
		return false;
	}
	return true;
}

bool inputCheck(int argc, char* argv[], std::string& filename, std::string& from, std::string& to) {
	if (argc != 4) {
		std::cout << "Filename, S1, to is necessary" << std::endl;
		return false;
	}
	filename = argv[1];
	from = argv[2];
	to = argv[3];
	if (from.length() * to.length() == 0) {
		std::cout << "S1, S2 is necessary" << std::endl;
		return false;
	}
	return true;
}

std::string replace(std::string& str, const std::string& from, const std::string& to) {
	std::string res = "";
	std::string tail = "";
	if(from.empty())
        return "";
    size_t pos = 0;
    while((pos = str.find(from, pos)) != std::string::npos) {
        res += str.substr(0, pos) + to;
		tail = str.substr(pos + from.length());
        pos += to.length();
    }
	res += tail;
	std::cout << res << std::endl;
	return res;
}

int main(int argc, char *argv[]) {
	std::fstream input_file;
	std::fstream output_file;
	std::string filename;
	std::string from;
	std::string to;
    std::string line;

	if (!inputCheck(argc, argv, filename, from, to) ||
		!fileCheck(input_file, output_file, filename))
	 	return 1;

    while (std::getline(input_file, line)) {
        output_file << replace(line, from, to) << "\n";
    }

	input_file.close();
	output_file.close();
}
