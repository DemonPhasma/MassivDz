#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "RU");
    const int SIZE = 10;
    int arr[SIZE];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 100 + 1;
    }

    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int minElement = arr[0];
    int maxElement = arr[0];

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    std::cout << "Минимальный элемент: " << minElement << std::endl;
    std::cout << "Максимальный элемент: " << maxElement << std::endl;

    return 0;
}


//--------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime> 

int main() {
    setlocale(LC_ALL, "RU");
    int size;
    int minRange, maxRange;
    int threshold;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::cout << "Введите минимальное значение диапазона: ";
    std::cin >> minRange;

    std::cout << "Введите максимальное значение диапазона: ";
    std::cin >> maxRange;

    std::cout << "Введите пороговое значение: ";
    std::cin >> threshold;

    if (minRange >= maxRange) {
        std::cerr << "Ошибка: минимальное значение должно быть меньше максимального." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % (maxRange - minRange + 1) + minRange;
    }

    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < threshold) {
            sum += arr[i];
        }
    }

    std::cout << "Сумма элементов, меньших " << threshold << ": " << sum << std::endl;

    delete[] arr;

    return 0;
}


//--------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "RU");
    const int MONTHS = 12;
    double profits[MONTHS];

    std::cout << "Введите прибыль фирмы за 12 месяцев:\n";
    for (int i = 0; i < MONTHS; ++i) {
        std::cout << "Месяц " << (i + 1) << ": ";
        std::cin >> profits[i];
    }

    int startMonth, endMonth;

    std::cout << "Введите диапазон месяцев (например, 3 и 6): ";
    std::cin >> startMonth >> endMonth;

    if (startMonth < 1 || endMonth > MONTHS || startMonth > endMonth) {
        std::cerr << "Ошибка: Неверный диапазон месяцев." << std::endl;
        return 1;
    }

    double maxProfit = std::numeric_limits<double>::lowest();
    double minProfit = std::numeric_limits<double>::max();
    int maxMonth = startMonth - 1;
    int minMonth = startMonth - 1;

    for (int i = startMonth - 1; i < endMonth; ++i) {
        if (profits[i] > maxProfit) {
            maxProfit = profits[i];
            maxMonth = i;
        }
        if (profits[i] < minProfit) {
            minProfit = profits[i];
            minMonth = i;
        }
    }

    std::cout << "Максимальная прибыль в месяце " << (maxMonth + 1)
        << " с прибылью " << maxProfit << std::endl;
    std::cout << "Минимальная прибыль в месяце " << (minMonth + 1)
        << " с прибылью " << minProfit << std::endl;

    return 0;
}

