#include <iostream>
#include <fstream>
#include <string>

int writefile(const std::string &filename, const std::string &text);

int readfile(const std::string &filename);

void usage();

int main(int argc, char* argv[]){
    

    if (argc < 3){
        usage();
    }
    else if (strcmp(argv[1], "w") == 0){
        writefile(std::string(argv[2]), "Hello World!");
    }
    else if (strcmp(argv[1], "r") == 0){

        readfile(std::string(argv[2]));
    }
    else {
        usage();
    }

    
    return 0;
}

int writefile(const std::string &filename, const std::string &text){
    std::cout << "writing to file" << std::endl;
    return 0;
}

int readfile(const std::string &filename){
    std::cout << "reading from file" << std::endl;
    std::fstream file;
    file.open(filename, std::fstream::in);
    if (!file){
        std::cout << "No such file" << std::endl;
    }
    else {
        while (1){
        char c;
        file >> c;
        if (file.eof())
            break;
        std::cout << c;
        }
    }
    
    std::cout << std::endl;

    file.close();
    return 0;
}

void usage(){
    std::cout << "Usage blah blah blah" << std::endl;
}