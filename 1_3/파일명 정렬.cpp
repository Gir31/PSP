#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct FileName {
    string HEAD;
    string NUMBER;
    string TAIL;
};

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<FileName> filenames;

    for (string file : files)
    {
		int i = 0;
        FileName filename;
        for (char ch : file)
        {
            if (isdigit(ch) && i != 2) {
                filename.NUMBER += ch;
                i = 1;
            }
            else if (i == 0)
            {
                filename.HEAD += ch;
            }
            else
            {
                i = 2;
                filename.TAIL += ch;
            }
        }
		filenames.push_back(filename);
    }

    stable_sort(filenames.begin(), filenames.end(), [](const FileName& a, const FileName& b) {
        string headA = a.HEAD;
        string headB = b.HEAD;
        transform(headA.begin(), headA.end(), headA.begin(), ::toupper);
        transform(headB.begin(), headB.end(), headB.begin(), ::toupper);
        if (headA == headB) {
            int numA = stoi(a.NUMBER);
            int numB = stoi(b.NUMBER);
            return numA < numB;
        }
        return headA < headB;
		});

    for (const FileName& filename : filenames) {
        answer.push_back(filename.HEAD + filename.NUMBER + filename.TAIL);
	}

    return answer;
}

int main()
{
    vector<string> files = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" };
    vector<string> answer = solution(files);
    for (const string& file : answer) {
        cout << file << endl;
    }
    return 0;
}