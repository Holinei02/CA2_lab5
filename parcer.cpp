#include <getopt.h>
#include <iostream>

int num = 0;

void PrintHelp()
{
    std::cout <<
            "--greeting  (-g):          Say hello to the world\n"
            "--num   (-n) <n>:          Change value of variable 'num'\n"
            "--bye -(b) <name>:         To farawell with <name> \n"
            "--help  (-h):              Show help\n";
    exit(1);
}

void ProcessArgs(int argc, char** argv)
{
    const char* const short_opts = "n:b:g:h";
    const option long_opts[] = {
            {"num", required_argument, nullptr, 'n'},
            {"greeting", no_argument, nullptr, 'g'},
            {"help", no_argument, nullptr, 'h'},
            {"bye", required_argument, nullptr, 'b'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'n':
            num = std::stoi(optarg);
            std::cout << "Num set to: " << num << std::endl;
            break;

        case 'b':
            std::cout << "Bye, my dear : " << std::stof(optarg) << std::endl;
            break;
        
        case 'g':
            std::cout << "Hello, the awesome world!" << std::endl;
            break;

        case 'h':
        case '?':
        default:
            PrintHelp();
            break;
        }
    }
}

int main(int argc, char **argv)
{
    ProcessArgs(argc, argv);
    return 0;
}