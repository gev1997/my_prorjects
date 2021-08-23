#ifndef VERTEX_PARSER_H
#define VERTEX_PARSER_H

#include <QtCore>
#include <algorithm>

#include <iostream>

QVector<QVector<float>> vertex_parser(const QString& path) {
    QVector<QVector<float>> _vertices;
    QVector<float> _tmp;

    QFile file(path);
    file.open(QIODevice::ReadOnly);

    if (!file.isOpen()) {
        std::cerr << "ex";
        return {};
    }

    QTextStream t_str(&file);
    while (!t_str.atEnd()) {
        std::string line = t_str.readLine().toStdString();

        if (line.empty()) {
            continue;
        }

        auto comma = find(line.begin(), line.end(), ',');
        std::string x(find(line.begin(), line.end(), 'x') + 2, comma);
        line = std::string(comma + 1, line.end());

        comma = find(line.begin(), line.end(), ',');
        std::string y(find(line.begin(), line.end(), 'y') + 2, comma);
        line = std::string(comma + 1, line.end());

        comma = find(line.begin(), line.end(), ')');
        std::string z(find(line.begin(), line.end(), 'z') + 2, comma);

        _tmp.push_back(std::stof(x));
        _tmp.push_back(std::stof(y));
        _tmp.push_back(std::stof(z));
    }

    _vertices.push_back(QVector<float>(_tmp.begin(), _tmp.begin() + (_tmp.size() / 2)));
    _vertices.push_back(QVector<float>(_tmp.begin() + (_tmp.size() / 2), _tmp.end()));

    return std::move(_vertices);
}

#endif // VERTEX_PARSER_H
