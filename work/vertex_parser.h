#ifndef VERTEX_PARSER_H
#define VERTEX_PARSER_H

#include <QtCore>
#include <fstream>
#include <iostream>

bool cmp(char c) {
    return !((c >= '0' && c <= '9') || (c == '.')) && c != ',';
}

void vertex_parser(QVector<QVector<float>>& v, const std::string& path) {
    std::ifstream read(path);
    if (!read.is_open()) {
        return;
    }

    QVector<float> temp;
    while (!read.eof()) {
        std::string line;
        std::getline(read, line);

        line.erase(std::remove_if(line.begin(), line.end(), cmp), line.end());

        std::cerr << line << std::endl;

        std::string s_vertex;

        for (int i = 0; i < line.size(); ++i) {
//            if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '.')) {
//                s_vertex += line[i];
//            }
//            else {
//                temp.push_back(std::stof(s_vertex));
//            }
        }
    }
}

#endif // VERTEX_PARSER_H
