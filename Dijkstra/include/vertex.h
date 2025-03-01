#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

using namespace std;

const int INF = numeric_limits<int>::max();

class vertex {
public:
    int id;
    int d;
    int predecessor;
    vertex(int id): id(id), d(INF), predecessor(-1){}
};
#endif // VERTEX_H_INCLUDED
