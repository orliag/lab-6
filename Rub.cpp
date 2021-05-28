#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>



using namespace std;



class rubic {
private:
    char front[3][3] = { {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'}, {'Y', 'Y', 'Y'} };
    char back[3][3] = { {'W', 'W', 'W'}, {'W', 'W', 'W'}, {'W', 'W', 'W'} };
    char top[3][3] = { {'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'} };
    char bottom[3][3] = { {'R','R','R'},{'R','R','R'},{'R','R','R'} };
    char left[3][3] = { {'B','B','B'},{'B','B','B'},{'B','B','B'} };
    char right[3][3] = { {'G','G','G'},{'G','G','G'},{'G','G','G'} };



    bool RFT_angle() {
        if ((top[2][2] == front[1][1]) or (top[2][2] == right[1][1]) or (top[2][2] == bottom[1][1])) {
            if ((front[0][2] == front[1][1]) or (front[0][2] == right[1][1]) or (front[0][2] == bottom[1][1])) {
                if ((right[0][0] == front[1][1]) or (right[0][0] == right[1][1]) or (right[0][0] == bottom[1][1])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool RFB_angle() {
        if ((bottom[0][2] == front[1][1]) or (bottom[0][2] == right[1][1]) or (bottom[0][2] == bottom[1][1])) {
            if ((front[2][2] == front[1][1]) or (front[2][2] == right[1][1]) or (front[2][2] == bottom[1][1])) {
                if ((right[2][0] == front[1][1]) or (right[2][0] == right[1][1]) or (right[2][0] == bottom[1][1])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool angle_rifht() {
        if ((bottom[0][2] == bottom[1][1]) and (front[2][2] == front[1][1]) and (right[2][0] == right[1][1])) {
            return true;
        }
        return false;
    }

    bool TFR() {
        if ((top[2][2] == top[1][1]) or (top[2][2] == right[1][1]) or (top[2][2] == front[1][1])) {
            if ((front[0][2] == top[1][1]) or (front[0][2] == right[1][1]) or (front[0][2] == front[1][1])) {
                if ((right[0][0] == top[1][1]) or (right[0][0] == right[1][1]) or (right[0][0] == front[1][1])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool TFL() {
        if ((top[2][0] == top[1][1]) or (top[2][0] == left[1][1]) or (top[2][0] == front[1][1])) {
            if ((front[0][0] == top[1][1]) or (front[0][0] == left[1][1]) or (front[0][0] == front[1][1])) {
                if ((left[0][2] == top[1][1]) or (left[0][2] == left[1][1]) or (left[0][2] == front[1][1])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool TBR() {
        if ((top[0][2] == top[1][1]) or (top[0][2] == right[1][1]) or (top[0][2] == back[1][1])) {
            if ((right[0][2] == top[1][1]) or (right[0][2] == right[1][1]) or (right[0][2] == back[1][1])) {
                if ((back[2][2] == top[1][1]) or (back[2][2] == right[1][1]) or (back[2][2] == back[1][1])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool TBL() {
        if ((top[0][0] == top[1][1]) or (top[0][0] == left[1][1]) or (top[0][0] == back[1][1])) {
            if ((left[0][0] == top[1][1]) or (left[0][0] == left[1][1]) or (left[0][0] == back[1][1])) {
                if ((back[2][0] == top[1][1]) or (back[2][0] == left[1][1]) or (back[2][0] == back[1][1])) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    rubic() {

    };

    void rol_F() {
        F();
        Back_();

        swap(top[1][0], right[0][1]);
        swap(top[1][0], bottom[1][2]);
        swap(top[1][0], left[2][1]);

        swap(top[1][1], right[1][1]);
        swap(top[1][1], bottom[1][1]);
        swap(top[1][1], left[1][1]);

        swap(top[1][2], right[2][1]);
        swap(top[1][2], bottom[1][0]);
        swap(top[1][2], left[0][1]);
    }

    void rol_Back() {
        F_();
        Back();

        swap(top[1][0], left[2][1]);
        swap(top[1][0], bottom[1][2]);
        swap(top[1][0], right[0][1]);

        swap(top[1][1], left[1][1]);
        swap(top[1][1], bottom[1][1]);
        swap(top[1][1], right[1][1]);

        swap(top[1][2], left[0][1]);
        swap(top[1][2], bottom[1][0]);
        swap(top[1][2], right[2][1]);
    }

    void rol_R() {
        R();
        L_();

        swap(front[0][1], top[0][1]);
        swap(front[0][1], back[0][1]);
        swap(front[0][1], bottom[0][1]);

        swap(front[1][1], top[1][1]);
        swap(front[1][1], back[1][1]);
        swap(front[1][1], bottom[1][1]);

        swap(front[2][1], top[2][1]);
        swap(front[2][1], back[2][1]);
        swap(front[2][1], bottom[2][1]);
    }

    void rol_L() {
        R_();
        L();

        swap(front[0][1], bottom[0][1]);
        swap(front[0][1], back[0][1]);
        swap(front[0][1], top[0][1]);

        swap(front[1][1], bottom[1][1]);
        swap(front[1][1], back[1][1]);
        swap(front[1][1], top[1][1]);

        swap(front[2][1], bottom[2][1]);
        swap(front[2][1], back[2][1]);
        swap(front[2][1], top[2][1]);
    }

    void rol_T() {
        T();
        B_();

        swap(front[1][0], left[1][0]);
        swap(front[1][0], back[1][2]);
        swap(front[1][0], right[1][0]);

        swap(front[1][1], left[1][1]);
        swap(front[1][1], back[1][1]);
        swap(front[1][1], right[1][1]);

        swap(front[1][2], left[1][2]);
        swap(front[1][2], back[1][0]);
        swap(front[1][2], right[1][2]);
    }

    void rol_B() {
        T_();
        B();

        swap(front[1][0], right[1][0]);
        swap(front[1][0], back[1][2]);
        swap(front[1][0], left[1][0]);

        swap(front[1][1], right[1][1]);
        swap(front[1][1], back[1][1]);
        swap(front[1][1], left[1][1]);

        swap(front[1][2], right[1][2]);
        swap(front[1][2], back[1][0]);
        swap(front[1][2], left[1][2]);
    }

    void R() {

        swap(right[0][0], right[0][2]);
        swap(right[0][0], right[2][2]);
        swap(right[0][0], right[2][0]);

        swap(right[0][1], right[1][2]);
        swap(right[0][1], right[2][1]);
        swap(right[0][1], right[1][0]);

        swap(top[2][2], back[2][2]);
        swap(top[2][2], bottom[2][2]);
        swap(top[2][2], front[2][2]);

        swap(top[0][2], back[0][2]);
        swap(top[0][2], bottom[0][2]);
        swap(top[0][2], front[0][2]);

        swap(top[1][2], back[1][2]);
        swap(top[1][2], bottom[1][2]);
        swap(top[1][2], front[1][2]);
    }

    void R_() {
        swap(right[0][0], right[2][0]);
        swap(right[0][0], right[2][2]);
        swap(right[0][0], right[0][2]);

        swap(right[0][1], right[1][0]);
        swap(right[0][1], right[2][1]);
        swap(right[0][1], right[1][2]);

        swap(top[2][2], front[2][2]);
        swap(top[2][2], bottom[2][2]);
        swap(top[2][2], back[2][2]);

        swap(top[0][2], front[0][2]);
        swap(top[0][2], bottom[0][2]);
        swap(top[0][2], back[0][2]);

        swap(top[1][2], front[1][2]);
        swap(top[1][2], bottom[1][2]);
        swap(top[1][2], back[1][2]);

    }

    void L() {
        swap(left[0][0], left[0][2]);
        swap(left[0][0], left[2][2]);
        swap(left[0][0], left[2][0]);

        swap(left[0][1], left[1][2]);
        swap(left[0][1], left[2][1]);
        swap(left[0][1], left[1][0]);

        swap(top[0][0], front[0][0]);
        swap(top[0][0], bottom[0][0]);
        swap(top[0][0], back[0][0]);

        swap(top[2][0], front[2][0]);
        swap(top[2][0], bottom[2][0]);
        swap(top[2][0], back[2][0]);

        swap(top[1][0], front[1][0]);
        swap(top[1][0], bottom[1][0]);
        swap(top[1][0], back[1][0]);
    }

    void L_() {
        swap(left[0][0], left[2][0]);
        swap(left[0][0], left[2][2]);
        swap(left[0][0], left[0][2]);

        swap(left[0][1], left[1][0]);
        swap(left[0][1], left[2][1]);
        swap(left[0][1], left[1][2]);

        swap(top[0][0], back[0][0]);
        swap(top[0][0], bottom[0][0]);
        swap(top[0][0], front[0][0]);

        swap(top[2][0], back[2][0]);
        swap(top[2][0], bottom[2][0]);
        swap(top[2][0], front[2][0]);

        swap(top[1][0], back[1][0]);
        swap(top[1][0], bottom[1][0]);
        swap(top[1][0], front[1][0]);
    }

    void F() {
        swap(front[0][0], front[0][2]);
        swap(front[0][0], front[2][2]);
        swap(front[0][0], front[2][0]);

        swap(front[0][1], front[1][2]);
        swap(front[0][1], front[2][1]);
        swap(front[0][1], front[1][0]);

        swap(top[2][0], right[0][0]);
        swap(top[2][0], bottom[0][2]);
        swap(top[2][0], left[2][2]);

        swap(top[2][1], right[1][0]);
        swap(top[2][1], bottom[0][1]);
        swap(top[2][1], left[1][2]);

        swap(top[2][2], right[2][0]);
        swap(top[2][2], bottom[0][0]);
        swap(top[2][2], left[0][2]);

    }

    void F_() {
        swap(front[0][0], front[2][0]);
        swap(front[0][0], front[2][2]);
        swap(front[0][0], front[0][2]);

        swap(front[0][1], front[1][0]);
        swap(front[0][1], front[2][1]);
        swap(front[0][1], front[1][2]);

        swap(top[2][0], left[2][2]);
        swap(top[2][0], bottom[0][2]);
        swap(top[2][0], right[0][0]);

        swap(top[2][1], left[1][2]);
        swap(top[2][1], bottom[0][1]);
        swap(top[2][1], right[1][0]);

        swap(top[2][2], left[0][2]);
        swap(top[2][2], bottom[0][0]);
        swap(top[2][2], right[2][0]);

    }

    void T() {
        swap(top[0][0], top[0][2]);
        swap(top[0][0], top[2][2]);
        swap(top[0][0], top[2][0]);

        swap(top[0][1], top[1][2]);
        swap(top[0][1], top[2][1]);
        swap(top[0][1], top[1][0]);

        swap(left[0][0], back[2][2]);
        swap(left[0][0], right[0][0]);
        swap(left[0][0], front[0][0]);

        swap(left[0][1], back[2][1]);
        swap(left[0][1], right[0][1]);
        swap(left[0][1], front[0][1]);

        swap(left[0][2], back[2][0]);
        swap(left[0][2], right[0][2]);
        swap(left[0][2], front[0][2]);

    }

    void T_() {
        swap(top[0][0], top[2][0]);
        swap(top[0][0], top[2][2]);
        swap(top[0][0], top[0][2]);

        swap(top[0][1], top[1][0]);
        swap(top[0][1], top[2][1]);
        swap(top[0][1], top[1][2]);

        swap(left[0][0], front[0][0]);
        swap(left[0][0], right[0][0]);
        swap(left[0][0], back[2][2]);

        swap(left[0][1], front[0][1]);
        swap(left[0][1], right[0][1]);
        swap(left[0][1], back[2][1]);

        swap(left[0][2], front[0][2]);
        swap(left[0][2], right[0][2]);
        swap(left[0][2], back[2][0]);

    }

    void B() {
        swap(bottom[0][0], bottom[0][2]);
        swap(bottom[0][0], bottom[2][2]);
        swap(bottom[0][0], bottom[2][0]);

        swap(bottom[0][1], bottom[1][2]);
        swap(bottom[0][1], bottom[2][1]);
        swap(bottom[0][1], bottom[1][0]);

        swap(left[2][0], front[2][0]);
        swap(left[2][0], right[2][0]);
        swap(left[2][0], back[0][2]);

        swap(left[2][1], front[2][1]);
        swap(left[2][1], right[2][1]);
        swap(left[2][1], back[0][1]);

        swap(left[2][2], front[2][2]);
        swap(left[2][2], right[2][2]);
        swap(left[2][2], back[0][0]);
    }

    void B_() {
        swap(bottom[0][0], bottom[2][0]);
        swap(bottom[0][0], bottom[2][2]);
        swap(bottom[0][0], bottom[0][2]);

        swap(bottom[0][1], bottom[1][0]);
        swap(bottom[0][1], bottom[2][1]);
        swap(bottom[0][1], bottom[1][2]);

        swap(left[2][0], back[0][2]);
        swap(left[2][0], right[2][0]);
        swap(left[2][0], front[2][0]);

        swap(left[2][1], back[0][1]);
        swap(left[2][1], right[2][1]);
        swap(left[2][1], front[2][1]);

        swap(left[2][2], back[0][0]);
        swap(left[2][2], right[2][2]);
        swap(left[2][2], front[2][2]);

    }

    void Back() {
        swap(back[0][0], back[0][2]);
        swap(back[0][0], back[2][2]);
        swap(back[0][0], back[2][0]);

        swap(back[0][1], back[1][2]);
        swap(back[0][1], back[2][1]);
        swap(back[0][1], back[1][0]);

        swap(top[0][0], left[2][0]);
        swap(top[0][0], bottom[2][2]);
        swap(top[0][0], right[0][2]);

        swap(top[0][1], left[1][0]);
        swap(top[0][1], bottom[2][1]);
        swap(top[0][1], right[1][2]);

        swap(top[0][2], left[0][0]);
        swap(top[0][2], bottom[2][0]);
        swap(top[0][2], right[2][2]);
    }

    void Back_() {
        swap(back[0][0], back[2][0]);
        swap(back[0][0], back[2][2]);
        swap(back[0][0], back[0][2]);

        swap(back[0][1], back[1][0]);
        swap(back[0][1], back[2][1]);
        swap(back[0][1], back[1][2]);

        swap(top[0][0], right[0][2]);
        swap(top[0][0], bottom[2][2]);
        swap(top[0][0], left[2][0]);

        swap(top[0][1], right[1][2]);
        swap(top[0][1], bottom[2][1]);
        swap(top[0][1], left[1][0]);

        swap(top[0][2], right[2][2]);
        swap(top[0][2], bottom[2][0]);
        swap(top[0][2], left[0][0]);
    }

    void stat() {

        for (int i = 0; i < 3; i++) {
            cout << "\t";
            for (int j = 0; j < 3; j++) {
                cout << top[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << left[i][j] << " ";
            }
            cout << "\t";
            for (int j = 0; j < 3; j++) {
                cout << front[i][j] << " ";
            }
            cout << "\t";
            for (int j = 0; j < 3; j++) {
                cout << right[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 3; i++) {
            cout << "\t";
            for (int j = 0; j < 3; j++) {
                cout << bottom[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 3; i++) {
            cout << "\t";
            for (int j = 0; j < 3; j++) {
                cout << back[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void save(string name) {
        ofstream file;
        file.open(name);


        if (!file.is_open()) {
            cout << "Error file openning" << endl;
        }
        else {
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    file << front[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    file << top[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    file << right[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    file << bottom[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    file << left[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    file << back[j][i];
                }
            }
        }
        cout << "File saved" << endl;
        file.close();
    }

    void load(string name) {
        ifstream fin;
        fin.open(name);

        if (!fin.is_open()) {
            cout << "Error file openning" << endl;
        }
        else {
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    fin >> front[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    fin >> top[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    fin >> right[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    fin >> bottom[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    fin >> left[j][i];
                }
            }
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    fin >> back[j][i];
                }
            }
        }

        fin.close();
    }

    void random_set() {
        int k;

        for (int i = 0; i < 10000; i++) {
            k = rand() % 12;
            if (k == 0) {
                R();
            }
            else if (k == 1) {
                R_();
            }
            else if (k == 2) {
                L();
            }
            else if (k == 3) {
                L_();
            }
            else if (k == 4) {
                F();
            }
            else if (k == 5) {
                F_();
            }
            else if (k == 6) {
                T();
            }
            else if (k == 7) {
                T_();
            }
            else if (k == 8) {
                B();
            }
            else if (k == 9) {
                B_();
            }
            else if (k == 10) {
                Back();
            }
            else if (k == 11) {
                Back_();
            }
        }
    }


    void solve() {
        vector<string> way;

        cout << "he!";

        rol_R();
        way.push_back("rol_R");

        {
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 8; i++) {
                    while (front[1][0] == bottom[1][1]) {
                        while (top[1][0] == bottom[1][1]) {
                            T();
                            way.push_back("T");
                        }
                        L_();
                        way.push_back("L_");
                    }
                    while (front[1][2] == bottom[1][1]) {
                        while (top[1][2] == bottom[1][1]) {
                            T();
                            way.push_back("T");
                        }
                        R();
                        way.push_back("R");
                    }
                    rol_T();
                    way.push_back("rol_T");
                }

                for (int i = 0; i < 4; i++) {
                    if (bottom[0][1] == bottom[1][1]) {
                        while (top[2][1] == bottom[1][1]) {
                            T();
                            way.push_back("T");
                        }
                        F();
                        way.push_back("F");
                        F();
                        way.push_back("F");
                    }
                    rol_T();
                    way.push_back("rol_T");
                }

                for (int i = 0; i < 4; i++) {
                    if ((front[0][1] == bottom[1][1]) or (front[2][1] == bottom[1][1])) {
                        while (top[2][1] == bottom[1][1]) {
                            T();
                            way.push_back("T");
                        }
                        F();
                        way.push_back("F");
                        if (front[1][2] == bottom[1][1]) {
                            while (top[1][2] == bottom[1][1]) {
                                T();
                                way.push_back("T");
                            }
                            R();
                            way.push_back("R");
                            if ((right[1][0] == bottom[1][1]) or (right[1][2] == bottom[1][1])) {
                                while (top[1][2] == bottom[1][1]) {
                                    T();
                                    way.push_back("T");
                                }
                                R_();
                                way.push_back("R_");
                            }

                        }
                        else if (front[1][0] == bottom[1][1]) {
                            while (top[1][0] == bottom[1][1]) {
                                T();
                                way.push_back("T");
                            }
                            L_();
                            way.push_back("L_");
                            if ((left[1][0] == bottom[1][1]) or (left[1][2] == bottom[1][1])) {
                                while (top[1][0] == bottom[1][1]) {
                                    T();
                                    way.push_back("T");
                                }
                                L();
                                way.push_back("L");
                            }

                        }

                    }

                    for (int i = 0; i < 4; i++) {
                        if (bottom[0][1] == bottom[1][1]) {
                            while (top[2][1] == bottom[1][1]) {
                                T();
                                way.push_back("T");
                            }
                            F();
                            way.push_back("F");
                            F();
                            way.push_back("F");
                        }
                        rol_T();
                        way.push_back("rol_T");
                    }


                    rol_T();
                    way.push_back("rol_T");
                }
            }


            for (int i = 0; i < 4; i++) {
                while ((front[0][1] != front[1][1]) or (top[2][1] != bottom[1][1])) {
                    T();
                    way.push_back("T");
                }
                F();
                F();
                way.push_back("F");
                way.push_back("F");
                rol_T();
                way.push_back("rol_T");
            }

        }
        // I

        {}

        {

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    if (RFT_angle()) {
                        while (!angle_rifht()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                        }

                    }


                    T();
                    way.push_back("T");
                }


                rol_T();
                way.push_back("rol_T");
            }


            for (int i = 0; i < 4; i++) {
                if (!angle_rifht()) {
                    if (RFB_angle()) {
                        while (!angle_rifht()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                        }
                    }
                    else {
                        R();
                        T();
                        R_();
                        T_();
                        way.push_back("right_hand");
                    }
                }

                rol_T();
                way.push_back("rol_T");
            }


            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    if (RFT_angle()) {
                        while (!angle_rifht()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                        }
                        break;
                    }
                    T();
                    way.push_back("T");
                }
                rol_T();
                way.push_back("rol_T");
            }


            for (int i = 0; i < 4; i++) {
                if (!angle_rifht()) {
                    if (RFB_angle()) {
                        while (!angle_rifht()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                        }
                    }
                    else {
                        R();
                        T();
                        R_();
                        T_();
                        way.push_back("right_hand");
                    }
                }

                rol_T();
                way.push_back("rol_T");
            }


            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    if (RFT_angle()) {
                        while (!angle_rifht()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                        }
                        break;
                    }
                    T();
                    way.push_back("T");
                }
                rol_T();
                way.push_back("rol_T");
            }

        }

        // II

        {}

        {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (front[0][1] == front[1][1]) {
                        if (top[2][1] == right[1][1]) {
                            T();
                            way.push_back("T");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B"); //T R T R_ T_ rol_T L_ T_ L T rol_B T

                        }
                        else if (top[2][1] == left[1][1]) {
                            T_();
                            way.push_back("T_");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T"); //T_ L_ T_ L T rol_B R T R_ T_ rol_T T_
                        }

                    }
                    T();
                    way.push_back("T");
                }
                rol_T();
                way.push_back("rol_T");
            }
            for (int i = 0; i < 4; i++) {
                if ((front[1][2] != front[1][1]) or (right[1][0] != right[1][1])) {
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    rol_T();
                    way.push_back("rol_T");
                    L_();
                    T_();
                    L();
                    T();
                    way.push_back("left_hand");
                    rol_B();
                    way.push_back("rol_B");
                    T();
                    way.push_back("T");
                }

                rol_T();
                way.push_back("rol_T");
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (front[0][1] == front[1][1]) {
                        if (top[2][1] == right[1][1]) {
                            T();
                            way.push_back("T");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");

                        }
                        else if (top[2][1] == left[1][1]) {
                            T_();
                            way.push_back("T_");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                        }

                    }
                    T();
                    way.push_back("T");
                }
                rol_T();
                way.push_back("rol_T");
            }

            for (int i = 0; i < 4; i++) {
                if ((front[1][2] != front[1][1]) or (right[1][0] != right[1][1])) {
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    rol_T();
                    way.push_back("rol_T");
                    L_();
                    T_();
                    L();
                    T();
                    way.push_back("left_hand");
                    rol_B();
                    way.push_back("rol_B");
                    T();
                    way.push_back("T");
                }

                rol_T();
                way.push_back("rol_T");
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (front[0][1] == front[1][1]) {
                        if (top[2][1] == right[1][1]) {
                            T();
                            way.push_back("T");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");

                        }
                        else if (top[2][1] == left[1][1]) {
                            T_();
                            way.push_back("T_");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                        }

                    }
                    T();
                    way.push_back("T");
                }
                rol_T();
                way.push_back("rol_T");
            }

            for (int i = 0; i < 4; i++) {
                if ((front[1][2] != front[1][1]) or (right[1][0] != right[1][1])) {
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    rol_T();
                    way.push_back("rol_T");
                    L_();
                    T_();
                    L();
                    T();
                    way.push_back("left_hand");
                    rol_B();
                    way.push_back("rol_B");
                    T();
                    way.push_back("T");
                }

                rol_T();
                way.push_back("rol_T");
            }
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (front[0][1] == front[1][1]) {
                        if (top[2][1] == right[1][1]) {
                            T();
                            way.push_back("T");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");

                        }
                        else if (top[2][1] == left[1][1]) {
                            T_();
                            way.push_back("T_");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            rol_B();
                            way.push_back("rol_B");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                        }

                    }
                    T();
                    way.push_back("T");
                }
                rol_T();
                way.push_back("rol_T");
            }

        }

        //III

        {}

        {
            if (!((top[1][1] == top[1][0]) and (top[1][1] == top[1][2]) and (top[1][1] == top[2][1]) and (top[1][1] == top[0][1]))) {
                if ((top[1][1] == top[1][0]) and (top[1][1] == top[1][2])) {
                    F();
                    way.push_back("F");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    F_();
                    way.push_back("F_");
                }
                else if ((top[1][1] == top[0][1]) and (top[1][1] == top[2][1])) {
                    T();
                    way.push_back("T");
                    F();
                    way.push_back("F");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    F_();
                    way.push_back("F_");

                }
                else if (((top[1][1] != top[1][0]) and (top[1][1] != top[1][2]) and (top[1][1] != top[2][1]) and (top[1][1] != top[0][1]))) {
                    F();
                    way.push_back("F");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    F_();
                    way.push_back("F_");
                    T();
                    way.push_back("T");
                    F();
                    way.push_back("F");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    F_();
                    way.push_back("F_");
                }
                else {
                    while ((top[1][1] != top[1][0]) or (top[1][1] != top[0][1])) {
                        T();
                        way.push_back("T");
                    }
                    F();
                    way.push_back("F");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    F_();
                    way.push_back("F_");
                }
            }

        }

        //IV 


        {
            bool flag = false;
            for (int j = 0; j < 4; j++) {

                if (!flag) {
                    for (int i = 0; i < 4; i++) {
                        if (TBL() and TBR() and TFL() and TFR()) {
                            flag = true;
                            break;
                        }
                        else if (TBL() and TFL()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            T_();
                            way.push_back("T_");
                            rol_B();
                            way.push_back("rol_B");

                            flag = true;
                            break;
                        }
                        else if (TFL() and TBR()) {
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            T_();
                            way.push_back("T_");
                            T_();
                            way.push_back("T_");
                            rol_T();
                            way.push_back("rol_T");
                            rol_T();
                            way.push_back("rol_T");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            R();
                            T();
                            R_();
                            T_();
                            way.push_back("right_hand");
                            rol_T();
                            way.push_back("rol_T");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            L_();
                            T_();
                            L();
                            T();
                            way.push_back("left_hand");
                            T_();
                            way.push_back("T_");

                            flag = true;
                            break;
                        }


                        T();
                        way.push_back("T");
                    }
                }


                rol_T();
                way.push_back("rol_T");
            }

        }

        //V

        {}
        {
            rol_F();
            way.push_back("rol_F");
            rol_F();
            way.push_back("rol_F");


            for (int i = 0; i < 4; i++) {
                while (bottom[1][1] != bottom[0][2]) {
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                }
                B();
                way.push_back("B");
            }

            rol_F();
            way.push_back("rol_F");
            rol_F();
            way.push_back("rol_F");


        }

        //VI

        {
            if ((front[0][1] != front[1][1]) and (right[0][1] != right[1][1]) and (left[0][1] != left[1][1]) and (back[2][1] != back[1][1])) {
                R();
                T();
                R_();
                T_();
                way.push_back("right_hand");
                L_();
                T_();
                L();
                T();
                way.push_back("left_hand");
                T();
                R();
                T_();
                R_();
                way.push_back("T");
                way.push_back("R");
                way.push_back("T_");
                way.push_back("R_");
                T_();
                L_();
                T();
                L();
                way.push_back("T_");
                way.push_back("L_");
                way.push_back("T");
                way.push_back("L");
            }

            for (int i = 0; i < 4; i++) {

                if ((left[0][1] == right[1][1]) and (front[0][1] == front[1][1])) {
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    L_();
                    T_();
                    L();
                    T();
                    way.push_back("left_hand");
                    T();
                    R();
                    T_();
                    R_();
                    way.push_back("T");
                    way.push_back("R");
                    way.push_back("T_");
                    way.push_back("R_");
                    T_();
                    L_();
                    T();
                    L();
                    way.push_back("T_");
                    way.push_back("L_");
                    way.push_back("T");
                    way.push_back("L");
                }
                else if ((right[0][1] == left[1][1]) and (front[0][1] == front[1][1])) {


                    L_();
                    T_();
                    L();
                    T();
                    way.push_back("left_hand");
                    R();
                    T();
                    R_();
                    T_();
                    way.push_back("right_hand");
                    T_();
                    L_();
                    T();
                    L();
                    way.push_back("T_");
                    way.push_back("L_");
                    way.push_back("T");
                    way.push_back("L");
                    T();
                    R();
                    T_();
                    R_();
                    way.push_back("T");
                    way.push_back("R");
                    way.push_back("T_");
                    way.push_back("R_");
                }

                rol_T();
                way.push_back("rol_T");
            }



        }

        //VII

//random save 1 solve



        rol_L();
        way.push_back("rol_L");


        vector<string> buf;
        cout << way.size() << endl;
        
        for (int i = 0; i < (int)way.size() - 8; i++) {
            if ((way[i] != "right_hand") && (way[i] != "left_hand")) {

                if ((way[i] == way[i + 1]) and (way[i + 1] == way[i + 2]) and (way[i + 2] == way[i + 3])) {
                    i += 3;
                }
                else if ((way[i] == way[i + 1]) and (way[i + 1] == way[i + 2])) {
                    if (way[i] == "T") {
                        i += 2;
                        buf.push_back("T_");
                    }
                    else if (way[i] == "rol_T") {
                        i += 2;
                        buf.push_back("rol_B");
                    }
                }
                else {
                    buf.push_back(way[i]);
                }

            }
            else if ((way[i] == way[i + 1]) and (way[i] == way[i + 2]) and (way[i] == way[i + 3]) and (way[i] == way[i + 4])) {
                buf.push_back("T");
                buf.push_back("R");
                buf.push_back("T_");
                buf.push_back("R_");
                i += 4;
            }
            else {
                buf.push_back(way[i]);
            }

        }
        for (int i = (int)way.size() - 8; i < (int)way.size(); i++) {
            buf.push_back(way[i]);
        }


        for (int i = 0; i < way.size() - 6; i++) {
            cout << way[i] << " ";
        }
        cout << endl << buf.size() << endl;

        way = buf;


        int k = (int)buf.size();
        for (int i = 0; i < k; i++) {
            buf.pop_back();
        }

        for (int i = 0; i < way.size(); i++) {
            if (i + 6 < way.size()) {
                if ((way[i] != "right_hand") and (way[i] != "left_hand")) {

                    if ((way[i] == way[i + 1]) and (way[i + 1] == way[i + 2]) and (way[i + 2] == way[i + 3])) {
                        i += 3;
                    }
                    else if ((way[i] == way[i + 1]) and (way[i + 1] == way[i + 2])) {
                        if (way[i] == "T") {
                            i += 2;
                            buf.push_back("T_");
                        }
                        else if (way[i] == "rol_T") {
                            i += 2;
                            buf.push_back("rol_B");
                        }
                    }
                    else {
                        buf.push_back(way[i]);
                    }

                }
                else if ((way[i] == way[i + 1]) and (way[i] == way[i + 2]) and (way[i] == way[i + 3]) and (way[i] == way[i + 4])) {
                    buf.push_back("T");
                    buf.push_back("R");
                    buf.push_back("T_");
                    buf.push_back("R_");
                    i += 4;
                }
                else {
                    buf.push_back(way[i]);
                }

            }
            else {
                buf.push_back(way[i]);
            }
        }

        way = buf;

        for (int i = 0; i < way.size(); i++) {
            cout << way[i] << " ";

        }

        cout << endl;

    }
};


int main(int argc, const char* argv[]) {

    srand((unsigned int)time(NULL));

    rubic cube;

    string comand;
    cout << "new, random or load" << endl;
    cin >> comand;

    if (comand == "new") {
        cube.stat();
    }
    else if (comand == "random") {
        cube.random_set();
        cube.stat();
    }
    else if (comand == "load") {
        cout << "Enter file name" << endl;
        string path;
        cin >> path;
        cube.load(path);
        cube.stat();
    }
    else {
        cout << "new cube" << endl;
    }


    while (cin >> comand) {
        if (comand == "R") {
            cube.R();
            cube.stat();
        }
        else if (comand == "random") {
            cube.random_set();
            cube.stat();
        }
        else if (comand == "load") {
            cout << "Enter file name" << endl;
            string path;
            cin >> path;
            cube.load(path);
            cube.stat();
        }
        else if (comand == "0") {
            break;
        }
        else if (comand == "solve") {
            cube.solve();
            cube.stat();
        }
        else if (comand == "R_") {
            cube.R_();
            cube.stat();
        }
        else if (comand == "L") {
            cube.L();
            cube.stat();
        }
        else if (comand == "L_") {
            cube.L_();
            cube.stat();
        }
        else if (comand == "F") {
            cube.F();
            cube.stat();
        }
        else if (comand == "F_") {
            cube.F_();
            cube.stat();
        }
        else if (comand == "T") {
            cube.T();
            cube.stat();
        }
        else if (comand == "T_") {
            cube.T_();
            cube.stat();
        }
        else if (comand == "B") {
            cube.B();
            cube.stat();
        }
        else if (comand == "B_") {
            cube.B_();
            cube.stat();
        }
        else if (comand == "right_hand") {
            cube.R();
            cube.T();
            cube.R_();
            cube.T_();
            cube.stat();
        }
        else if (comand == "left_hand") {
            cube.L_();
            cube.T_();
            cube.L();
            cube.T();
            cube.stat();
        }
        else if (comand == "Back") {
            cube.Back();
            cube.stat();
        }
        else if (comand == "Back_") {
            cube.Back_();
            cube.stat();
        }
        else if (comand == "rol_L") {
            cube.rol_L();
            cube.stat();
        }
        else if (comand == "rol_R") {
            cube.rol_R();
            cube.stat();
        }
        else if (comand == "rol_T") {
            cube.rol_T();
            cube.stat();
        }
        else if (comand == "rol_B") {
            cube.rol_B();
            cube.stat();
        }
        else if (comand == "rol_F") {
            cube.rol_F();
            cube.stat();
        }
        else if (comand == "rol_Back") {
            cube.rol_Back();
            cube.stat();
        }
        else if (comand == "save") {
            cout << "Enter file name" << endl;
            cin >> comand;
            cube.save(comand);
        }
        else {
            cout << "Unknown comand" << endl;
        }
    }





    return 0;
}
