#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};


struct Contact {
    string name;
    int number;
};

const long hashSize = 9999999L;
const int notFound = -1;

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}


vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Contact> contacts;
    contacts.resize(hashSize);

    // initialize contacts, prepare for direct addressing
    for(size_t i = 0; i < contacts.size(); ++i)
        contacts[i].number = notFound;

    // process queries    
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            contacts[queries[i].number].name   = queries[i].name;
	    contacts[queries[i].number].number = queries[i].number;
        } else if (queries[i].type == "del") {
            contacts[queries[i].number].number = notFound;
        } else {
            string response = "not found";
            if(contacts[queries[i].number].number != notFound ) 
		response = contacts[queries[i].number].name;
            result.push_back(response);
        }
    return result;
}


int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
