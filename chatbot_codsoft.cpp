// written by Aamina Bokhari
//Task 1 : Chatbot
//Codesoft
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<iomanip>

using namespace std;
//Get responce function here
string GetResponse(string Request) {
  //I am converting the Request into lowercase letters for easy comparison
    transform(Request.begin(), Request.end(), Request.begin(), ::tolower);

    // Greetings here...(find hello OR hi)
    if (Request.find("hi") != string::npos || Request.find("hello") != string::npos)
        return "Hello!";

    // if user asks How are you?
    else if (Request.find("how are you") != string::npos || Request.find("How are you doing") != string::npos)
        return " I'm doing well,Thanks for asking!, How about you?";

    // if user ask about hobbies or fav thing..
    else if (Request.find("favorite") != string::npos && Request.find("topic") != string::npos || Request.find("hobby") != string::npos)
        return "I love talking to you.";

    
    // if user want some sugestions from the chatBot...
    else if (Request.find("recommend") != string::npos || Request.find("suggest") != string::npos|| Request.find("bored") != string::npos) {
        vector<string> suggestions = { "I recommend trying out a new book or movie!",
                                          "How about exploring a new hobby ?",
                                          "You could try visiting a new restaurant or café!",
                                          "Why not take a walk in nature and enjoy the outdoors?",
                                          "How about trying a new recipe and cooking something delicious for your family and friends?" };
        int Index = rand() % suggestions.size();//randomly display any suggestions
        return suggestions[Index];
    }

    // if the your want to end the chat....(find bye and end)..
    else if (Request.find("bye") != string::npos|| Request.find("Take care") != string::npos|| Request.find("later") != string::npos)
        return "Goodbye! Have a great day!";
    
    

    //handling all other requests from the user...
    else
        return "I'm sorry, I didn't understand that. Can you please rephrase?";
}

int main() {
    srand(time(NULL)); 
    cout << "**********************************" << endl;
    cout << "Welcome!,I am Chatbot!" << endl;
    cout << "**********************************" << endl;
    cout << "How can I help you?" << endl;

    string req;
    while (true) {
        cout << "User: ";
        getline(cin, req);
        

        string response = GetResponse(req);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}
