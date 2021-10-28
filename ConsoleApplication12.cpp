#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cassert>
#include "blackjack.h"


void obzac()
{
    std::cout << "\n\n//============================================================================//\n\n";
}

//task1
class ArrayInt {
private:
	int* data;
	int length;
public:
	ArrayInt() : length(0), data(nullptr) {};

	ArrayInt(int inLength) : length(inLength) {
		assert(length >= 0);
		if (length > 0)
		{
			data = new int[length];
		}
		else
			data = nullptr;
	}

	void erase() {
		if (length > 0)
		{
			delete[] data;
			data = nullptr;
			length = 0;
		}
	}

	int getLength() const {
		return length;
	}

	int& operator[](int index) {
		return data[index];
	}

	void deleteLast() {

		assert(length != 0);

		if (length == 1)
		{
			erase();
		}
		else
		{
			int* new_data = new int[length - 1];

			for (int i = 0; i < length - 1; i++) {
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
			length--;
		}
	}

	void deleteFirst() {
		assert(length != 0);

		if (length == 1)
		{
			erase();
		}
		else
		{
			int* new_data = new int[length - 1];

			for (int i = 0; i < length - 1; i++) {
				new_data[i] = data[i + 1];
			}

			delete[] data;
			data = new_data;
			length--;
		}
	}

	void sort() {
		assert(length != 0);

		int tempIndex = 0;
		int lastIndex = length - 1;
		int temp;

		while (lastIndex > 0)
		{
			if (data[tempIndex] > data[tempIndex + 1])
			{
				temp = data[tempIndex];
				data[tempIndex] = data[tempIndex + 1];
				data[tempIndex + 1] = temp;
			}

			if (tempIndex == lastIndex - 1)
			{
				tempIndex = 0;
				lastIndex--;
			}
			else
			{
				tempIndex++;
			}
		}
	}

	void print() const {
		assert(length != 0);

		for (int i = 0; i < length; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "length: " << length << std::endl;
	}

	~ArrayInt() {
		delete[] data;
	}
};

//task 2
void printVector(std::vector<int>& input)
{
    std::cout << "\n";
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
        std::cout << *it << " ";
}
int countUniqueNumbers(std::vector<int> input)
{
    std::sort(input.begin(), input.end());
    std::vector<int>::iterator it;
    it = std::unique(input.begin(), input.end());
    input.resize(std::distance(input.begin(), it));
    return input.size();
}

int main()
{
	{
		obzac();
		ArrayInt array(8);
		array[0] = 1;
		array[1] = 2;
		array[2] = 3;
		array[3] = 4;
		array[4] = 5;
		array[5] = 6;
		array[6] = 7;
		array[7] = 8;
		array.deleteFirst();
		array.deleteLast();
		array.print();
		obzac();
	}

    {
		obzac();
        //task 2
        std::vector<int> array = { 1488, 88, 88, 228, 228, 12345, 553535, 2278 };
        std::cout << "\nInitial array: ";
        printVector(array);
        int count = countUniqueNumbers(array);
        std::cout << "\nUnique numbers: " << count;
		obzac();
    }

    {
		obzac();
        //task3
        Card aceClubs(ACE, CLUBS);
        Card aceHearts(ACE, HEARTS);
        Card kingClubs(KING, CLUBS);

        Hand playerHand;
        playerHand.Add(&aceClubs);
        playerHand.Add(&aceHearts);
        playerHand.Add(&kingClubs);

        int sum = playerHand.GetValue();
        std::cout << "\n\nPlayer's hand value is: " << sum;
        playerHand.Clear();
        sum = playerHand.GetValue();
        std::cout << "\nHand cleared! New value is: " << sum;
		obzac();
    }

}