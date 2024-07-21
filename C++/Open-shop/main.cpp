#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits>

using namespace std;

struct Worker {
    int time;
    int workId;
};

class Solution {
    int n;
    int m;
    int min_time;
    int time;
    int busy;
    set<int> busy_work;
    vector<vector<Worker>> works;
    vector<Worker> workers;
    vector<string> plan;

public:
    Solution() {
        n = 0;
        m = 0;
        min_time = numeric_limits<int>::max();
        time = 0;
        busy = 0;
    }

    void free_work() {
        time += min_time;
        int new_min_time = numeric_limits<int>::max();
        for (int i = 0; i < workers.size(); i++) {
            if (workers[i].time != 0) {
                workers[i].time -= min_time;
                if (workers[i].time) {
                    if (workers[i].time < new_min_time)
                    {
                        new_min_time = workers[i].time;
                    }
                } else {
                    busy--;
                    busy_work.erase(workers[i].workId);
                    workers[i] = {0, 0};
                }
            }
        }
        min_time = new_min_time;
    }

    bool get_work(int ind) {
        if (busy == n) {
            free_work();
        }
        for (int i = 0; i < works[ind].size(); i++) {
            int times = works[ind][i].time;
            int worker = works[ind][i].workId;
            if (workers[worker].time == 0) {
                if (times == 0) {
                    works[ind].erase(works[ind].begin() + i);
                    plan.push_back(to_string(ind + 1) + " " + to_string(worker + 1));
                    continue;
                }
                busy_work.insert(ind);
                busy++;
                workers[worker].time = times;
                workers[worker].workId = ind;
                if (min_time > times) {
                    min_time = times;
                }
                works[ind].erase(works[ind].begin() + i);
                plan.push_back(to_string(ind + 1) + " " + to_string(worker + 1));
                return false;
            }
        }
        return true;
    }

    void read_data() {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            vector<Worker> work;
            for (int j = 0; j < m; j++) {
                int val;
                cin >> val;
                work.push_back({val, j});
            }
            //sort(work.begin(), work.end(), [](const Worker& w1, const Worker& w2) {
             //   return w1.time > w2.time;
            //});
            works.push_back(work);
        }
    }

    void work() {
        time = 0;
        workers.resize(m, {0, 0});
        int k = m * n;
        while (plan.size() != k) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (busy_work.size() == n) {
                    free_work();
                }
                if (busy_work.find(j) == busy_work.end()) {
                    flag &= get_work(j);
                }
            }
            if (flag) {
                free_work();
            }
        }
        int t = 0;
        for (const auto& val : workers) {
            if (val.time > t) {
                t = val.time;
            }
        }
        time += t;
    }

    void write_data() {
        cout << time << "\n";
        for (const auto& entry : plan) {
            cout << entry << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solution sol;
    sol.read_data();
    sol.work();
    sol.write_data();
    return 0;
}
