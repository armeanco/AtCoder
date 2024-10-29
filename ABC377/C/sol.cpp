#include <iostream>
#include <utility>
#include <set>

void sol() {
        int N, M;
        std::cin >> N >> M;
        std::set<std::pair<int, int>> setik;
        int a, b;
        auto fill = [](int a, int b, int N, std::set<std::pair<int, int>> &setik) -> void {
                        setik.insert(std::make_pair(a, b));
                        setik.insert(a + 2 <= N && b + 1 <= N ? std::make_pair(a + 2, b + 1) : std::make_pair(0, 0));
                        setik.insert(a + 1 <= N && b + 2 <= N ? std::make_pair(a + 1, b + 2) : std::make_pair(0, 0));
                        setik.insert(a - 1 >= 1 && b + 2 <= N ? std::make_pair(a - 1, b + 2) : std::make_pair(0, 0));
                        setik.insert(a - 2 >= 1 && b + 1 <= N ? std::make_pair(a - 2, b + 1) : std::make_pair(0, 0));
                        setik.insert(a - 2 >= 1 && b - 1 >= 1 ? std::make_pair(a - 2, b - 1) : std::make_pair(0, 0));
                        setik.insert(a - 1 >= 1 && b - 2 >= 1 ? std::make_pair(a - 1, b - 2) : std::make_pair(0, 0));
                        setik.insert(a + 1 <= N && b - 2 >= 1 ? std::make_pair(a + 1, b - 2) : std::make_pair(0, 0));
                        setik.insert(a + 2 <= N && b - 1 >= 1 ? std::make_pair(a + 2, b - 1) : std::make_pair(0, 0));
        };
        for(int i = 0; i < M; ++i) {
                std::cin >> a >> b;
                fill(a, b, N, setik);
        }
        std::cout << setik.begin()->first == 0 ? static_cast<long>(N) * N - (setik.size() - 1) : static_cast<long>(N) * N - static_cast<int>(setik.size()) << "\n";
}

int main() {
        sol();
        return EXIT_SUCCESS;
}
