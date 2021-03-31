#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

int main(int argc, char* argv[]){
    char instr[500];
    gets(instr);
    int idx=-1;

    std::stack<char> word;
    std::queue<char> sentence;
    while(!sentence.empty()) sentence.pop();
    while(!word.empty()) word.pop();
    while(instr[++idx]!='\0')
    {
        if(instr[idx]!=' ')
        {
            word.push(instr[idx]);
            continue;
        }
        else
        {
            while(!word.empty())
            {
                char temp=word.top();
                sentence.push(temp);
                word.pop();
            }
            char space=' ';
            sentence.push(space);
            continue;
        }
    }
    while(!word.empty())
    {
        char temp=word.top();
        sentence.push(temp);
        word.pop();
    }

    while(!sentence.empty())
    {
        std::cout<<sentence.front();
        sentence.pop();
    }
    return 0;
}
