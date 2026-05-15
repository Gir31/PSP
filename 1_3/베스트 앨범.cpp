#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> genrePlayCount;
    map<string, vector<pair<int, int>>> genreMap;

    for (int i = 0; i < genres.size(); ++i)
    {
        if (genrePlayCount.find(genres[i]) != genrePlayCount.end())
        {
            genrePlayCount[genres[i]] += plays[i];
        }
        else
        {
            genrePlayCount.insert({ genres[i], plays[i] });
        }

        if (genreMap.find(genres[i]) != genreMap.end())
        {
            genreMap[genres[i]].push_back({ i, plays[i] });
        }
        else
        {
            vector<pair<int, int>> v;
            v.push_back({ i, plays[i] });
            genreMap.insert({ genres[i], v });
        }
    }

    vector<pair<string, int>> musics;

    for (auto it = genrePlayCount.begin(); it != genrePlayCount.end(); ++it)
    {
        musics.push_back({ it->first, it->second });
    }

    sort(musics.begin(), musics.end(), [](pair<string, int> left, pair<string, int> right)
        {
            return left.second > right.second;
        });

    for (pair<string, int> music : musics)
    {
        sort(genreMap[music.first].begin(), genreMap[music.first].end(), [](pair<int, int> left, pair<int, int> right)
            {
                return left.second > right.second;
            });

        if (genreMap[music.first].size() == 1)
        {
            answer.push_back(genreMap[music.first][0].first);
        }
        else
        {
            answer.push_back(genreMap[music.first][0].first);
            answer.push_back(genreMap[music.first][1].first);
        }
    }

    return answer;
}

int main()
{
    solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });

    return 0;
}

// 자료구조 map의 경우 
//for (int i = 0; i < genres.size(); ++i) {
//    genrePlayCount[genres[i]] += plays[i]; // 키가 없으면 0에서 더함
//    genreMap[genres[i]].push_back({ i, plays[i] }); // 키가 없으면 빈 vector 생성 후 push
//}