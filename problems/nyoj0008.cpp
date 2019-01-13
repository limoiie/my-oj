//
// Created by limo on 2018/6/19.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct rect {
    int no, height, width;

    rect() = default;
    rect(int v_no, int v_one, int v_two) {
        set(v_no, v_one, v_two);
    }

    void set(int v_no, int v_one, int v_two) {
        this->no = v_no;
        if (v_one > v_two) height = v_one, width = v_two;
        else width = v_one, height = v_two;
    }

    bool operator!=(const rect& rt) {
        return no != rt.no || height != rt.height || width != rt.width;
    }

    void print() {
        cout << no << " " << height << " " << width << endl;
    }
};

bool compare(const rect& rt1, const rect& rt2) {
    if (rt1.no == rt2.no) {
        if (rt1.height == rt2.height) {
            return rt1.width < rt2.width;
        } else {
            return rt1.height < rt2.height;
        }
    } else {
        return rt1.no < rt2.no;
    }
}

int test_main() {
    int case_num; cin >> case_num;
    while (case_num--) {
        int n; cin >> n;

        vector<rect> rect_list;
        for (auto i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            rect rt(a, b, c);
            rect_list.push_back(rt);
        }

        sort(rect_list.begin(), rect_list.end(), compare);

        rect_list.front().print();
        for (int i = 1; i < rect_list.size(); ++i) {
            if (rect_list[i] != rect_list[i-1])
                rect_list[i].print();
        }
    }
    return 0;
}