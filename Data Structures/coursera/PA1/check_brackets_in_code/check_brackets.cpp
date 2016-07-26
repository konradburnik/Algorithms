#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(int type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {

    bool isBalanced = true;
    int errorPos = 0;

    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket b = Bracket(next, position);
            opening_brackets_stack.push(b);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
           if( opening_brackets_stack.empty() == false )
           {
            Bracket b = opening_brackets_stack.top();
            if ( b.Matchc(next) == false  ) {
              isBalanced = false;
              errorPos = position;
              break;
            } else
                opening_brackets_stack.pop();
           } else 
             { 
               isBalanced = false;
               errorPos = position;
               break;
             }
        }
    }
    
    if(opening_brackets_stack.empty() == false && isBalanced == true) 
    {
      isBalanced = false;
      errorPos = opening_brackets_stack.top().position;
    }

    // Printing answer, write your code here
    if ( isBalanced ) 
    	std::cout << "Success" << "\n";
    else 
        std::cout << errorPos+1 << "\n";
    
    return 0;
}
