#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>


int main(int argc,char *argv[])
{
    std::vector<std::string> adjectives;
    std::vector<std::string> nouns;
    

    std::ifstream adjectivesFile("adjectives.txt");
    
    for(std::string line;std::getline(adjectivesFile,line);)
    {
        adjectives.push_back(line);
    }
    

    std::ifstream nounsFile("nouns.txt");
    
    for(std::string line;std::getline(nounsFile,line);)
    {
        nouns.push_back(line);
    }
    
    
    std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    
    std::cout << "codename:  " << adjectives.at(generator() % adjectives.size()) << " " << nouns.at(generator() % nouns.size()) << std::endl;
    
    return 0;
}
