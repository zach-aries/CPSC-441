#include <iostream>
#include <random>
#include <iomanip>

#include "binary_tree.h"
#include "tree_processor.h"

#define N 1024
#define TEST_NUMBER 100

using namespace std;

int tree_processor::probe_count = 0;
int tree_processor::successful_count = 0;
int tree_processor::idle_count = 0;
int tree_processor::collision_count = 0;

int main() {

    int depth = 0;
    // simple table printing
    cout << endl;
    cout << setw(7) << left << "depth";
    cout << setw(6) << left << "k";
    cout << setw(10) << left << "succ %";
    cout << setw(10) << left << "idle %";
    cout << setw(10) << left << "colission %";
    cout << endl << "--------------------------------------------" << endl;
    while (depth <= 10) {


        int exp = 0;
        double k = pow(2,exp);

        while (k <= N) {
            int probe_total = 0;
            int success_total = 0;
            int idle_total = 0;
            int collision_total = 0;

            for (int i = 0; i < TEST_NUMBER; i++) {
                std::vector<std::pair<int,bool> > stations;
                for (int i = 0; i < N; i++) {
                    if (k < N)
                        stations.emplace_back(std::make_pair(i,false));
                    else
                        stations.emplace_back(std::make_pair(i,true));
                }


                if( k < N ){
                    int count = 0;
                    const unsigned int seed = time(0);

                    // Generating random numbers with C++11's random requires an engine and a distribution.
                    // This is an engine based on the Mersenne Twister 19937 (64 bits):
                    std::mt19937_64 rng(seed);
                    // Now we create another uniform distribution for integers in the [0, N) range:
                    uniform_int_distribution<int> unii(0, N - 1);
                    while (count < k) {
                        // generate random number from distribution
                        int randint = unii(rng);

                        if (!stations[randint].second){
                            stations[randint].second = true;
                            count ++;
                        }
                    }
                }

                binary_tree btree(stations);
                tree_processor::process_tree(btree, depth, btree.root);

                probe_total += tree_processor::probe_count;
                success_total += tree_processor::successful_count;
                idle_total += tree_processor::idle_count;
                collision_total += tree_processor::collision_count;

                tree_processor::probe_count = 0;
                tree_processor::successful_count = 0;
                tree_processor::idle_count = 0;
                tree_processor::collision_count = 0;
            }

            int probe_avg = probe_total / TEST_NUMBER;
            int success_avg = success_total / TEST_NUMBER;
            int idle_avg = idle_total / TEST_NUMBER;
            int collision_avg = collision_total / TEST_NUMBER;



            cout << setw(7) << left << depth;
            cout << setw(6) << left << k;
            cout << setw(10) << left << (float)success_avg / (float)probe_avg;
            cout << setw(10) << left << (float)idle_avg / (float)probe_avg;
            cout << setw(10) << left << (float)collision_avg / (float)probe_avg;
            cout << endl;

            exp ++;
            k = pow(2, exp);
        }

        depth +=2;
    }

    return 0;
}