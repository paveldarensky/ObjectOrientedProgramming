#include <iostream>
#include <map>
#include <fstream>
#include <ctime>

class SBase
{
public:
	virtual int Get() = 0;
};

class SKbrd : public SBase
{
public:
	int Get()
	{
		int num;
		std::cout << "Введите число: ";
		std::cin >> num;
		return num;
	};
};

class SFile : public SBase
{
	std::ifstream file;
public:
	SFile(const std::string& fileName)
	{
		file.open(fileName);
	}

	~SFile()
	{
		file.close();
	}

	int Get()
	{
		int num;

		if (file >> num)
		{
			return num;
		}
		else
		{
			return -1;
		}
	};

};

class SQueue : public SBase
{
	int* que, length, current;
public:
	SQueue(int leng)
	{
		current = -1;
		que = new int[length = (leng + 1)];
		srand(time(0));
		for (int i = 0; i < (length - 1); i++)
		{
			que[i] = 2 + rand() % (10 - 2 + 1);
		}
		que[length - 1] = -1;
	};

	~SQueue()
	{
		delete[] que;
	}

	int Get()
	{
		current++;
		return que[current];
	};
};

class Freq
{
	std::map<int, int> counts;
	int sum;
public:
	void Calc(SBase* pobj)
	{
		int num;
		while ((num = pobj->Get()) >= 0)
		{
			counts[num]++;
			sum += num;
		}
	};

	friend std::ostream& operator<<(std::ostream& stream, Freq& obj)
	{
		for (const auto& pair : obj.counts) {
			stream << "Число: " << pair.first << ", количество: " << pair.second << std::endl;
		}
		stream << "Сумма всех чисел: " << obj.sum << "\n";
		return stream;
	};
};

class Diap : public Freq
{
	int min, max, count;
public:
	Diap()
	{
		min = 0; max = 0; count = -1;
	};

	void Calc(SBase* pobj)
	{
		int num;
		if (count == -1)
		{
			num = pobj->Get();
			min = max = num;
			count = 1;
		}
		//min = std::min(min, num);
		//max = std::max(max, num);
		//count++;
		while ((num = pobj->Get()) >= 0)
		{
			min = std::min(min, num);
			max = std::max(max, num);
			count++;
		}
	};

	friend std::ostream& operator<<(std::ostream& stream, Diap& obj)
	{
		stream << "Минимальное число: " << obj.min << "\n";
		stream << "Максимальное число: " << obj.max << "\n";
		stream << "Количество всех чисел: " << obj.count << "\n";
		return stream;
	};
};

void main()
{
	setlocale(LC_ALL, "rus");

	SKbrd keyboardTEST_freq;
	SFile fileTEST_freq("test_freq.txt");
	SQueue queueTEST_freq(5);

	Freq freqObj;
	freqObj.Calc(&keyboardTEST_freq);
	freqObj.Calc(&fileTEST_freq);
	freqObj.Calc(&queueTEST_freq);
	std::cout << "Результат Freq:\n" << freqObj << "\n";

	SKbrd keyboardTEST_diap;
	SFile fileTEST_diap("test_diap.txt");
	SQueue queueTEST_diap(5);

	Diap diapObj;
	diapObj.Calc(&keyboardTEST_diap);
	diapObj.Calc(&fileTEST_diap);
	diapObj.Calc(&queueTEST_diap);
	std::cout << "Результат Diap:\n" << diapObj << "\n";
}