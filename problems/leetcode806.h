//
// Created by limo on 2018/6/3.
//
// Leetcode806
//

#ifndef OJ_LEETCODE806_H
#define OJ_LEETCODE806_H


#include "base.h"

class SolutionLeetCode806 {
    struct point {
        int x, y;
        point() = default;
        point(int vx, int vy) : x(vx), y(vy) {}
        point operator+(const point& p) const {return {x+p.x, y+p.y};}
        bool operator==(const point& p) const {return x==p.x && y==p.y;}
        bool operator!=(const point& p) const {return x!=p.x || y!=p.y;}
    };

public:
    int cutOffTree(vector<vector<int>>& forest) {
        this->p_forest = make_shared<vector<vector<int>>>(forest);
        h = forest.size(), w = forest.front().size();

        vector<point> trees;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (forest[i][j] > 1)
                    trees.emplace_back(i, j);

        sort(trees.begin(), trees.end(), [this](const point& lv, const point& rv)->bool{
            return map(lv) < map(rv);
        });
        trees.insert(trees.begin(), {0,0});

        int steps = 0;
        for (int t, i = 1; i < trees.size(); ++i) {
            if ((t = bfs(trees[i-1], trees[i])) >= 0) steps += t;
            else
                return -1;
        }
        return steps;
    }

private:
    shared_ptr<vector<vector<int>>> p_forest;
    size_t h, w;

    int bfs(const point &start, const point &end) {
        if (start == end) return 0;

        memset(visited, 0, sizeof(visited));
        visited[start.x][start.y] = 1;

        queue<point> que; que.push(start);

        while (!que.empty()) {
            point curr = que.front(); que.pop();
            for (auto const &d : di) {
                point n = d + curr;
                if (n == end) return visited[curr.x][curr.y];

                if (in_map(n) && map(n) && !visited[n.x][n.y]) {
                    visited[n.x][n.y] = visited[curr.x][curr.y] + 1;
                    que.push(n);
                }
            }
        }
        return -1;
    }

    inline
    bool in_map(const point &p) {
        return p.x >= 0 && p.x < p_forest->size() &&
               p.y >= 0 && p.y < p_forest->front().size();
    }

    inline
    int& map(const point &p) {
        return (*p_forest)[p.x][p.y];
    }

    int visited[52][52];

    point di[4] = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

};

#endif //OJ_LEETCODE806_H
