#include <iostream>
#include <set>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>
#include <unordered_set>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

int main() {
    const int size = 500;

    // Red-Black Tree
    std::map<int, int> red_black_tree;

    // Filling Red-Black Tree with random unique numbers
    for (int i = 0; i < size; ++i) {
        int num = random_int(1, 1000);
        red_black_tree[num] = i;
    }

    // Unordered Set
    std::unordered_set<int> unordered_set_container;

    // Filling Unordered Set with random unique numbers
    for (int i = 0; i < size; ++i) {
        int num = random_int(1, 1000);
        unordered_set_container.insert(num);
    }

    // Timing search operation in Red-Black Tree
    auto start_search_red_black_tree = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        red_black_tree.find(random_int(1, 1000));
    }
    auto end_search_red_black_tree = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_search_red_black_tree = end_search_red_black_tree - start_search_red_black_tree;

    // Timing search operation in Unordered Set
    auto start_search_unordered_set = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        unordered_set_container.find(random_int(1, 1000));
    }
    auto end_search_unordered_set = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_search_unordered_set = end_search_unordered_set - start_search_unordered_set;

    // Timing insertion operation in Red-Black Tree
    auto start_insert_red_black_tree = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        red_black_tree[random_int(1001, 2000)] = i;
    }
    auto end_insert_red_black_tree = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_insert_red_black_tree = end_insert_red_black_tree - start_insert_red_black_tree;

    // Timing insertion operation in Unordered Set
    auto start_insert_unordered_set = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        unordered_set_container.insert(random_int(1001, 2000));
    }
    auto end_insert_unordered_set = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_insert_unordered_set = end_insert_unordered_set - start_insert_unordered_set;

    // Outputting results
    std::cout << "Time taken for searching in Red-Black Tree: " << duration_search_red_black_tree.count() << " seconds." << std::endl;
    std::cout << "Time taken for searching in Unordered Set: " << duration_search_unordered_set.count() << " seconds." << std::endl;
    std::cout << "Time taken for inserting a new element in Red-Black Tree: " << duration_insert_red_black_tree.count() << " seconds." << std::endl;
    std::cout << "Time taken for inserting a new element in Unordered Set: " << duration_insert_unordered_set.count() << " seconds." << std::endl;

    return 0;
}
